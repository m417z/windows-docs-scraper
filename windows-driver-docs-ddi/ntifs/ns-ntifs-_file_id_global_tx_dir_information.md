# _FILE_ID_GLOBAL_TX_DIR_INFORMATION structure

## Description

The **FILE_ID_GLOBAL_TX_DIR_INFORMATION** structure contains information about transactional visibility for the files in a directory.

## Members

### `NextEntryOffset`

The byte offset from the beginning of this entry, at which the next FILE_ID_FULL_DIR_INFORMATION entry is located if multiple entries are present in a buffer. A value of zero indicates no other entries follow this one.

### `FileIndex`

The byte offset of the file within the parent directory. For file systems in which the position of a file within the parent directory is not fixed and can be changed to maintain sort order, this field should be set to 0 and is ignored.

### `CreationTime`

The time when the file was created.

### `LastAccessTime`

The last time the file was accessed.

### `LastWriteTime`

The last time information was written to the file.

### `ChangeTime`

The last time the file was changed.

### `EndOfFile`

The absolute new end-of-file position as a byte offset from the start of the file. EndOfFile specifies the offset to the byte immediately following the last valid byte in the file.

### `AllocationSize`

The file allocation size in bytes. The value of this field is an integer multiple of the cluster size.

### `FileAttributes`

The file attributes.

| Flag | Meaning |
| --- | --- |
| FILE_ATTRIBUTE_NORMAL | A file that has standard attributes should be created. |
| FILE_ATTRIBUTE_READONLY | A read-only file should be created. |
| FILE_ATTRIBUTE_HIDDEN | A hidden file should be created. |
| FILE_ATTRIBUTE_SYSTEM | A system file should be created. |
| FILE_ATTRIBUTE_ARCHIVE | The file should be marked so that it will be archived. |
| FILE_ATTRIBUTE_TEMPORARY | A temporary file should be created. |

### `FileNameLength`

The length, in bytes, of the file name contained within the **FileName** member.

### `FileId`

A file reference number for the file. The file system generates this number and assigns it to the file. For file systems that do not support **FileId**, this field is set to 0 and ignored.

### `LockingTransactionId`

A GUID value of the transaction that has this file locked for modification. The file system generates and assigns this value.

### `TxInfoFlags`

A bitwise OR of zero or more of the following values.

| Value | Meaning |
| --- | --- |
| FILE_ID_GLOBAL_TX_DIR_INFO_FLAG_WRITELOCKED 0x00000001 | The file is locked for modification by a transaction. The transaction's ID must be contained in the **LockingTransactionId** member if this flag is set. |
| FILE_ID_GLOBAL_TX_DIR_INFO_FLAG_VISIBLE_TO_TX 0x00000002 | The file is visible to transacted enumerators of the directory whose transaction ID is in the **LockingTransactionId** member. |
| FILE_ID_GLOBAL_TX_DIR_INFO_FLAG_VISIBLE_OUTSIDE_TX 0x00000004 | The file is visible to transacted enumerators of the directory other than the one whose transaction ID is in the **LockingTransactionId** member, and it is visible to non-transacted enumerators of the directory. |

If the FILE_ID_GLOBAL_TX_DIR_INFO_FLAG_WRITELOCKED flag is not set, the other flags must not be set. If flags other than FILE_ID_GLOBAL_TX_DIR_INFO_FLAG_WRITELOCKED are set, the FILE_ID_GLOBAL_TX_DIR_INFO_FLAG_WRITELOCKED flag must be set.

### `FileName`

A sequence of Unicode characters containing the file name.

**Note** Use **FileNameLength** to determine the length of the file name rather than assuming the presence of a trailing null delimiter.

## Remarks

The **FILE_ID_GLOBAL_TX_DIR_INFORMATION** structure can be implemented for file systems that return the FILE_SUPPORTS_TRANSACTIONS flag in response to a query using a [FILE_FS_ATTRIBUTE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_attribute_information) structure. It must not be implemented for file systems that do not return that flag.

If the FILE_ID_GLOBAL_TX_DIR_INFO_FLAG_WRITELOCKED flag is not set in **TxInfoFlags**, **LockingTransactionId** is ignored.