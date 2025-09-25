# WIN32_STREAM_ID structure

## Description

The **WIN32_STREAM_ID** structure contains stream data.

## Members

### `dwStreamId`

Type of data. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BACKUP_ALTERNATE_DATA**<br><br>0x00000004 | Alternative data streams. This corresponds to the NTFS $DATA stream type on a named data stream. |
| **BACKUP_DATA**<br><br>0x00000001 | Standard data. This corresponds to the NTFS $DATA stream type on the default (unnamed) data stream. |
| **BACKUP_EA_DATA**<br><br>0x00000002 | Extended attribute data. This corresponds to the NTFS $EA stream type. |
| **BACKUP_LINK**<br><br>0x00000005 | Hard link information. This corresponds to the NTFS $FILE_NAME stream type. |
| **BACKUP_OBJECT_ID**<br><br>0x00000007 | Objects identifiers. This corresponds to the NTFS $OBJECT_ID stream type. |
| **BACKUP_PROPERTY_DATA**<br><br>0x00000006 | Property data. |
| **BACKUP_REPARSE_DATA**<br><br>0x00000008 | Reparse points. This corresponds to the NTFS $REPARSE_POINT stream type. |
| **BACKUP_SECURITY_DATA**<br><br>0x00000003 | Security descriptor data. |
| **BACKUP_SPARSE_BLOCK**<br><br>0x00000009 | Sparse file. This corresponds to the NTFS $DATA stream type for a sparse file. |
| **BACKUP_TXFS_DATA**<br><br>0x0000000A | [Transactional NTFS (TxF)](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-portal) data stream. This corresponds to the NTFS $TXF_DATA stream type.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |

### `dwStreamAttributes`

Attributes of data to facilitate cross-operating system transfer. This member can be one or more of the
following values.

| Value | Meaning |
| --- | --- |
| **STREAM_MODIFIED_WHEN_READ** | Attribute set if the stream contains data that is modified when read. Allows the backup application to know that verification of data will fail. |
| **STREAM_CONTAINS_SECURITY** | Stream contains security data (general attributes). Allows the stream to be ignored on cross-operations restore. |

### `Size`

Size of data, in bytes.

### `dwStreamNameSize`

Length of the name of the alternative data stream, in bytes.

### `cStreamName`

Unicode string that specifies the name of the alternative data stream.

## See also

[BackupRead](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupread)

[BackupSeek](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupseek)

[BackupWrite](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupwrite)