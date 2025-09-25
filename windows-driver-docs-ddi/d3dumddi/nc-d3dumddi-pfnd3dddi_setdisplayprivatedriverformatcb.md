# PFND3DDDI_SETDISPLAYPRIVATEDRIVERFORMATCB callback function

## Description

The **pfnSetDisplayPrivateDriverFormatCb** function changes the private-format attribute of a video present source.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDICB_SETDISPLAYPRIVATEDRIVERFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_setdisplayprivatedriverformat) structure that describes how to format a video present source.

## Return value

**pfnSetDisplayPrivateDriverFormatCb** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The video present source was successfully changed.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|
|E_FAIL|pfnSetDisplayPrivateDriverFormatCb could not change the private-format attribute of the video present source.|

This function might also return other HRESULT values.

## Remarks

Changing the private-format attribute of a video present source is useful to accommodate a full-screen DirectX application that creates its flipping change when the shared GDI primary surface is in a non-optimal private format for the full-screen DirectX application. For example, suppose the display miniport driver always creates the GDI shared primary surface as un-swizzled. However, for performance reasons, the user-mode display driver requires that all the surfaces in a full-screen flipping chain are swizzled. The user-mode display driver could then create the back buffers as swizzled and call **pfnSetDisplayPrivateDriverFormatCb** to change the shared GDI primary surface to swizzled.

If the call to **pfnSetDisplayPrivateDriverFormatCb** fails, the user-mode display driver should continue without changing the private-format attribute of the video present source. In the preceding example, the driver can either leave the shared primary as un-swizzled and have the back buffers swizzled or the driver can change the back buffers to the un-swizzled format.

If the user-mode display driver receives the D3DDDIERR_INCOMPATIBLEPRIVATEFORMAT error from a call to the [pfnSetDisplayModeCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setdisplaymodecb) function, the driver can do one of the following:

* Change the private-format attribute of the primary surface and call **pfnSetDisplayModeCb** again.
* Call **pfnSetDisplayPrivateDriverFormatCb** and attempt to change the private-format attribute of the video present source. The driver can then call **pfnSetDisplayModeCb** again.

The user-mode display driver can call **pfnSetDisplayPrivateDriverFormatCb** only if the **Version** member of the [D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice) structure was set to greater than seven when the display device (specified by the *hDevice* parameter) was created in a call to the driver's [CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice) function.

## See also

[CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice)

[D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice)

[D3DDDICB_SETDISPLAYPRIVATEDRIVERFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_setdisplayprivatedriverformat)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)

[pfnSetDisplayModeCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setdisplaymodecb)