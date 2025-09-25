# IDXVAHD_Device::GetVideoProcessorOutputFormats

## Description

Gets a list of the output formats supported by the Microsoft DirectX Video Acceleration High Definition (DXVA-HD) device.

## Parameters

### `Count` [in]

The number of formats to retrieve. This parameter must equal the **OutputFormatCount** member of the [DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps) structure. Call the [IDXVAHD_Device::GetVideoProcessorDeviceCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessordevicecaps) method to get this value.

### `pFormats` [out]

A pointer to an array of **D3DFORMAT** values. The *Count* parameter specifies the number of elements in the array. The method fills the array with a list of output formats.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The list of formats can include both **D3DFORMAT** values, such as **D3DFMT_X8R8G8B8**, and FOURCC codes, such as 'NV12'. For more information, see [Video FOURCCs](https://learn.microsoft.com/windows/desktop/medfound/video-fourccs).

#### Examples

```cpp
// Checks whether a DXVA-HD device supports a specified output format.

HRESULT CheckOutputFormatSupport(
    IDXVAHD_Device          *pDXVAHD,
    const DXVAHD_VPDEVCAPS& caps,
    D3DFORMAT               d3dformat
    )
{
    D3DFORMAT *pFormats = new (std::nothrow) D3DFORMAT[caps.OutputFormatCount];
    if (pFormats == NULL)
    {
        return E_OUTOFMEMORY;
    }

    HRESULT hr = pDXVAHD->GetVideoProcessorOutputFormats(
        caps.OutputFormatCount,
        pFormats
        );

    if (FAILED(hr))
    {
        goto done;
    }

    UINT index;
    for (index = 0; index < caps.OutputFormatCount; index++)
    {
        if (pFormats[index] == d3dformat)
        {
            break;
        }
    }
    if (index == caps.OutputFormatCount)
    {
        hr = E_FAIL;
    }

done:
    delete [] pFormats;
    return hr;
}

```

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[IDXVAHD_Device](https://learn.microsoft.com/windows/desktop/api/dxvahd/nn-dxvahd-idxvahd_device)