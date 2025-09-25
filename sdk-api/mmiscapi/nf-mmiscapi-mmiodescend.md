# mmioDescend function

## Description

The **mmioDescend** function descends into a chunk of a RIFF file that was opened by using the [mmioOpen](https://learn.microsoft.com/previous-versions/dd757331(v=vs.85)) function. It can also search for a given chunk.

## Parameters

### `hmmio`

File handle of an open RIFF file.

### `pmmcki`

Pointer to a buffer that receives an [MMCKINFO](https://learn.microsoft.com/previous-versions/dd757312(v=vs.85)) structure.

### `pmmckiParent`

Pointer to an optional application-defined [MMCKINFO](https://learn.microsoft.com/previous-versions/dd757312(v=vs.85)) structure identifying the parent of the chunk being searched for. If this parameter is not **NULL**, **mmioDescend** assumes the **MMCKINFO** structure it refers to was filled when **mmioDescend** was called to descend into the parent chunk, and **mmioDescend** searches for a chunk within the parent chunk. Set this parameter to **NULL** if no parent chunk is being specified.

### `fuDescend`

Search flags. If no flags are specified, **mmioDescend** descends into the chunk beginning at the current file position. The following values are defined.

| Value | Meaning |
| --- | --- |
| MMIO_FINDCHUNK | Searches for a chunk with the specified chunk identifier. |
| MMIO_FINDLIST | Searches for a chunk with the chunk identifier "LIST" and with the specified form type. |
| MMIO_FINDRIFF | Searches for a chunk with the chunk identifier "RIFF" and with the specified form type. |

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMIOERR_CHUNKNOTFOUND** | The end of the file (or the end of the parent chunk, if given) was reached before the desired chunk was found. |

## Remarks

A "RIFF" chunk consists of a four-byte chunk identifier (type **FOURCC**), followed by a four-byte chunk size (type **DWORD**), followed by the data portion of the chunk, followed by a null pad byte if the size of the data portion is odd. If the chunk identifier is "RIFF" or "LIST", the first four bytes of the data portion of the chunk are a form type or list type (type **FOURCC**).

If you use **mmioDescend** to search for a chunk, make sure the file position is at the beginning of a chunk before calling the function. The search begins at the current file position and continues to the end of the file. If a parent chunk is specified, the file position should be somewhere within the parent chunk before calling **mmioDescend**. In this case, the search begins at the current file position and continues to the end of the parent chunk.

If **mmioDescend** is unsuccessful in searching for a chunk, the current file position is undefined. If **mmioDescend** is successful, the current file position is changed. If the chunk is a "RIFF" or "LIST" chunk, the new file position will be just after the form type or list type (12 bytes from the beginning of the chunk). For other chunks, the new file position will be the start of the data portion of the chunk (8 bytes from the beginning of the chunk).

The **mmioDescend** function fills the [MMCKINFO](https://learn.microsoft.com/previous-versions/dd757312(v=vs.85)) structure pointed to by the *lpck* parameter with the following information:

* The **ckid** member is the chunk. If the MMIO_FINDCHUNK, MMIO_FINDRIFF, or MMIO_FINDLIST flag is specified for **wFlags**, the [MMCKINFO](https://learn.microsoft.com/previous-versions/dd757312(v=vs.85)) structure is also used to pass parameters to **mmioDescend**. In this case, the **ckid** member specifies the four-character code of the chunk identifier, form type, or list type to search for.
* The **cksize** member is the size, in bytes, of the data portion of the chunk. The size includes the form type or list type (if any), but does not include the 8-byte chunk header or the pad byte at the end of the data (if any).
* The **fccType** member is the form type if **ckid** is "RIFF", or the list type if **ckid** is "LIST". Otherwise, it is **NULL**.
* The **dwDataOffset** member is the file offset of the beginning of the data portion of the chunk. If the chunk is a "RIFF" chunk or a "LIST" chunk, this member is the offset of the form type or list type.
* The **dwFlags** member contains other information about the chunk. Currently, this information is not used and is set to zero.