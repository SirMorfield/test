#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#define POD_THRUST_MAX 100
#define POD_THRUST_MIN 0
#define POD_FORCEFIELD_RADIUS 400
#define POD_COLISSION_DISTANCE 946
#define CHECKPOINT_RADIUS 600

typedef struct	s_input
{
	int pod_x;
    int pod_y;
    int checkpoint_x;
    int checkpoint_y;
    int checkpoint_dist;
    int checkpoint_angle;
    int opponent_x;
    int opponent_y;
}				t_input;

typedef struct	s_pod
{
	int		target_x;
	int		target_y;
	int		thrust;
	char	*special;
}				t_pod;

int distance(int x1, int y1, int x2, int y2)
{
    int square_difference_x = (x2 - x1) * (x2 - x1);
    int square_difference_y = (y2 - y1) * (y2 - y1);
    int distance = sqrt(square_difference_x + square_difference_y);
    return (distance);
}

int map(int x, int in_min, int in_max, int out_min, int out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void	set_input(t_input *input)
{
	scanf("%d%d%d%d%d%d", &input->pod_x, &input->pod_y, &input->checkpoint_x, &input->checkpoint_y, &input->checkpoint_dist, &input->checkpoint_angle);
	scanf("%d%d", &input->opponent_x, &input->opponent_y);
}

void	clean_pod(t_pod *pod)
{
	if (pod->special != NULL)
		free(pod->special);
	pod->special = NULL;
	pod->thrust = 0;
}

int		apply_bounds(int x, int min, int max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

void	get_target(int *target_x, int *target_y, t_input *input)
{
	*target_x = input->checkpoint_x;
	*target_y = input->checkpoint_y;
}

int     start_breaking_at = 1200;
void	get_thrust(int *thrust, t_input *input)
{
	if (input->checkpoint_angle > 90 || input->checkpoint_angle < -90) {
		*thrust = 0;
        return ;
    }
    if (input->checkpoint_dist > start_breaking_at)
        return ;
    int allowed_angle = map(input->checkpoint_dist, CHECKPOINT_RADIUS - 1, start_breaking_at, 2, 50);
	if	(input->checkpoint_angle > -allowed_angle &&
		input->checkpoint_angle < allowed_angle) {
		
		*thrust = map(_checkpoint_angle)
	}
    else
        *thrust = 100;
	*thrust = apply_bounds(*thrust, POD_THRUST_MIN, POD_THRUST_MAX);
}

bool	used_boost = false;
float	allowed_boost_angle = 2;
int		min_boost_distance = 12000;
void	do_boost(char *special, t_input *input)
{
	if (special != NULL)
		return ;
	if (!used_boost &&
		input->checkpoint_angle >= (int)-allowed_boost_angle &&
		input->checkpoint_angle <= (int)allowed_boost_angle &&
		input->checkpoint_dist >= min_boost_distance) {
		special = strdup("BOOST");
		used_boost = true;
	} else {
		min_boost_distance -= 100;
		allowed_boost_angle += 0.5;
	}
}

int     shield_usages = 100;
int     min_distance = 9999999;
void	do_shield(char *special, t_input *input)
{
	if (special != NULL)
		return ;
    if (shield_usages > 3)
        return ;
	int distance_to_opponent = distance(input->pod_x, input->pod_y, input->opponent_x, input->opponent_y);
    if (distance_to_opponent < min_distance)
        min_distance = distance_to_opponent;
	if (distance_to_opponent <= POD_COLISSION_DISTANCE + 2) {
		special = strdup("SHIELD");
        shield_usages++;
    }
}


int		main(void)
{
	t_input input;
	t_pod pod;

    while (true) {
		set_input(&input);
		clean_pod(&pod);

		get_target(&pod.target_x, &pod.target_y, &input);

		get_thrust(&pod.thrust, &input);

		do_boost(pod.special, &input);
		do_shield(pod.special, &input);

		if (pod.special == NULL)
			printf("%d %d %d\n", pod.target_x, pod.target_y, pod.thrust);
		else
			printf("%d %d %s\n", pod.target_x, pod.target_y, pod.special);
    }
    return (0);
}