# PFND3DDDI_EXTENSIONEXECUTE callback function

## Description

The **ExtensionExecute** function performs an operation by using the given DirectX Video Accelerator (DXVA) extension device.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [**D3DDDIARG_EXTENSIONEXECUTE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_extensionexecute) structure that describes the DXVA operation to perform.

## Return value

**ExtensionExecute** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The DXVA operation is successfully performed.|
|E_OUTOFMEMORY|ExtensionExecute could not allocate the required memory for it to complete.|

## Remarks

For more information, see [Extended Support for DirectX VA 2.0](https://learn.microsoft.com/windows-hardware/drivers/display/extended-support-for-directx-va-2-0).

## See also

[**CreateExtensionDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createextensiondevice)

[**D3DDDIARG_EXTENSIONEXECUTE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_extensionexecute)

[**D3DDDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)