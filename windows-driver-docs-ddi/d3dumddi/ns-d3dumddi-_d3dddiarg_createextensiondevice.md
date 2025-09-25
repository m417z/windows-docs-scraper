# D3DDDIARG_CREATEEXTENSIONDEVICE structure

## Description

The **D3DDDIARG_CREATEEXTENSIONDEVICE** structure describes a DirectX Video Acceleration (DirectX VA) extension device to create.

## Members

### `pGuid` [in]

A pointer to the GUID that represents the DirectX VA extension type. The Direct3D runtime calls the [**GetCaps**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function to query for the supported extension GUIDs.

### `pPrivate` [in]

A pointer to the [**DXVADDI_PRIVATEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_privatedata) structure that contains data needed by the driver to create the extension device.

### `hExtension` [out]

A handle to the extension device. The user-mode driver creates this handle. The Direct3D runtime uses it to identify the extension device in subsequent calls.

## Remarks

For more information, see [Creating and Using a DirectX VA 2.0 Extension Device](https://learn.microsoft.com/windows-hardware/drivers/display/creating-and-using-a-directx-va-2-0-extension-device).

## See also

[**CreateExtensionDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createextensiondevice)

[**DXVADDI_PRIVATEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_privatedata)

[**GetCaps**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)