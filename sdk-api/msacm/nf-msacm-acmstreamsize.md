# acmStreamSize function

## Description

The **acmStreamSize** function returns a recommended size for a source or destination buffer on an ACM stream.

## Parameters

### `has`

Handle to the conversion stream.

### `cbInput`

Size, in bytes, of the source or destination buffer. The *fdwSize* flags specify what the input parameter defines. This parameter must be nonzero.

### `pdwOutputBytes`

Pointer to a variable that contains the size, in bytes, of the source or destination buffer. The *fdwSize* flags specify what the output parameter defines. If the **acmStreamSize** function succeeds, this location will always be filled with a nonzero value.

### `fdwSize`

Flags for the stream size query. The following values are defined:

| Value | Meaning |
| --- | --- |
| ACM_STREAMSIZEF_DESTINATION | The *cbInput* parameter contains the size of the destination buffer. The *pdwOutputBytes* parameter will receive the recommended source buffer size, in bytes. |
| ACM_STREAMSIZEF_SOURCE | The *cbInput* parameter contains the size of the source buffer. The *pdwOutputBytes* parameter will receive the recommended destination buffer size, in bytes. |

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ACMERR_NOTPOSSIBLE** | The requested operation cannot be performed. |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |
| **MMSYSERR_INVALPARAM** | At least one parameter is invalid. |

## Remarks

An application can use this function to determine suggested buffer sizes for either source or destination buffers. The buffer sizes returned might be only an estimation of the actual sizes required for conversion. Because actual conversion sizes cannot always be determined without performing the conversion, the sizes returned will usually be overestimated.

In the event of an error, the location pointed to by *pdwOutputBytes* will receive zero. This assumes that the pointer specified by *pdwOutputBytes* is valid.

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)