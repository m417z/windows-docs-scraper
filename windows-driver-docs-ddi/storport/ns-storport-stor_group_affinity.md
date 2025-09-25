## Description

The **STOR_GROUP_AFFINITY** structure specifies a group number and the processor affinity within that group.

## Members

### `Mask`

A **STOR_AFFINITY** value that specifies the affinity mask. The bits in the affinity mask identify a set of processors within the group identified by **Group**.

### `Group`

Specifies the group number.

### `Reserved`

Reserved for future use. Set all three **Reserved** array elements to zero.

## Remarks

A **STOR_GROUP_AFFINITY** structure describes a thread affinity, which is a set of processors on which a thread is allowed to run. **Mask** contains an affinity mask that identifies the processors in the set. All of the processors in this set belong to the group that is identified by the **Group** member of the structure.

The [**StorPortSetSystemGroupAffinityThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetsystemgroupaffinitythread) and [**StorPortRevertToUserGroupAffinityThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreverttousergroupaffinitythread) routines use **STOR_GROUP_AFFINITY** structures to specify thread affinities.

## See also

[**StorPortRevertToUserGroupAffinityThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreverttousergroupaffinitythread)

[**StorPortSetSystemGroupAffinityThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetsystemgroupaffinitythread)