# StorPortBuildScatterGatherList function

## Description

The **StorPortBuildScatterGatherList** routine creates a scatter/gather list for the specified data buffer.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Mdl` [in]

A pointer to a memory descriptor list (MDL) that describes the memory pages associated with the data buffer.

### `CurrentVa` [in]

The virtual address of the data buffer.

### `Length` [in]

The length, in bytes, of the data buffer.

### `ExecutionRoutine` [in]

A pointer to a miniport driver-supplied *ExecutionRoutine*. The Storport driver calls this routine after creating the scatter/gather list. The miniport driver should perform all operations that make use of the scatter/gather list inside the execution routine, not in the code that follows the call to the **StorPortBuildScatterGatherList** routine.

An *ExecutionRoutine* is declared as follows:

```
VOID
ExecutionRoutine (
    IN PVOID  *DeviceObject,
    IN PVOID  *Irp,
    IN PSTOR_SCATTER_GATHER_LIST  ScatterGather,
    IN PVOID  Context
    );
```

#### DeviceObject

Miniport drivers should ignore this parameter.

#### Irp

Miniport drivers should ignore this parameter.

#### ScatterGather

A pointer to a [STOR_SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_scatter_gather_list) structure that contains the scatter/gather list for the specified data buffer.

#### Context

The context value specified in the **StorPortBuildScatterGatherList** function's *Context* parameter.

The Storport driver calls a miniport driver's *ExecutionRoutine* at IRQL = DISPATCH_LEVEL.

### `Context` [in]

A context value that the port driver passes to the execution routine specified in the *ExecutionRoutine* parameter. The execution routine uses this value to uniquely identify the request.

### `WriteToDevice` [in]

A value that indicates the direction of the DMA transfer. A value of **TRUE** indicates a transfer that is from the data buffer to the device, and a value of **FALSE** indicates a transfer that is from the device to the data buffer.

### `ScatterGatherBuffer` [in, out]

A pointer to a miniport-supplied buffer that receives the scatter/gather list. A miniport driver can allocate memory for this buffer by calling the [StorPortAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocatepool) routine.

### `ScatterGatherBufferLength` [in]

The size, in bytes, of the buffer pointed to by the *ScatterGatherBuffer* parameter.

## Return value

**StorPortBuildScatterGatherList** returns one of the following values:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | Indicates that the routine created the scatter/gather list successfully.<br><br>**Important** See 'Remarks'. |
| **STOR_STATUS_INVALID_PARAMETER** | The *HwDeviceExtension* passed was **NULL**. |
| **STOR_STATUS_INVALID_IRQL** | The call was made at an invalid IRQL. |
| **STOR_STATUS_INSUFFICIENT_RESOURCES** | The system has insufficient map registers available for the transfer. |
| **STOR_STATUS_BUFFER_TOO_SMALL** | The Length parameter is too big to fit within the buffer. |

## Remarks

The miniport driver calls [StorPortPutScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportputscattergatherlist) to release the resources that **StorPortBuildScatterGatherList** allocated while constructing the scatter/gather list.

The miniport driver must call [StorPortPutScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportputscattergatherlist) before freeing or reusing the memory it allocated for the scatter/gather list.

**Note** If **StorPortBuildScatterGatherList** returns STOR_STATUS_SUCCESS, then the callback in *ExecutionRoutine* was successfully queued to execute after the scatter/gather list is created. The miniport must not assume that *ExecutionRoutine* was called or that the scatter/gather list is ready when **StorPortBuildScatterGatherList** returns. If necessary, the miniport can synchronize the execution of code following **StorPortBuildScatterGatherList** with the callback in *ExecutionRoutine* to ensure that the scatter/gather list is available.

## See also

[STOR_SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_scatter_gather_list)

[StorPortAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocatepool)

[StorPortPutScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportputscattergatherlist)