const fs = require('fs')

const files = fs.readdirSync('.')
for (const file of files) {
	if (file[file.length - 1] == '4') {
		let newf = file.split('')
		delete newf[6]
		newf = newf.join('')
		// let newf = `S0${file[0]}E${file[1]}${file[2]}${file.substring(3, file.length)}`
		fs.renameSync(file, newf)
		console.log(file, newf)
	}
}