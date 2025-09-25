# MFCreateTransformActivate function

## Description

Creates a generic activation object for Media Foundation transforms (MFTs).

## Parameters

### `ppActivate` [out]

Receives a pointer to the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface.
The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Most applications will not use this function; it is used internally by the [MFTEnumEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenumex) function.

An *activation object* is a helper object that creates another object, somewhat similar to a class factory. The **MFCreateTransformActivate** function creates an activation object for MFTs. Before this activation object can create an MFT, the caller must initialize the activation object by setting one or more attributes on it.

| Attribute | Description |
| --- | --- |
| [MFT_TRANSFORM_CLSID_Attribute](https://learn.microsoft.com/windows/desktop/medfound/mft-transform-clsid-attribute) | Required. Contains the CLSID of the MFT. The activation object creates the MFT by passing this CLSID to the **CoCreateInstance** function. |
| [MF_TRANSFORM_CATEGORY_Attribute](https://learn.microsoft.com/windows/desktop/medfound/mf-transform-category-attribute) | Optional. Specifies the category of the MFT. |
| [MF_TRANSFORM_FLAGS_Attribute](https://learn.microsoft.com/windows/desktop/medfound/mf-transform-flags-attribute) | Contains various flags that describe the MFT. For hardware-based MFTs, set the **MFT_ENUM_FLAG_HARDWARE** flag. Otherwise, this attribute is optional. |
| [MFT_CODEC_MERIT_Attribute](https://learn.microsoft.com/windows/desktop/medfound/mft-codec-merit-attribute) | Optional. Contains the merit value of a hardware codec.<br><br>If this attribute is set and its value is greater than zero, the activation object calls [MFGetMFTMerit](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfgetmftmerit) to get the trusted merit value for the MFT. If the trusted merit is less than the value of this attribute, the activation object's [IMFActivate::ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject) method fails and returns **MF_E_INVALID_CODEC_MERIT**. |
| [MFT_ENUM_HARDWARE_URL_Attribute](https://learn.microsoft.com/windows/desktop/medfound/mft-enum-hardware-url-attribute) | Required for hardware-based MFTs. Specifies the symbolic link for the hardware device. The device proxy uses this value to configure the MFT. |
| [MFT_FIELDOFUSE_UNLOCK_Attribute](https://learn.microsoft.com/windows/desktop/medfound/mft-fieldofuse-unlock-attribute) | Optional. Contains an [IMFFieldOfUseMFTUnlock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imffieldofusemftunlock) pointer, which can be used to unlock the MFT. The **IMFFieldOfUseMFTUnlock** interface is used with MFTs that have usage restrictions.<br><br>If this attribute is set and the [MF_TRANSFORM_FLAGS_Attribute](https://learn.microsoft.com/windows/desktop/medfound/mf-transform-flags-attribute) attribute contains the **MFT_ENUM_FLAG_FIELDOFUSE** flag, the activation object calls [IMFFieldOfUseMFTUnlock::Unlock](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imffieldofusemftunlock-unlock) when it creates the MFT. An application can also set the [MFT_FIELDOFUSE_UNLOCK_Attribute](https://learn.microsoft.com/windows/desktop/medfound/mft-fieldofuse-unlock-attribute) attribute without setting the **MFT_ENUM_FLAG_FIELDOFUSE** flag. In that case, the application must call **Unlock**. |
| [MFT_PREFERRED_ENCODER_PROFILE](https://learn.microsoft.com/windows/desktop/medfound/mft-preferred-encoder-profile) | Optional. Contains the encoding profile for an encoder. The value of this attribute is an [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) pointer.<br><br>If this attribute is set and the value of the [MF_TRANSFORM_CATEGORY_Attribute](https://learn.microsoft.com/windows/desktop/medfound/mf-transform-category-attribute) attribute is **MFT_CATEGORY_AUDIO_ENCODER** or **MFT_CATEGORY_VIDEO_ENCODER**, the activation object uses the encoding profile to configure the MFT. The MFT must expose either **ICodecAPI** or **IPropertyStore** for this purpose. |
| [MFT_PREFERRED_OUTPUTTYPE_Attribute](https://learn.microsoft.com/windows/desktop/medfound/mft-preferred-outputtype-attribute) | Optional. Specifies the preferred output format for an encoder.<br><br>If this attribute set and the value of the [MF_TRANSFORM_CATEGORY_Attribute](https://learn.microsoft.com/windows/desktop/medfound/mf-transform-category-attribute) attribute is **MFT_CATEGORY_AUDIO_ENCODER** or **MFT_CATEGORY_VIDEO_ENCODER**, the activation object sets this media type on the MFT. |

For more information about activation objects, see [Activation Objects](https://learn.microsoft.com/windows/desktop/medfound/activation-objects).

## See also

[Activation Objects](https://learn.microsoft.com/windows/desktop/medfound/activation-objects)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)