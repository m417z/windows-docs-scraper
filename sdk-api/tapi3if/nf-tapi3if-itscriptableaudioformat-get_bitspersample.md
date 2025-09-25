# ITScriptableAudioFormat::get_BitsPerSample

## Description

The
**get_BitsPerSample** method returns the value for the **wBitsPerSample** member in the
[WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure.

## Parameters

### `pVal` [out]

Pointer to the value of the **wBitsPerSample** member in the
[WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pVal* argument is not a valid pointer. |

## See also

[ITScriptableAudioFormat](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itscriptableaudioformat)

[put_BitsPerSample](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itscriptableaudioformat-put_bitspersample)