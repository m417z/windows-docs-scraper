# MMCKINFO structure

## Description

The **MMCKINFO** structure contains information about a chunk in a RIFF file.

## Members

### `ckid`

Chunk identifier.

### `cksize`

Size, in bytes, of the data member of the chunk. The size of the data member does not include the 4-byte chunk identifier, the 4-byte chunk size, or the optional pad byte at the end of the data member.

### `fccType`

Form type for "RIFF" chunks or the list type for "LIST" chunks.

### `dwDataOffset`

File offset of the beginning of the chunk's data member, relative to the beginning of the file.

### `dwFlags`

Flags specifying additional information about the chunk. It can be zero or the following flag:

| Name | Description |
| --- | --- |
| **MMIO_DIRTY** | The length of the chunk might have changed and should be updated by the [mmioAscend](https://learn.microsoft.com/previous-versions/dd757315(v=vs.85)) function. This flag is set when a chunk is created by using the [mmioCreateChunk](https://learn.microsoft.com/previous-versions/dd757317(v=vs.85)) function. |

## See also

[mmioAscend](https://learn.microsoft.com/previous-versions/dd757315(v=vs.85))

[mmioCreateChunk](https://learn.microsoft.com/previous-versions/dd757317(v=vs.85))