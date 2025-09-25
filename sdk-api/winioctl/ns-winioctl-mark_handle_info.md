# MARK_HANDLE_INFO structure

## Description

Contains information that is used to mark a specified file or directory, and its update sequence
number (USN) change journal record with data about changes. It is used by the
[FSCTL_MARK_HANDLE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_mark_handle) control code.

## Members

### `DUMMYUNIONNAME`

### `UsnSourceInfo`

The type of changes being made.

The operation does not modify the file or directory externally from the point of view of the application that
created it.

When a thread writes a new USN record, the source information flags in the prior record continues to be
present only if the thread also sets those flags. Therefore, the source information structure allows
applications to filter out USN records that are set only by a known source, such as an antivirus filter.

The following values are defined.

| Value | Meaning |
| --- | --- |
| **USN_SOURCE_DATA_MANAGEMENT**<br><br>0x00000001 | The operation provides information about a change to the file or directory made by the operating system.<br><br>A typical use is when Remote Storage moves data from external to local storage. Remote Storage is the hierarchical storage management software. Such a move usually at a minimum adds the **USN_REASON_DATA_OVERWRITE** flag to a USN record. However, the data has not changed from the user point of view. By noting **USN_SOURCE_DATA_MANAGEMENT** in the **SourceInfo** member of the [USN_RECORD](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v2) structure that holds the record, you can determine that although a write operation is performed on the item, data has not changed. |
| **USN_SOURCE_AUXILIARY_DATA**<br><br>0x00000002 | The operation adds a private data stream to a file or directory.<br><br>An example might be a virus detector adding checksum information. As the virus detector modifies the item, the system generates USN records. **USN_SOURCE_AUXILIARY_DATA** indicates that the modifications did not change the application data. |
| **USN_SOURCE_REPLICATION_MANAGEMENT**<br><br>0x00000004 | The operation creates or updates the contents of a replicated file.<br><br>For example, the file replication service sets this flag when it creates or updates a file in a replicated directory. |

| **USN_SOURCE_CLIENT_REPLICATION_MANAGEMENT**<br><br>0x00000008 | Replication is being performed on client systems either from the cloud or servers. |

### `CopyNumber`

The zero-based copy number to use for subsequent reads. This is for use on Storage Spaces and Streams on
NTFS and ReFS and non-integrity streams on ReFS (streams with integrity on ReFS handle this automatically.)

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This member is not supported before Windows 8 and Windows Server 2012.

### `VolumeHandle`

The volume handle to the volume where the file or directory resides. For more information on obtaining a
volume handle, see the Remarks section.

This handle is required to check the privileges for this operation.

The caller must have the **SE_MANAGE_VOLUME_NAME** privilege. For more information, see
[Privileges](https://learn.microsoft.com/windows/desktop/SecAuthZ/privileges).

### `HandleInfo`

The flag that specifies additional information about the file or directory identified by the handle value
in the **VolumeHandle** member.

| Value | Meaning |
| --- | --- |
| **MARK_HANDLE_PROTECT_CLUSTERS**<br><br>0x00000001 | The file is marked as unable to be defragmented until the handle is closed.<br><br>Once a handle marked **MARK_HANDLE_PROTECT_CLUSTERS** is closed, there is no guarantee that the file's clusters won't move. |
| **MARK_HANDLE_TXF_SYSTEM_LOG**<br><br>0x00000004 | The file is marked as unable to be defragmented until the handle is closed.<br><br>**Windows Server 2003:** This flag is not supported until Windows Server 2003 with SP1.<br><br>**Windows XP:** This flag is not supported. |
| **MARK_HANDLE_NOT_TXF_SYSTEM_LOG**<br><br>0x00000008 | The file is marked as unable to be defragmented until the handle is closed.<br><br>**Windows Server 2003:** This flag is not supported until Windows Server 2003 with SP1.<br><br>**Windows XP:** This flag is not supported. |
| **MARK_HANDLE_REALTIME**<br><br>0x00000020 | The file is marked for real-time read behavior regardless of the actual file type. Files marked with this flag must be opened for [unbuffered I/O](https://learn.microsoft.com/windows/desktop/FileIO/file-buffering).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **MARK_HANDLE_NOT_REALTIME**<br><br>0x00000040 | The file previously marked for real-time read behavior using the **MARK_HANDLE_REALTIME** flag can be unmarked using this flag, removing the real-time behavior. Files marked with this flag must be opened for [unbuffered I/O](https://learn.microsoft.com/windows/desktop/FileIO/file-buffering).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **MARK_HANDLE_READ_COPY**<br><br>0x00000080 | Indicates the copy number specified in the **CopyNumber** member should be used for reads. Files marked with this flag must be opened for [unbuffered I/O](https://learn.microsoft.com/windows/desktop/FileIO/file-buffering).<br><br>**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported until Windows 8 and Windows Server 2012. |
| **MARK_HANDLE_NOT_READ_COPY**<br><br>0x00000100 | The file previously marked for read-copy behavior using the **MARK_HANDLE_READ_COPY** flag can be unmarked using this flag, removing the read-copy behavior. Files marked with this flag must be opened for [unbuffered I/O](https://learn.microsoft.com/windows/desktop/FileIO/file-buffering).<br><br>**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported until Windows 8 and Windows Server 2012. |

| **MARK_HANDLE_RETURN_PURGE_FAILURE**<br><br>0x00000400 | When intermixing memory mapped/cached IO with non-cached IO the system attempts, when a non-cached io is issued, to purge memory mappings for the range of the non-cached IO. If these purges fail the system normally does not return the failure to the caller which can lead to corrupted state (which is why the documentation says to not do this). This flag tells the system to return purge failures for the given handle so the application can better handle this situation<br><br>This flag is not supported until Windows 8 and Windows Server 2012. |

| **MARK_HANDLE_DISABLE_FILE_METADATA_OPTIMIZATION**<br><br>0x00001000 | A highly fragmented file in NTFS uses multiple MFT records to describe all of the extents for a file. This list of child MFT records (also known as FRS records) are controlled by a structure known as an attribute list. An attribute list is limited to 128K in size. When the size of an attribute list hits a certain threshold NTFS will trigger a background compaction on the extents so the minimum number of child FRS records will be used. This flag disables this FRS compaction feature for the given file.<br><br>This flag is not supported until Windows 10. |

| **MARK_HANDLE_ENABLE_USN_SOURCE_ON_PAGING_IO**<br><br>0x00002000 | Tells NTFS to set the given UsnSourceInfo value on Paging writes in the USN Journal. Traditionally this was not done on paging writes since the system did not know what thread made the given changes. This is an override. This only works if the FileObject the memory manager is using has this state associated with it.<br><br>This flag is not supported until Windows 10. |

| **MARK_HANDLE_SKIP_COHERENCY_SYNC_DISALLOW_WRITES**<br><br>0x00004000 | Setting this flag tells the system that writes are not allowed on this file. If an application tries to open the file for write access, the operation is failed with STATUS_ACCESS_DENIED. If a write is seen the operation is failed with STATUS_MARKED_TO_DISALLOW_WRITES<br><br>This flag is not supported until Windows 10. |

## Remarks

To retrieve a handle to a volume, call
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) with the
*lpFileName* parameter set to a string in the following form:

"\\.\*X*:"

In the preceding string, *X* is the letter identifying the drive on which the volume
appears.

## See also

[FSCTL_MARK_HANDLE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_mark_handle)

[USN_RECORD](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v2)