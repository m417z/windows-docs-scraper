# AVIStreamWrite function

## Description

The **AVIStreamWrite** function writes data to a stream.

## Parameters

### `pavi`

Handle to an open stream.

### `lStart`

First sample to write.

### `lSamples`

Number of samples to write.

### `lpBuffer`

Pointer to a buffer containing the data to write.

### `cbBuffer`

Size of the buffer referenced by *lpBuffer*.

### `dwFlags`

Flag associated with this data. The following flag is defined:

| Value | Meaning |
| --- | --- |
| **AVIIF_KEYFRAME** | Indicates this data does not rely on preceding data in the file. |

### `plSampWritten`

Pointer to a buffer that receives the number of samples written. This can be set to **NULL**.

### `plBytesWritten`

Pointer to a buffer that receives the number of bytes written. This can be set to **NULL**.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

The default AVI file handler supports writing only at the end of a stream. The "WAVE" file handler supports writing anywhere.

This function overwrites existing data, rather than inserting new data.

The argument *pavi* is a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)