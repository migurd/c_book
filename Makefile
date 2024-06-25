all:
	@gcc ${file}.c -o bin/${file}
	@./bin/${file}
