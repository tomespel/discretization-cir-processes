# Progress 
 
## Meeting: 27.02.18 
We must be able to: 
- Generate Y [Implemented and tested, Mehdi, 01.03.2018] 
- Compute the threshold [Implemented, Mehdi, 01.03.2018] 
- Implement formula (16) for values between 0 and K [Started, not finished, Mehdi 01.03.2018] [Finished, Kees 04.03.2018]
- Use the code given by `cir2` 
 
We should **focus on these tasks** due next meeting. Our aim is to finish implementing the scheme (recall we are working on the the second order version of the scheme). 
It should be interesting to do some research on the _Heston model_. 
 
Recall that using Normal would generate negative variables. 
 
## Notes, Mehdi, 01.03.2018 
 
**There are two many functions with parameters which makes debugging difficult 
we should try to refactor this into classes to reduce the risk of mistakes 
and identify errors more easily** 

## Notes, Kees, 04.03.2018

Second order scheme totally implemented. 
Notice changes in functions cir2 and plot_paths_cir2 which now gives the option of intruding an output file name.
When plotting case B (parameters given by page 24) notice that the scheme likes to stay near zero. 
