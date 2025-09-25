# midiOutGetErrorText function

## Description

The **midiOutGetErrorText** function retrieves a textual description for an error identified by the specified error code.

## Parameters

### `mmrError`

Error code.

### `pszText`

Pointer to a buffer to be filled with the textual error description.

### `cchText`

Length, in characters, of the buffer pointed to by *lpText*.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_BADERRNUM** | The specified error number is out of range. |
| **MMSYSERR_INVALPARAM** | The specified pointer or structure is invalid. |

## Remarks

If the textual error description is longer than the specified buffer, the description is truncated. The returned error string is always null-terminated. If *cchText* is zero, nothing is copied, and the function returns MMSYSERR_NOERROR. All error descriptions are less than MAXERRORLENGTH characters long.

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)