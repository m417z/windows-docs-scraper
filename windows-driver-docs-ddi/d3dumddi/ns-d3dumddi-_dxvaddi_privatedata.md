# DXVADDI_PRIVATEDATA structure

## Description

The **DXVADDI_PRIVATEDATA** structure encapsulates private data for a DirectX Video Acceleration (DXVA) extension device.

## Members

### `pData` [in]

A pointer to a buffer that contains private, driver-defined data for the extension device.

### `DataSize` [in]

The size, in bytes, of the buffer that is pointed to by **pData**.

## Remarks

For more information, see [Extended Support for DirectX VA 2.0](https://learn.microsoft.com/windows-hardware/drivers/display/extended-support-for-directx-va-2-0).

## See also

[**CreateExtensionDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createextensiondevice)

[**D3DDDIARG_CREATEEXTENSIONDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createextensiondevice)

[**DecodeExtensionExecute**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodeextensionexecute)

[**D3DDDIARG_DECODEEXTENSIONEXECUTE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decodeextensionexecute)

[**ExtensionExecute**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_extensionexecute)

[**D3DDDIARG_EXTENSIONEXECUTE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_extensionexecute)