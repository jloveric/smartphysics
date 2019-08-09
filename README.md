# SmartPhysics
(Work in progress) -- This is the very beginning of work towards a "Smart Physics" simulation tool.  Physical models/simulations are used to train machine learning algorithms which can then be used to speed up the simulations or perform at higher resolution.

# Build in Docker

You need docker installed on your system.  Run the following in the main directory

```bash
docker build -t smartphysics .
```
run the image and use its console

```bash
docker run -it smartphysics bash
```
run the tests
```
make test
```
run the main.cc
```
./smartphysics
```
