# ITFileTrack::get_EmptyAudioFormatForScripting

## Description

The
**get_EmptyAudioFormatForScripting** method is used to get an
[ITScriptableAudioFormat](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itscriptableaudioformat) interface with all fields set to 0.

## Parameters

### `ppAudioFormat` [out]

Pointer to
[ITScriptableAudioFormat](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itscriptableaudioformat) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

TAPI calls the **AddRef** method on the
[ITScriptableAudioFormat](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itscriptableaudioformat) interface returned by **ITFileTrack::get_EmptyAudioFormatForScripting**. The application must call **Release** on
**ITScriptableAudioFormat** to free resources associated with it.

## See also

[ITFileTrack](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itfiletrack)