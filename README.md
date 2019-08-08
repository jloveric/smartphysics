# SmartPhysics
(Work in progress) -- This is the very beginning of work towards a "Smart Physics" simulation tool.  Physical models/simulations are used to train machine learning algorithms which can then be used to perform simulations faster, or act as subgrid scale models for those simulations so that they can be performed faster and at higher equivalent resolution.

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

