## Description

Callback function that allows APOs to specify a preferred input format for the provided output format.

## Parameters

### `outputFormat` [in]

An [IAudioMediaType](https://learn.microsoft.com/windows/win32/api/audiomediatype/nn-audiomediatype-iaudiomediatype) representing the output format associated with the callback.

### `preferredFormat` [out]

An **IAudioMediaType** representing the preferred input format for the APO.

## Return value

An HRESULT.

## Remarks

This API enables scenarios such as a headphone provider that provides virtual surround sound. The APO could request to receive 7-1 input even though the endpoint renders in stereo. APOs can specify different preferred formats for different output formats. For example, an app may request 7.1 input when the m stream type is media, but request stereo input when the stream type is communications.

## See also