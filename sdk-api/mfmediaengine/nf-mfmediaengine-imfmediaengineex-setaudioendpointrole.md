# IMFMediaEngineEx::SetAudioEndpointRole

## Description

Sets the audio device endpoint used for the next call to [SetSource](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-setsource) or [Load](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-load).

## Parameters

### `role` [in]

Specifies the audio end point role.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For information on audio endpoint roles, see [ERole enumeration](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/ne-mmdeviceapi-erole).

## See also

[IMFMediaEngineEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineex)