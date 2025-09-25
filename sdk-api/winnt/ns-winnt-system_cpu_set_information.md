# SYSTEM_CPU_SET_INFORMATION structure

## Description

This structure is returned by [GetSystemCpuSetInformation](https://learn.microsoft.com/windows/desktop/ProcThread/getsystemcpusetinformation). It is used to enumerate the CPU Sets on the system and determine their current state.

 This is a variable-sized structure designed for future expansion. When iterating over this structure, use the size field to determine the offset to the next structure.

## Members

### `Size`

This is the size, in bytes, of this information structure.

### `Type`

This is the type of information in the structure. Applications should skip any structures with unrecognized types.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.CpuSet`

### `DUMMYUNIONNAME.CpuSet.Id`

The ID of the specified CPU Set. This identifier can be used with [SetProcessDefaultCpuSets](https://learn.microsoft.com/windows/desktop/ProcThread/setprocessdefaultcpusets) or [SetThreadSelectedCpuSets](https://learn.microsoft.com/windows/desktop/ProcThread/setthreadselectedcpusets) when specifying a list of CPU Sets to affinitize to.

### `DUMMYUNIONNAME.CpuSet.Group`

Specifies the Processor Group of the CPU Set. All other values in the CpuSet structure are relative to the processor group.

### `DUMMYUNIONNAME.CpuSet.LogicalProcessorIndex`

Specifies the group-relative index of the home processor of the CPU Set. Unless the CPU Set is parked for thermal or power management reasons or assigned for exclusive use to another application, threads will run on the home processor of one of their CPU Sets. The **Group** and **LogicalProcessorIndex** fields are the same as the ones found in the PROCESSOR_NUMBER structure and they correspond to the **Group** field and **Mask** field of the GROUP_AFFINITY structure.

### `DUMMYUNIONNAME.CpuSet.CoreIndex`

A group-relative value indicating which "Core" has the home processor of the CPU Set. This number is the same for all CPU Sets in the same group that share significant execution resources with each other, such as different hardware threads on a single core that supports simultaneous multi-threading.

### `DUMMYUNIONNAME.CpuSet.LastLevelCacheIndex`

A group-relative value indicating which CPU Sets share at least one level of cache with each other. This value is the same for all CPU Sets in a group that are on processors that share cache with each other.

### `DUMMYUNIONNAME.CpuSet.NumaNodeIndex`

A group-relative value indicating which NUMA node a CPU Set is on. All CPU Sets in a given group that are on the same NUMA node will have the same value for this field.

### `DUMMYUNIONNAME.CpuSet.EfficiencyClass`

 A value indicating the intrinsic energy efficiency of a processor for systems that support heterogeneous processors (such as ARM big.LITTLE systems). CPU Sets with higher numerical values of this field have home processors that are faster but less power-efficient than ones with lower values.

### `DUMMYUNIONNAME.CpuSet.DUMMYUNIONNAME2`

### `DUMMYUNIONNAME.CpuSet.DUMMYUNIONNAME2.AllFlags`

### `DUMMYUNIONNAME.CpuSet.DUMMYUNIONNAME2.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.CpuSet.DUMMYUNIONNAME2.DUMMYSTRUCTNAME.Parked`

### `DUMMYUNIONNAME.CpuSet.DUMMYUNIONNAME2.DUMMYSTRUCTNAME.Allocated`

### `DUMMYUNIONNAME.CpuSet.DUMMYUNIONNAME2.DUMMYSTRUCTNAME.AllocatedToTargetProcess`

### `DUMMYUNIONNAME.CpuSet.DUMMYUNIONNAME2.DUMMYSTRUCTNAME.RealTime`

### `DUMMYUNIONNAME.CpuSet.DUMMYUNIONNAME2.DUMMYSTRUCTNAME.ReservedFlags`

### `DUMMYUNIONNAME.CpuSet.Reserved`

Reserved.

### `DUMMYUNIONNAME.CpuSet.SchedulingClass`

### `DUMMYUNIONNAME.CpuSet.AllocationTag`

Specifies a tag used by Core Allocation to communicate a given allocated CPU Set between threads in different components.

##### - CpuSet.Allocated : 1

If set, the specified CPU Set is not available for general system use, but instead is allocated for exclusive use of some processes. If a non-NULL **Process** argument is specified in a call to [GetSystemCpuSetInformation](https://learn.microsoft.com/windows/desktop/ProcThread/getsystemcpusetinformation), it is possible to determine if the processor is allocated for use with that process.

##### - CpuSet.AllocatedToTargetProcess : 1

This is set if the CPU Set is allocated for the exclusive use of some subset of the system processes and if it is allocated for the use of the process passed into [GetSystemCpuSetInformation](https://learn.microsoft.com/windows/desktop/ProcThread/getsystemcpusetinformation).

##### - CpuSet.Parked : 1

If set, the home processor of this CPU Set is parked. If the CPU Set is on a parked processor, threads assigned to that set may be reassigned to other processors that are selected by the **Process Default** sets or the **Thread Selected** sets. If all such processors are parked, the threads are reassigned to other available processors on the system.

##### - CpuSet.RealTime : 1

This is set of the CPU Set is on a processor that is suitable for low-latency realtime processing. The system takes steps to ensure that RealTime CPU Sets are unlikely to be running non-preemptible code, by moving other work like Interrupts and other application threads off of those processors.

##### - CpuSet.ReservedFlags : 4

Reserved.