# IMFTranscodeProfile::GetContainerAttributes

## Description

Gets the container settings that are currently set in the transcode profile.

## Parameters

### `ppAttrs` [out]

Receives a pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of the attribute store containing the current container type for the output file. Caller must release the interface pointer.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If there are no container attributes set in the transcode profile, the call to **GetContainerAttributes** succeeds and *ppAttrs* receives **NULL**.

 To get a specific attribute value, the caller must call the appropriate [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) method depending on the data type of the attribute. The following list shows the container attributes:

* [MF_TRANSCODE_CONTAINERTYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-containertype)
* [MF_TRANSCODE_SKIP_METADATA_TRANSFER](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-skip-metadata-transfer)
* [MF_TRANSCODE_TOPOLOGYMODE](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-topologymode)

## See also

[Attributes in Media Foundation](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[IMFTranscodeProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftranscodeprofile)

[Transcode API](https://learn.microsoft.com/windows/desktop/medfound/transcode-api)