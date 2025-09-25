# HANDLE_OPTIONS enumeration

## Description

Defines the flags of the file handle.

## Constants

### `HO_NONE:0`

None.

### `HO_OPEN_REQUIRING_OPLOCK:0x40000`

This value is for internal use only.

### `HO_DELETE_ON_CLOSE:0x4000000`

The file is to be deleted immediately after this handle is closed.

### `HO_SEQUENTIAL_SCAN:0x8000000`

Access is intended to be sequential from beginning to end. The system can use this as a hint to optimize file caching.
For additional information, see [Caching Behavior](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).

### `HO_RANDOM_ACCESS:0x10000000`

Access is intended to be random. The system can use this as a hint to optimize file caching.
For more information, see [Caching Behavior](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).

### `HO_NO_BUFFERING:0x20000000`

The file is being opened with no system caching for data reads and writes. This flag does not affect hard disk caching or memory mapped files.
There are strict requirements for successfully working with files opened with this flag. For details see [File Buffering](https://learn.microsoft.com/windows/desktop/FileIO/file-buffering).

### `HO_OVERLAPPED:0x40000000`

The file is being opened or created for asynchronous I/O.
For information about considerations when using a file handle created with this flag, see [Synchronous and Asynchronous I/O Handles](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).

### `HO_WRITE_THROUGH:0x80000000`

Write operations will not go through any intermediate cache, they will go directly to disk.
For additional information, see [Caching Behavior](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).