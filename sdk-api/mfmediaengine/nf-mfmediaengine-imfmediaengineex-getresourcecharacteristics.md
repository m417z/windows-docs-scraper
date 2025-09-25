# IMFMediaEngineEx::GetResourceCharacteristics

## Description

Gets various flags that describe the media resource.

## Parameters

### `pCharacteristics` [out]

Receives a bitwise **OR** of zero or more flags from the [MFMEDIASOURCE_CHARACTERISTICS enumeration](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfmediasource_characteristics).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFMediaEngineEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineex)