# IMFMediaSharingEngine::GetDevice

## Description

Gets information about the media sharing device.

## Parameters

### `pDevice` [out]

A pointer to a [DEVICE_INFO](https://learn.microsoft.com/windows/desktop/api/mfsharingengine/ns-mfsharingengine-device_info) structure. The method fills in this structure with the device information.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The method allocates memory for the **BSTR** members of the [DEVICE_INFO](https://learn.microsoft.com/windows/desktop/api/mfsharingengine/ns-mfsharingengine-device_info) structure. The caller must free the memory for each **BSTR** by calling **SysFreeString**.

## See also

[IMFMediaSharingEngine](https://learn.microsoft.com/windows/desktop/api/mfsharingengine/nn-mfsharingengine-imfmediasharingengine)