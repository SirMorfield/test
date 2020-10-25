        if (prev_disance == -1)
            prev_disance = input.checkpoint_dist;
        else {
            if (input.checkpoint_dist > prev_disance + 200) {
                if (max_distance_to_pass_checkpoint < prev_disance)
                    max_distance_to_pass_checkpoint = prev_disance;
            }
            prev_disance = input.checkpoint_dist;
        }
        fprintf(stderr, "%d %d %d\n", input.checkpoint_dist, abs(input.checkpoint_angle), max_distance_to_pass_checkpoint);