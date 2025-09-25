# MFEnumDeviceSources function

## Description

Enumerates a list of audio or video capture devices.

## Parameters

### `pAttributes` [in]

Pointer to an attribute store that contains search criteria. To create the attribute store, call [MFCreateAttributes](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreateattributes). Set one or more of the following attributes on the attribute store:

| Value | Meaning |
| --- | --- |
| **[MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-devsource-attribute-source-type)** | Specifies whether to enumerate audio or video devices. (Required.) |
| **[MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_AUDCAP_ROLE](https://learn.microsoft.com/windows/desktop/medfound/mf-devsource-attribute-source-type-audcap-role)** | For audio capture devices, specifies the device role. (Optional.) |
| **[MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_CATEGORY](https://learn.microsoft.com/windows/desktop/medfound/mf-devsource-attribute-source-type-vidcap-category)** | For video capture devices, specifies the device category. (Optional.) |

### `pppSourceActivate` [out]

Receives an array of [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface pointers. Each pointer represents an activation object for a media source. The function allocates the memory for the array. The caller must release the pointers in the array and call [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to free the memory for the array.

### `pcSourceActivate` [out]

Receives the number of elements in the *pppSourceActivate* array. If no capture devices match the search criteria, this parameter receives the value 0.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Each returned [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) pointer represents a capture device, and can be used to create a media source for that device. You can also use the **IMFActivate** pointer to query for attributes that describe the device. The following attributes might be set:

| Attribute | Description |
| --- | --- |
| [MF_DEVSOURCE_ATTRIBUTE_FRIENDLY_NAME](https://learn.microsoft.com/windows/desktop/medfound/mf-devsource-attribute-friendly-name) | The display name of the device. |
| [MF_DEVSOURCE_ATTRIBUTE_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-devsource-attribute-media-type) | The major type and subtype GUIDs that describe the device's output format. |
| [MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-devsource-attribute-source-type) | The type of capture device (audio or video). |
| [MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_AUDCAP_ENDPOINT_ID](https://learn.microsoft.com/windows/desktop/medfound/mf-devsource-attribute-source-type-audcap-endpoint-id) | The audio endpoint ID string. (Audio devices only.) |
| [MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_CATEGORY](https://learn.microsoft.com/windows/desktop/medfound/mf-devsource-attribute-source-type-vidcap-category) | The device category. (Video devices only.) |
| [MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_HW_SOURCE](https://learn.microsoft.com/windows/desktop/medfound/mf-devsource-attribute-source-type-vidcap-hw-source) | Whether a device is a hardware or software device. (Video devices only.) |
| [MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_SYMBOLIC_LINK](https://learn.microsoft.com/windows/desktop/medfound/mf-devsource-attribute-source-type-vidcap-symbolic-link) | The symbolic link for the device driver. (Video devices only.) |

To create a media source from an [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) pointer, call the [IMFActivate::ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject) method.

#### Examples

The following example enumerates the video capture devices on the system and creates a media source for the first device on the list.

```cpp
HRESULT CreateVideoDeviceSource(IMFMediaSource **ppSource)
{
    *ppSource = NULL;

    IMFMediaSource *pSource = NULL;
    IMFAttributes *pAttributes = NULL;
    IMFActivate **ppDevices = NULL;

    // Create an attribute store to specify the enumeration parameters.
    HRESULT hr = MFCreateAttributes(&pAttributes, 1);
    if (FAILED(hr))
    {
        goto done;
    }

    // Source type: video capture devices
    hr = pAttributes->SetGUID(
        MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE,
        MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID
        );
    if (FAILED(hr))
    {
        goto done;
    }

    // Enumerate devices.
    UINT32 count;
    hr = MFEnumDeviceSources(pAttributes, &ppDevices, &count);
    if (FAILED(hr))
    {
        goto done;
    }

    if (count == 0)
    {
        hr = E_FAIL;
        goto done;
    }

    // Create the media source object.
    hr = ppDevices[0]->ActivateObject(IID_PPV_ARGS(&pSource));
    if (FAILED(hr))
    {
        goto done;
    }

    *ppSource = pSource;
    (*ppSource)->AddRef();

done:
    SafeRelease(&pAttributes);

    for (DWORD i = 0; i < count; i++)
    {
        SafeRelease(&ppDevices[i]);
    }
    CoTaskMemFree(ppDevices);
    SafeRelease(&pSource);
    return hr;
}

```

## See also

[Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/desktop/medfound/audio-video-capture-in-media-foundation)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)