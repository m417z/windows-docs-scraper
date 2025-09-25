# FILE_COMPRESSION_INFO structure

## Description

Receives file compression information. Used for any handles. Use only when calling [GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex).

## Members

### `CompressedFileSize`

The file size of the compressed file.

### `CompressionFormat`

The compression format that is used to compress the file.

### `CompressionUnitShift`

The factor that the compression uses.

### `ChunkShift`

The number of chunks that are shifted by compression.

### `ClusterShift`

The number of clusters that are shifted by compression.

### `Reserved`

Reserved.

## See also

[FILE_INFO_BY_HANDLE_CLASS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-file_info_by_handle_class)

[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex)