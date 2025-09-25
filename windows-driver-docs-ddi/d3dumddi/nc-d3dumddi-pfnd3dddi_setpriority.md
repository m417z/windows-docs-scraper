# PFND3DDDI_SETPRIORITY callback function

## Description

The *SetPriority* function sets the eviction-from-memory priority for a managed texture.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_SETPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setpriority) structure that specifies the priority level to set for the managed texture.

## Return value

*SetPriority* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The priority level is successfully set.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

## Remarks

The Microsoft Direct3D runtime calls *SetPriority* to set the priority level for a resource. The user-mode display driver should translate the resource handle that is supplied in the **hResource** member of the [D3DDDIARG_SETPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setpriority) structure that is pointed to by *pData* to an allocation handle. After the driver makes this translation, the driver should pass the resulting handle in a call to the [pfnSetPriorityCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setprioritycb) function.

## See also

[D3DDDIARG_SETPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setpriority)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[pfnSetPriorityCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setprioritycb)