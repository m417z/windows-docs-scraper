# PDXVAHDSW_ProposeVideoPrivateFormat callback function

## Description

Gets a private surface format from a software plug-in Microsoft DirectX Video Acceleration High Definition (DXVA-HD) device.

## Parameters

### `hDevice` [in]

A handle to the plug-in DXVA-HD device.

### `pFormat` [in, out]

A pointer to a **D3DFORMAT** value. On input, specifies the surface format that is requested by the application. On output, specifies the private surface format that the plug-in device proposes.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is called when the application calls [IDXVAHD_Device::CreateVideoSurface](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-createvideosurface) if the following conditions are true:

* The type of input surface is **DXVAHD_SURFACE_TYPE_VIDEO_INPUT_PRIVATE**.
* The Direct3D device does not support the surface format requested by the application natively.

This function enables the plug-in device to propose an alternate format with an equivalent memory layout. For example, if the application requests AYUV, the plug-in device might allocate a surface of type **D3DFMT_A8R8G8B8**.

If the function succeeds, the [CreateVideoSurface](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-createvideosurface) method attempts to create a surface with the format returned in *pFormat*.

#### Examples

The following code shows how a plug-in device proposes **D3DFMT_A8R8G8B8** as an alternative surface format for AYUV.

```
HRESULT CALLBACK ProposeVideoPrivateFormat(
    HANDLE hDevice,
    D3DFORMAT* pFormat
    )
{
    switch (*pFormat)
    {
        case D3DFMT_AYUV:
            *pFormat = D3DFMT_A8R8G8B8;
            return S_OK;

        default:
            return E_FAIL;
    }
}

```

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHDSW_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahdsw_callbacks)

[IDXVAHD_Device::CreateVideoSurface](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-createvideosurface)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)