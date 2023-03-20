# SchedulingAlgorithms
A symulation of different scheduling algorithms in operating system. Approximation of how efficiently access to CPU is managed by the following:
- FCFS - first come first served
- SJFnp - shortest job first, non-preemptive
- SJFp - shortest job first, preemptive
- RR - round robin

The mockup is of course very basic and does not consider wait time for switching between contexts or deleting processes, etc. This simulation only considers a single-threaded processing unit, and so, is a gross simplification of any real system.
The simulation allows the user to set a small set of process lengths to generate along with corresponding arrival times. By filling those two tables by corresponding data, you get your custom test case for result verification purposes.
Of course, the more reliable option is to run a simulation in random spawn mode, where user has no control over exact processes spawned, and can only influence ratios or duration ranges, as well as specify the number of spawned processes.
The program is optimized to minimaze the usage of loops and iteration through collections. It just might not-burn your computer...
Created for my Operating Systems university course

