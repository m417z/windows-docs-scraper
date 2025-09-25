# PFND3DDDI_DESTROYSYNCHRONIZATIONOBJECTCB callback function

## Description

The **pfnDestroySynchronizationObjectCb** function destroys the synchronization object that was created through a call to the [pfnCreateSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createsynchronizationobjectcb) function.

## Parameters

### `hDevice`

A handle to a display device (that is, the graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDICB_DESTROYSYNCHRONIZATIONOBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_destroysynchronizationobject) structure that contains a handle to the synchronization object to destroy.

## Return value

**pfnDestroySynchronizationObjectCb** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The synchronization object was successfully destroyed.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

This function might also return other HRESULT values.

## See also

[D3DDDICB_DESTROYSYNCHRONIZATIONOBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_destroysynchronizationobject)

[pfnCreateSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createsynchronizationobjectcb)