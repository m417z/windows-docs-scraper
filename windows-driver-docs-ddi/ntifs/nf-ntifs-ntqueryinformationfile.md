# NtQueryInformationFile function

## Description

The **NtQueryInformationFile** routine returns various kinds of information about a file object. See also [**NtQueryInformationByName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationbyname), which can be more efficiently used for a few file information classes.

## Parameters

### `FileHandle` [in]

Handle to a file object. The handle is created by a successful call to [**NtCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) or [**NtOpenFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenfile), or to an equivalent file create or open routine.

### `IoStatusBlock` [out]

Pointer to an [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that receives the final completion status and information about the operation. The **Information** member receives the number of bytes that this routine actually writes to the *FileInformation* buffer.

### `FileInformation` [out]

Pointer to a caller-allocated buffer into which the routine writes the requested information about the file object. The *FileInformationClass* parameter specifies the type of information that the caller requests.

### `Length` [in]

The size, in bytes, of the buffer pointed to by *FileInformation*.

### `FileInformationClass` [in]

Specifies the type of information to be returned about the file, in the buffer that *FileInformation* points to. Device and intermediate drivers can specify any of the following [FILE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_file_information_class) values (listed from lowest to highest enum value):

|FILE_INFORMATION_CLASS value|Type of information returned|
|----|----|
| **FileBasicInformation** (4) | A [FILE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_basic_information) structure. The caller must have opened the file with the FILE_READ_ATTRIBUTES flag specified in the *DesiredAccess* parameter. |
| **FileStandardInformation** (5) | A [FILE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_standard_information) structure. The caller can query this information as long as the file is open, without any particular requirements for *DesiredAccess*. |
| **FileInternalInformation** (6) | A [FILE_INTERNAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_internal_information) structure. This structure specifies a 64-bit file ID that uniquely identifies a file in NTFS. On other file systems, this file ID is not guaranteed to be unique. |
| **FileEaInformation** (7) | A [FILE_EA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_ea_information) structure. This structure specifies the size of the extended attributes block that is associated with the file. |
|**FileAccessInformation** (8) |A [FILE_ACCESS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_access_information) structure. This structure contains an access mask. For more information about access masks, see [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask).|
| **FileNameInformation** (9) | A [FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_name_information) structure. The structure can contain the file's full path or only a portion of it. The caller can query this information as long as the file is open, without any particular requirements for *DesiredAccess*. For more information about the file-name syntax, see the Remarks section later in this topic. |
| **FilePositionInformation** (14) | A [FILE_POSITION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_position_information) structure. The caller must have opened the file with the *DesiredAccess* FILE_READ_DATA or FILE_WRITE_DATA flag specified in the *DesiredAccess* parameter, and with the FILE_SYNCHRONOUS_IO_ALERT or FILE_SYNCHRONOUS_IO_NONALERT flag specified in the *CreateOptions* parameter. |
| **FileModeInformation** (16) | A [FILE_MODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_mode_information) structure. This structure contains a set of flags that specify the mode in which the file can be accessed. These flags are a subset of the options that can be specified in the *CreateOptions* parameter of the [**IoCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatefile) routine. |
| **FileAlignmentInformation** (17) | A [FILE_ALIGNMENT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_alignment_information) structure. The caller can query this information as long as the file is open, without any particular requirements for *DesiredAccess*. This information is useful if the file was opened with the FILE_NO_INTERMEDIATE_BUFFERING flag specified in the *CreateOptions* parameter. |
| **FileAllInformation** (18) | A [FILE_ALL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_all_information) structure. By combining several file-information structures into a single structure, **FILE_ALL_INFORMATION** reduces the number of queries required to obtain information about a file. |
| **FileAlternateNameInformation** (21) | A [FILE_ALL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_all_information) structure in which to return the alternate name information for a file (its 8.3 format name). |
| **FileStreamInformation** (22) | A buffer of [FILE_STREAM_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_stream_information) structures in which to enumerate the data streams of a file or a directory. |
| **FileCompressionInformation** (28) | A [FILE_COMPRESSION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_compression_information) structure in which to return compression information for a file. |
| **FileNetworkOpenInformation** (34) | A [FILE_NETWORK_OPEN_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_network_open_information) structure. The caller must have opened the file with the FILE_READ_ATTRIBUTES flag specified in the *DesiredAccess* parameter. |
| **FileAttributeTagInformation** (35) | A [FILE_ATTRIBUTE_TAG_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_attribute_tag_information) structure. The caller must have opened the file with the FILE_READ_ATTRIBUTES flag specified in the *DesiredAccess* parameter. |
| **FileIoPriorityHintInformation** (43) | A [FILE_IO_PRIORITY_HINT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_io_priority_hint_information) structure. The caller must have opened the file with the FILE_READ_DATA flag specified in the *DesiredAccess* parameter. |
| **FileSfioReserveInformation** (44) | A [FILE_SFIO_RESERVE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-file_sfio_reserve_information) structure. |
| **FileHardLinkInformation** (46) | A [FILE_LINKS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_links_information) structure. |
| **FileNormalizedNameInformation** (48) | A [FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_name_information) structure in which to return the normalized name of a file. |
| **FileIsRemoteDeviceInformation** (51) | A [FILE_IS_REMOTE_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_is_remote_device_information) structure. The caller can query this information as long as the file is open, without any particular requirements for *DesiredAccess*. |
| **FileStandardLinkInformation** (54) | A [FILE_STANDARD_LINK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_standard_link_information) structure. |
| **FileIdInformation** (59) | A [FILE_ID_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_id_information) structure. |
| **FileDesiredStorageClassInformation** (67) | A [FILE_DESIRED_STORAGE_CLASS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_desired_storage_class_information) structure. |
| **FileStatInformation** (68) | [FILE_STAT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_stat_information) |
| **FileStatLxInformation** (70) | [FILE_STAT_LX_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_stat_lx_information) |
| **FileCaseSensitiveInformation** (71) | A [FILE_CASE_SENSITIVE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_case_sensitive_information) structure. The caller must have opened the file with the FILE_READ_ATTRIBUTES flag specified in the *DesiredAccess* parameter. This value is available starting with Windows 10, version 1803. |
| **FileStorageReserveIdInformation** (74) | A [FILE_STORAGE_RESERVE_ID_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_storage_reserve_id_information) structure. |
| **FileCaseSensitiveInformationForceAccessCheck** (75) | A [FILE_CASE_SENSITIVE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_case_sensitive_information) structure. The caller must have opened the file with the FILE_READ_ATTRIBUTES flag specified in the *DesiredAccess* parameter. This is a special version of the FileCaseSensitiveInformation operation that is used to force the IOManager to perform access checks for the kernel-mode driver, similar to the checks that apply to a user-mode caller. This operation is only recognized by the IOManager and a file system should never receive it. This value is available starting with Windows 10, version 1803. |
| **FileKnownFolderInformation** (76) | A [**FILE_KNOWN_FOLDER_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_known_folder_information) structure. Available starting in Windows Server 2022. |

## Return value

**NtQueryInformationFile** returns STATUS_SUCCESS or an appropriate NTSTATUS error code.

## Remarks

**NtQueryInformationFile** returns information about the specified file object. Note that it returns zero in any member of a **FILE_*XXX*_INFORMATION** structure that is not supported by a particular device or file system.

When *FileInformationClass* = **FileNameInformation**, the file name is returned in the [FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_name_information) structure. The precise syntax of the file name depends on a number of factors:

* If you opened the file by submitting a full path to [**NtCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile), **NtQueryInformationFile** returns that full path.

* If the **ObjectAttributes->RootDirectory** handle was opened by name in a call to **NtCreateFile**, and subsequently the file was opened by **NtCreateFile** relative to this root-directory handle, **NtQueryInformationFile** returns the full path.

* If the **ObjectAttributes->RootDirectory** handle was opened by file ID (using the FILE_OPEN_BY_FILE_ID flag) in a call to **NtCreateFile**, and subsequently the file was opened by **NtCreateFile** relative to this root-directory handle, **NtQueryInformationFile** returns the relative path.

* However, if the user has **SeChangeNotifyPrivilege** (described in the Microsoft Windows SDK documentation), **NtQueryInformationFile** returns the full path in all cases.

* If only the relative path is returned, the file name string will not begin with a backslash.

* If the full path and file name are returned, the string will begin with a single backslash, regardless of its location. Thus the file C:\dir1\dir2\filename.ext will appear as \dir1\dir2\filename.ext, while the file \\server\share\dir1\dir2\filename.ext will appear as \server\share\dir1\dir2\filename.ext.

If **NtQueryInformationFile** fails because of a buffer overflow, drivers that implement **FileNameInformation** should return as many WCHAR characters of the file name as will fit in the buffer and specify the full length that is required in the *FileNameLength* parameter of the [FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_name_information) structure. You should reissue the query by using the file name length so that you can retrieve the full file name. Drivers that do not follow this pattern might require a gradual increase in length until they retrieve the full file name. For more information about working with files, see [Using Files in a Driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-files-in-a-driver).

Callers of **NtQueryInformationFile** must be running at IRQL = PASSIVE_LEVEL and [with special kernel APCs enabled](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

> [!NOTE]
> If the call to this function occurs in user mode, you should use the name "**NtQueryInformationFile**" instead of "**ZwQueryInformationFile**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[FILE_ACCESS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_access_information)

[FILE_ALIGNMENT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_alignment_information)

[FILE_ALL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_all_information)

[FILE_ATTRIBUTE_TAG_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_attribute_tag_information)

[FILE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_basic_information)

[FILE_EA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_ea_information)

[FILE_INTERNAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_internal_information)

[FILE_IO_PRIORITY_HINT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_io_priority_hint_information)

[FILE_IS_REMOTE_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_is_remote_device_information)

[FILE_MODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_mode_information)

[FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_name_information)

[FILE_NETWORK_OPEN_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_network_open_information)

[FILE_POSITION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_position_information)

[FILE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_standard_information)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[**NtCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)

[**NtQueryInformationByName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationbyname)

[**NtSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)