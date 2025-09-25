# PFND3DDDI_WAITFORSYNCHRONIZATIONOBJECTCB callback function

## Description

The **pfnWaitForSynchronizationObjectCb** function inserts a wait for the specified synchronization objects in the specified context DMA stream.

## Parameters

### `hDevice`

A handle to a display device (that is, the graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDICB_WAITFORSYNCHRONIZATIONOBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_waitforsynchronizationobject) structure that describes the synchronization objects and context DMA stream that are required to set up the wait.

## Return value

**pfnWaitForSynchronizationObjectCb** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The wait was successfully set up. |
| **E_INVALIDARG** | Parameters were validated and determined to be incorrect. |

This function might also return other HRESULT values.

## Remarks

**Direct3D Version 11 Note:** For more information about how the driver calls **pfnWaitForSynchronizationObjectCb**, see [Changes from Direct3D 10](https://learn.microsoft.com/windows-hardware/drivers/display/changes-from-direct3d-10).

For a code example of how to use the **pfnWaitForSynchronizationObjectCb** function, see [pfnSignalSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobjectcb).

## See also

[D3DDDICB_WAITFORSYNCHRONIZATIONOBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_waitforsynchronizationobject)