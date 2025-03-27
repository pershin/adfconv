all:
	mkdir -p build
	cc src/adfconv.c src/convert.c src/progress.c -o build/adfconv

clean:
	rm -rf build
