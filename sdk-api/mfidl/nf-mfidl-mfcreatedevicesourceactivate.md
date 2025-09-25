# MFCreateDeviceSourceActivate function

## Description

Creates an activation object that represents a hardware capture device.

## Parameters

### `pAttributes` [in]

Pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of an attribute store, which is used to select the device. See Remarks.

### `ppActivate` [out]

Receives a pointer to the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface. The caller must release the interface.

## Remarks

This function creates an activation object that can be used to create a media source for a hardware device. To create the media source itself, call [IMFActivate::ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject).

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

[Activation Objects](https://learn.microsoft.com/windows/desktop/medfound/activation-objects)

[Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/desktop/medfound/audio-video-capture-in-media-foundation)

[Capture Device Attributes](https://learn.microsoft.com/windows/desktop/medfound/capture-device-attributes)

[MFCreateDeviceSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatedevicesource)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)