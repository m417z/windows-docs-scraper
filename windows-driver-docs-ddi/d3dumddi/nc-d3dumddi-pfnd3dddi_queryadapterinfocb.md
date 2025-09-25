# PFND3DDDI_QUERYADAPTERINFOCB callback function

## Description

The **pfnQueryAdapterInfoCb** function retrieves graphics adapter information.

## Parameters

### `hAdapter`

A handle to the graphics adapter object.

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDICB_QUERYADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_queryadapterinfo) structure that receives information about the graphics hardware.

## Return value

**pfnQueryAdapterInfoCb** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|Information was successfully retrieved.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

This function might also return other HRESULT values.

## Remarks

Before the Microsoft Direct3D runtime calls the user-mode display driver's [CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice) or [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function to create the graphics context, the user-mode display driver should call **pfnQueryAdapterInfoCb** to retrieve information about the graphics hardware. This order is especially important for a multiple-monitor system.

In the **pfnQueryAdapterInfoCb** call, the user-mode display driver sends a buffer that the display miniport driver fills with configuration data. After receiving this configuration data, the user-mode display driver can accurately report its capabilities when the runtime calls the user-mode display driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) and GetCaps(D3D10_2) functions. When the runtime subsequently calls other user-mode display driver functions that are specified in the [D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs), [D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs), or [D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs) structure, the user-mode display driver can generate command streams that the hardware can process.

#### Examples

The following code example shows how to retrieve graphics adapter information.

```cpp
    HRESULT hr;
    // Query for GART segment support
    D3DDDICB_QUERYADAPTERINFO   ddiQueryAdapterInfo;

    memset(&R200AdapterInfo, 0, sizeof(R200AdapterInfo));

    ddiQueryAdapterInfo.pPrivateDriverData = &R200AdapterInfo;
    ddiQueryAdapterInfo.PrivateDriverDataSize = sizeof(R200AdapterInfo);

    hr = m_Callbacks.pfnQueryAdapterInfoCb(m_hAdapter, &ddiQueryAdapterInfo);
    if (FAILED(hr)) {
        return FALSE;
    }

    m_ulGartSupported = R200AdapterInfo.ulGartSupported;
```

## See also

[CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice)

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[D3DDDICB_QUERYADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_queryadapterinfo)

[D3DDDI_ADAPTERCALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_adaptercallbacks)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)