# PAGP_RESERVE_VIRTUAL callback function

## Description

The **AgpReserveVirtual** function reserves a range of virtual addresses for AGP.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `ProcessHandle` [in]

Handle of the process in which to reserve the virtual address range. If **ProcessHandle** is 0, then the virtual address range is allocated in system space.

### `PhysicalReserveContext` [in]

Is the context handle that identifies the reserved physical address range with which to associate the virtual memory reservation. This context was obtained from [AgpReservePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_physical).

### `VirtualReserveContext` [out]

Is the location in which the video port driver writes a context handle that identifies the reserved virtual memory.

## Return value

**AgpReserveVirtual** returns the base address of the reserved virtual address range if successful; otherwise, returns **NULL**.

## Remarks

If **ProcessHandle** is not 0, then **AgpReserveVirtual** reserves, but does not commit, a range of virtual addresses in the address space of a user-mode process. In that case, you must call [AgpCommitVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_virtual) to map the reserved (user-mode) virtual addresses to physical addresses.

If **ProcessHandle** is 0, then **AgpReserveVirtual** allocates a range of virtual addresses in system space and automatically maps (commits) the entire range of virtual addresses to physical addresses. Even though **AgpReserveVirtual** commits the entire virtual range, you still must call [AgpCommitVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_virtual) before any code accesses the virtual range.

When you call **AgpReserveVirtual** to allocate a range of virtual addresses in system space (that is, if you set **ProcessHandle** to 0), the entire range of physical addresses identified by **PhysicalReserveContext** must be committed to locked pages of physical memory by a previous call to [AgpCommitPhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_physical).

The miniport driver can call [AgpReleaseVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_release_virtual) several times to reserve many smaller address ranges rather than one big range.

The miniport driver should call [AgpReleaseVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_release_virtual) to release the reserved virtual address range when it is no longer needed.

## See also

[AgpCommitPhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_physical)

[AgpCommitVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_virtual)

[AgpReleaseVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_release_virtual)

[AgpReservePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_physical)