# _D3DDDICB_DESTROYALLOCATION2FLAGS structure

## Description

The **D3DDDICB_DESTROYALLOCATION2FLAGS** structure is used with the [D3DKMT_DESTROYALLOCATION2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroyallocation2) structure to describe parameters for releasing allocations with [D3DKMTDestroyAllocation2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtdestroyallocation2).

## Members

### `AssumeNotInUse`

|Value|Meaning|
|--- |--- |
|FALSE|Instructs the video memory manager to assume that commands queued prior to the destruction request may attempt to access the allocation being destroyed and defers the destruction operation until the queued commands finish.|
|TRUE|Instructs the video memory manager to ignore pending commands on the owner device and destroy the allocations immediately.|

### `SynchronousDestroy`

|Value|Meaning|
|--- |--- |
|FALSE|Instructs the DirectX graphics kernel that the call may return prior to the underlying surface memory being fully reclaimed by the operating system.|
|TRUE|Instructs the DirectX graphics kernel to wait until surface memory is reclaimed by the operating system.|

### `Reserved`

This member is reserved and should be set to zero.

### `SystemUseOnly`

This member is reserved and should not be used by the user mode driver.

### `Value`

The consolidated value of the fields in the structure.

## See also

[D3DKMTDestroyAllocation2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtdestroyallocation2)

[D3DKMT_DESTROYALLOCATION2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroyallocation2)