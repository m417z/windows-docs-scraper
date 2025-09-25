# mmioAscend function

## Description

The **mmioAscend** function ascends out of a chunk in a RIFF file descended into with the [mmioDescend](https://learn.microsoft.com/previous-versions/dd757318(v=vs.85)) function or created with the [mmioCreateChunk](https://learn.microsoft.com/previous-versions/dd757317(v=vs.85)) function.

## Parameters

### `hmmio`

File handle of an open RIFF file.

### `pmmcki`

Pointer to an application-defined [MMCKINFO](https://learn.microsoft.com/previous-versions/dd757312(v=vs.85)) structure previously filled by the [mmioDescend](https://learn.microsoft.com/previous-versions/dd757318(v=vs.85)) or [mmioCreateChunk](https://learn.microsoft.com/previous-versions/dd757317(v=vs.85)) function.

### `fuAscend`

Reserved; must be zero.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMIOERR_CANNOTSEEK** | There was an error while seeking to the end of the chunk. |
| **MMIOERR_CANNOTWRITE** | The contents of the buffer could not be written to disk. |

## Remarks

If the chunk was descended into by using [mmioDescend](https://learn.microsoft.com/previous-versions/dd757318(v=vs.85)), **mmioAscend** seeks to the location following the end of the chunk (past the extra pad byte, if any).

If the chunk was created and descended into by using **mmioCreateChunk**, or if the MMIO_DIRTY flag is set in the **dwFlags** member of the **MMCKINFO** structure referenced by *lpck*, the current file position is assumed to be the end of the data portion of the chunk. If the chunk size is not the same as the value stored in the **cksize** member of the **MMCKINFO** structure when **mmioCreateChunk** was called, **mmioAscend** corrects the chunk size in the file before ascending from the chunk. If the chunk size is odd, **mmioAscend** writes a null pad byte at the end of the chunk. After ascending from the chunk, the current file position is the location following the end of the chunk (past the extra pad byte, if any).