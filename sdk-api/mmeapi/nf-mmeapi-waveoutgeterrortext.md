# waveOutGetErrorText function

## Description

The **waveOutGetErrorText** function retrieves a textual description of the error identified by the given error number.

## Parameters

### `mmrError`

Error number.

### `pszText`

Pointer to a buffer to be filled with the textual error description.

### `cchText`

Size, in characters, of the buffer pointed to by *pszText*.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_BADERRNUM** | Specified error number is out of range. |
| **MMSYSERR_NODRIVER** | No device driver is present. |
| **MMSYSERR_NOMEM** | Unable to allocate or lock memory. |

## Remarks

If the textual error description is longer than the specified buffer, the description is truncated. The returned error string is always null-terminated. If *cchText* is zero, nothing is copied and the function returns zero. All error descriptions are less than MAXERRORLENGTH characters long.

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)