# ISpatialAudioClient::GetSupportedAudioObjectFormatEnumerator

## Description

Gets an [IAudioFormatEnumerator](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-iaudioformatenumerator) that contains all supported audio formats for spatial audio objects, the first item in the list represents the most preferable format.

## Parameters

### `enumerator` [out]

Pointer to the pointer that receives the [IAudioFormatEnumerator](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-iaudioformatenumerator) interface.

## Return value

If the method succeeds, it returns S_OK.

## See also

[ISpatialAudioClient](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioclient)