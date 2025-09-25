# IMFSinkWriterEncoderConfig::PlaceEncodingParameters

## Description

Dynamically updates the encoder configuration with a collection of new encoder settings.

## Parameters

### `dwStreamIndex` [in]

Specifies the stream index.

### `pEncodingParameters` [in]

A set of encoding parameters to configure the encoder with.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The encoder will be configured with these settings after all previously queued input media samples have been sent to it through [IMFTransform::ProcessInput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processinput).

## See also

[IMFSinkWriter](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriter)

[IMFSinkWriterEncoderConfig](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriterencoderconfig)

[IMFSinkWriterEx](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriterex)