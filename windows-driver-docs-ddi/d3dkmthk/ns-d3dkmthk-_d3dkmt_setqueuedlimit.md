# _D3DKMT_SETQUEUEDLIMIT structure

## Description

The D3DKMT_SETQUEUEDLIMIT structure describes parameters for setting or retrieving the limit for the number of operations of the given type that can be queued for the given device.

## Members

### `hDevice` [in]

A D3DKMT_HANDLE data type that represents the kernel-mode handle to the device to set or retrieve the limit of queued operations for.

### `Type` [in]

A [D3DKMT_QUEUEDLIMIT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_queuedlimit_type)-typed value that indicates the type of operations to set or retrieve the queued limit for.

### `QueuedPresentLimit` [in/out]

The limit for the number of present operations that can be queued for the device that is specified by **hDevice**. If the OpenGL installable client driver (ICD) sets **QueuedPresentLimit** to 0, the limit for the device is reset to the graphics adapter's default value, which is currently 3. The union that is contained in D3DKMT_SETQUEUEDLIMIT contains the limiting number if the **Type** member is D3DKMT_SET_QUEUEDLIMIT_PRESENT and retrieves the number if **Type** is D3DKMT_GET_QUEUEDLIMIT_PRESENT.

### `VidPnSourceId` [in]

An integer that identifies a video present source that is in the path of a video present network (VidPN) topology. The union that is contained in D3DKMT_SETQUEUEDLIMIT contains the integer if the present operations are flips.

### `QueuedPendingFlipLimit` [in/out]

The limit for the number of flip operations that can be queued for the device that is specified by **hDevice**. If the OpenGL ICD sets **QueuedPendingFlipLimit** to 0, the limit for the device is reset to the graphics adapter's default value, which is currently 1. The union that is contained in D3DKMT_SETQUEUEDLIMIT contains the limiting number if the present operations are flips.

## See also

[D3DKMTSetQueuedLimit](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsetqueuedlimit)

[D3DKMT_QUEUEDLIMIT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_queuedlimit_type)