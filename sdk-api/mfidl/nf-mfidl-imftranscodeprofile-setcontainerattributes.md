# IMFTranscodeProfile::SetContainerAttributes

## Description

Sets container configuration settings in the transcode profile.

 For example code, see [MFCreateTranscodeProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatetranscodeprofile).

## Parameters

### `pAttrs` [in]

Pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of an attribute store that contains the configuration settings for the container in which the transcoded file will be stored. The specified attribute values overwrite any existing values stored in the transcode profile.

The following list shows the container attributes that can be set:

* [MF_TRANSCODE_ADJUST_PROFILE](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-adjust-profile)
* [MF_TRANSCODE_CONTAINERTYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-containertype)
* [MF_TRANSCODE_SKIP_METADATA_TRANSFER](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-skip-metadata-transfer)
* [MF_TRANSCODE_TOPOLOGYMODE](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-topologymode)
* [MFT_FIELDOFUSE_UNLOCK](https://learn.microsoft.com/windows/desktop/medfound/mft-fieldofuse-unlock-attribute)

To create the attribute store, call [MFCreateAttributes](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreateattributes). To set a specific attribute value in the attribute store, the caller must call the appropriate [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) methods depending on the data type of the attribute.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Attributes in Media Foundation](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[IMFTranscodeProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftranscodeprofile)

[MFCreateAttributes](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreateattributes)

[Transcode API](https://learn.microsoft.com/windows/desktop/medfound/transcode-api)