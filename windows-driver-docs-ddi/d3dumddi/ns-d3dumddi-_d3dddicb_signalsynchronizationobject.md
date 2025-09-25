# _D3DDDICB_SIGNALSYNCHRONIZATIONOBJECT structure

## Description

The D3DDDICB_SIGNALSYNCHRONIZATIONOBJECT structure describes the parameters that are required to set up signaling in a call to the [pfnSignalSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobjectcb) function.

## Members

### `hContext` [in]

A handle to a Direct3D context that signals the synchronization events in the array that the **ObjectHandleArray** member specifies.

### `ObjectCount` [in]

The number of synchronization events in the **ObjectHandleArray** array.

### `ObjectHandleArray` [in]

An array of handles to the synchronization events that the context that is specified by the **hContext** member signals. The **D3DDDI_MAX_OBJECT_SIGNALED** constant, which is defined as 32, indicates the maximum number of synchronization events that the context can signal.

### `Flags` [in]

A [D3DDDICB_SIGNALFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_signalflags) structure that indicates, in bit-field flags, signaling behavior.

## See also

[D3DDDICB_SIGNALFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_signalflags)

[pfnSignalSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobjectcb)