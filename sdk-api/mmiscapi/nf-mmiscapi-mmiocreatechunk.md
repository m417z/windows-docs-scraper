# mmioCreateChunk function

## Description

The **mmioCreateChunk** function creates a chunk in a RIFF file that was opened by using the [mmioOpen](https://learn.microsoft.com/previous-versions/dd757331(v=vs.85)) function. The new chunk is created at the current file position. After the new chunk is created, the current file position is the beginning of the data portion of the new chunk.

## Parameters

### `hmmio`

File handle of an open RIFF file.

### `pmmcki`

Pointer to a buffer that receives a [MMCKINFO](https://learn.microsoft.com/previous-versions/dd757312(v=vs.85)) structure containing information about the chunk to be created.

### `fuCreate`

Flags identifying what type of chunk to create. The following values are defined.

| Value | Meaning |
| --- | --- |
| MMIO_CREATELIST | "LIST" chunk. |
| MMIO_CREATERIFF | "RIFF" chunk. |

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMIOERR_CANNOTSEEK** | Unable to determine offset of the data portion of the chunk. |
| **MMIOERR_CANNOTWRITE** | Unable to write the chunk header. |

## Remarks

This function cannot insert a chunk into the middle of a file. If an application attempts to create a chunk somewhere other than at the end of a file, **mmioCreateChunk** overwrites existing information in the file.

The [MMCKINFO](https://learn.microsoft.com/previous-versions/dd757312(v=vs.85)) structure pointed to by the *lpck* parameter should be set up as follows:

* The **ckid** member specifies the chunk identifier. If *wFlags* includes MMIO_CREATERIFF or MMIO_CREATELIST, this member will be filled by **mmioCreateChunk**.
* The **cksize** member specifies the size of the data portion of the chunk, including the form type or list type (if any). If this value is not correct when the [mmioAscend](https://learn.microsoft.com/previous-versions/dd757315(v=vs.85)) function is called to mark the end of the chunk, **mmioAscend** corrects the chunk size.
* The **fccType** member specifies the form type or list type if the chunk is a "RIFF" or "LIST" chunk. If the chunk is not a "RIFF" or "LIST" chunk, this member does not need to be filled in.
* The **dwDataOffset** member does not need to be filled in. The **mmioCreateChunk** function fills this member with the file offset of the data portion of the chunk.
* The **dwFlags** member does not need to be filled in. The **mmioCreateChunk** function sets the MMIO_DIRTY flag in **dwFlags**.