# D3DKMTOpenAdapterFromHdc function

## Description

The **D3DKMTOpenAdapterFromHdc** function maps a device context handle (HDC) to a graphics adapter handle and, if the adapter contains multiple monitor outputs, to one of those outputs.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_OPENADAPTERFROMHDC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_openadapterfromhdc) structure that describes the parameters that are required to perform the mapping.

## Return value

**D3DKMTOpenAdapterFromHdc** returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The mapping was performed successfully.|
|STATUS_NO_MEMORY|The kernel ran out of the resources that would enable it to open another handle.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect or the Windows Vista display driver model was not used.|

This function might also return other **NTSTATUS** values.

## Remarks

A graphics adapter corresponds to a video card. A monitor output corresponds to a head on a video card. A system with a single video card contains only one adapter. However, if the video card supports multiple heads, it supports outputting to multiple monitors.
Use the [D3DKMTCloseAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcloseadapter) function to avoid resource leaks.

#### Examples

The following code example demonstrates how an OpenGL ICD can use **D3DKMTOpenAdapterFromHdc** to retrieve the graphics adapter handle and the output for the primary monitor from the HDC.

```cpp
HRESULT GetPrimaryAdapterHandle(HANDLE* phAdapter, UINT* pOutput)
{
    D3DKMT_OPENADAPTERFROMHDC OpenAdapterData;
    DISPLAY_DEVICE dd;
    HDC hdc;
    int i;

    *phAdapter = NULL;
    *pOutput = 0;
    memset(&dd, 0, sizeof (dd));
    dd.cb = sizeof dd;

    for (i = 0; EnumDisplayDevicesA(NULL, i, &dd, 0); ++i) {
        if (dd.StateFlags & DISPLAY_DEVICE_PRIMARY_DEVICE) {
            break;
        }
    }

    hdc = CreateDC (NULL, dd.DeviceName, NULL, NULL);
    if (hdc == NULL) {
        return E_FAIL;
    }

    OpenAdapterData.hDc = hdc;
    if (NT_SUCCESS((*pfnKTOpenAdapterFromHdc)(&OpenAdapterData))) {
        DeleteDC(hdc);
        *phAdapter = OpenAdapterData.hAdapter;
        *pOutput = OpenAdapterData.VidPnSourceId;
        return S_OK;
    }
    DeleteDC(hdc);

    return E_FAIL;
}
```

## See also

[D3DKMT_OPENADAPTERFROMHDC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_openadapterfromhdc)