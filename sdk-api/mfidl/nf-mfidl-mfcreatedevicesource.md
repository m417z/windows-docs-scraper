# MFCreateDeviceSource function

## Description

Creates a media source for a hardware capture device.

## Parameters

### `pAttributes` [in]

Pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of an attribute store, which is used to select the device. See Remarks.

### `ppSource` [out]

Receives a pointer to the media source's [IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Important** When the capture device is no longer needed, you must shut down the device by calling [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-shutdown) on the [IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource) object you obtained by calling **MFCreateDeviceSource**. Failure to call **Shutdown** can result in memory links because the system may keep a reference to **IMFMediaSource** resources until **Shutdown** is called.

The *pAttributes* parameter specifies an attribute store. To create the attribute store, call the [MFCreateAttributes](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreateattributes) function. You must set the [MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-devsource-attribute-source-type) attribute, which specifies the type of device (audio or video).

For audio capture devices, optionally set one of the following attributes:

| Attribute | Description |
| --- | --- |
| [MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_AUDCAP_ENDPOINT_ID](https://learn.microsoft.com/windows/desktop/medfound/mf-devsource-attribute-source-type-audcap-endpoint-id) | Specifies the audio endpoint ID of the audio capture device. |
| [MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_AUDCAP_ROLE](https://learn.microsoft.com/windows/desktop/medfound/mf-devsource-attribute-source-type-audcap-role) | Specifies the device role. If this attribute is set, the function uses the default audio capture device for that device role.<br><br>Do not combine this attribute with the [MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_AUDCAP_ENDPOINT_ID](https://learn.microsoft.com/windows/desktop/medfound/mf-devsource-attribute-source-type-audcap-endpoint-id) attribute. |

If neither attribute is specified, the function selects the default audio capture device for the **eCommunications** role.

For video capture devices, you must set the following attribute:

| Attribute | Description |
| --- | --- |
| [MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_SYMBOLIC_LINK](https://learn.microsoft.com/windows/desktop/medfound/mf-devsource-attribute-source-type-vidcap-symbolic-link) | Specifies the symbolic link to the device. |

## See also

[Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/desktop/medfound/audio-video-capture-in-media-foundation)

[Capture Device Attributes](https://learn.microsoft.com/windows/desktop/medfound/capture-device-attributes)

[MFCreateDeviceSourceActivate](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatedevicesourceactivate)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)