# _GROUP_AFFINITY structure (minitape.h)

## Description

The **GROUP_AFFINITY** structure specifies a group number and the processor [affinity](https://learn.microsoft.com/windows-hardware/drivers/) within that group.

## Members

### `Mask`

Specifies the affinity mask. This parameter is a [**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity) value. The bits in the affinity mask identify a set of processors within the group identified by **Group**.

### `Group`

Specifies the group number. In Windows 7, the group number must be in the range from 0 to 3.

### `Reserved`

Reserved for future use. Set all three **Reserved** array elements to zero.

## Syntax

```cpp
typedef struct _GROUP_AFFINITY {
  KAFFINITY Mask;
  WORD      Group;
  WORD      Reserved[3];
} GROUP_AFFINITY, *PGROUP_AFFINITY;
```

## Remarks

This structure describes a group-specific affinity.

A **GROUP_AFFINITY** structure can describe a thread affinity, which is a set of processors on which a thread is allowed to run. All of the processors in this set belong to the group that is identified by the **Group** member of the structure. The **Mask** member contains an affinity mask that identifies the processors in the set. For example, the [KeSetSystemGroupAffinityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetsystemgroupaffinitythread) and [KeRevertToUserGroupAffinityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereverttousergroupaffinitythread) routines use **GROUP_AFFINITY** structures to specify thread affinities.

A **GROUP_AFFINITY** structure can describe an interrupt affinity, which is a set of processors on which an interrupt service routine can receive interrupts. For example, the [IoGetDeviceNumaNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdevicenumanode) routine uses **GROUP_AFFINITY** structures to specify interrupt affinities.

## See also

[KeRevertToUserGroupAffinityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereverttousergroupaffinitythread)

[IoGetDeviceNumaNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdevicenumanode)

[KeSetSystemGroupAffinityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetsystemgroupaffinitythread)

[**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity)