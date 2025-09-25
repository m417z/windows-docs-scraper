## Description

The **MmGetPhysicalMemoryRangesEx2** routine returns the virtual address of a nonpaged pool block which contains the physical memory ranges in the system.

## Parameters

### `PartitionObject`

Optional pointer to the partition object to query.

### `Flags`

Whether the caller is interested in FileOnly ranges, and whether to include all partitions.

## Return value

NULL on failure.

## Remarks

The returned block contains physical address and page count pairs. The last entry contains zero for both.

The caller must understand that although the returned block cannot change after it is returned, the actual memory configuration can change (due to hot-add/remove) at any time.

It is the caller's responsibility to free this block.

## See also