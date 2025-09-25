# ITFileTrack::get_AudioFormatForScripting

## Description

The
**get_AudioFormatForScripting** method gets the audio scripting format.

## Parameters

### `ppAudioFormat` [out]

Pointer to the
[ITScriptableAudioFormat](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itscriptableaudioformat) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

TAPI calls the **AddRef** method on the
[ITScriptableAudioFormat](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itscriptableaudioformat) interface returned by **ITFileTrack::get_AudioFormatForScripting**. The application must call **Release** on
**ITScriptableAudioFormat** to free resources associated with it.

## See also

[ITFileTrack](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itfiletrack)