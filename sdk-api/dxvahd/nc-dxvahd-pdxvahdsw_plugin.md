# PDXVAHDSW_Plugin callback function

## Description

Pointer to a function that initializes a software plug-in device for Microsoft DirectX Video Acceleration High Definition (DXVA-HD).

## Parameters

### `Size` [in]

The size of the structure pointed to by the *pCallbacks* parameter, in bytes.

### `pCallbacks` [out]

A pointer to an uninitialized [DXVAHDSW_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahdsw_callbacks) structure. The function fills this structure with pointers to the plug-in device's callback functions.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [DXVAHDSW_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahdsw_callbacks) structure contains pointers to callback functions. The software plug-in device must implement these callback functions. The DXVA-HD device calls the **PDXVAHDSW_Plugin** function to get the callback function pointers from the plug-in device.

#### Examples

```cpp
HRESULT CALLBACK DXVAHDSW_Plugin(UINT Size, void* pv)
{
    if (Size < sizeof(DXVAHDSW_CALLBACKS))
    {
        return E_INVALIDARG;
    }

    DXVAHDSW_CALLBACKS* pCallbacks = (DXVAHDSW_CALLBACKS*) pv;

    // TODO: Fill in pCallbacks structure.

    return S_OK;
}
```

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHD_CreateDevice](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-dxvahd_createdevice)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)