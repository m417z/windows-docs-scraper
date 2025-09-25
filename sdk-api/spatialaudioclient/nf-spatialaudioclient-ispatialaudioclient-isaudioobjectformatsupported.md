# ISpatialAudioClient::IsAudioObjectFormatSupported

## Description

Gets a value indicating whether [ISpatialAudioObjectRenderStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobjectrenderstream) supports a the specified format.

## Parameters

### `objectFormat` [in]

The format for which support is queried.

## Return value

If the specified format is supported, it returns S_OK. If specified format is unsupported, this method returns AUDCLNT_E_UNSUPPORTED_FORMAT.

## See also

[ISpatialAudioClient](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioclient)