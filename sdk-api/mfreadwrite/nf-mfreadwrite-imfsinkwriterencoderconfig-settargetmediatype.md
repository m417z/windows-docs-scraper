# IMFSinkWriterEncoderConfig::SetTargetMediaType

## Description

Dynamically changes the target media type that Sink Writer is encoding to.

## Parameters

### `dwStreamIndex` [in]

Specifies the stream index.

### `pTargetMediaType` [in]

The new media format to encode to.

### `pEncodingParameters` [in]

The new set of encoding parameters to configure the encoder with.
If not specified, previously provided parameters will be used.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The new media type must be supported by the media sink being used and by the encoder MFTs installed on the system.

## See also

[IMFSinkWriter](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriter)

[IMFSinkWriterEncoderConfig](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriterencoderconfig)

[IMFSinkWriterEx](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriterex)