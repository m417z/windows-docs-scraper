# _DXGK_VIRTUALGPUSEGMENTINFO structure

## Description

Information about the virtual GPU segment info.

## Members

### `DriverSegmentId`

The driver Id of the physical memory segment, which was enumerated by Dxgkrnl. The value starts from 1.

### `Size`

Size in this memory segment, which is needed in the vGPU.

### `Alignment`

Allocation alignment in the memory segment in bytes. This value must be a multiple of 4096 bytes or zero.

### `MinSegmentOffset`

Optionally, the driver can specify a range in the segment where this allocation must be located. If there is no range restriction, set these values to zero. This could be used, for example, when a portion of the VPR range needs to be assigned to a vGPU.

> [!NOTE]
> This functionality is deprecated.

### `MaxSegmentOffset`

Optionally, the driver can specify a range in the segment where this allocation must be located. If there is no range restriction, set these values to zero. This could be used, for example, when a portion of the VPR range needs to be assigned to a vGPU.

> [!NOTE]
> This functionality is deprecated.

### `PrivateDriverData`

Allocation driver private data.

## Remarks

## See also