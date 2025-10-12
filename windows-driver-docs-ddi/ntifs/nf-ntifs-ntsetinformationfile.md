# NtSetInformationFile function

## Description

The **NtSetInformationFile** routine changes various kinds of information about a file object.

## Parameters

### `FileHandle` [in]

Handle to the file object. This handle is created by a successful call to [**NtCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) or [**NtOpenFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenfile).

### `IoStatusBlock` [out]

Pointer to an [**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that receives the final completion status and information about the requested operation. The **Information** member receives the number of bytes set on the file.

### `FileInformation` [in]

Pointer to a buffer that contains the information to set for the file. The particular structure in this buffer is determined by the **FileInformationClass** parameter. For example, if the **FileInformationClass** parameter is set to the **FileDispositionInformationEx** constant, this parameter should be a pointer to a [**FILE_DISPOSITION_INFORMATION_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_disposition_information_ex) structure.

### `Length` [in]

The size, in bytes, of the **FileInformation** buffer.

### `FileInformationClass` [in]

The type of information, supplied in the buffer pointed to by **FileInformation**, to set for the file. Device and intermediate drivers can specify any of the following [**FILE_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_file_information_class) values.

|FILE_INFORMATION_CLASS value|Type of information returned|
|----|----|
| **FileBasicInformation** (4) | Change the information that is supplied in a [**FILE_BASIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_basic_information) structure. The caller must have opened the file with the FILE_WRITE_ATTRIBUTES flag set in the **DesiredAccess** parameter. |
| **FileRenameInformation** (10) | Change the current file name, which is supplied in a [**FILE_RENAME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_rename_information) structure. The caller must have DELETE access to the file. |
| **FileDispositionInformation** (13) | Request to delete the file when it is closed or cancel a previously requested deletion. The choice whether to delete or cancel is supplied in a [**FILE_DISPOSITION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_disposition_information) structure. The caller must have opened the file with the DELETE flag set in the **DesiredAccess** parameter. |
| **FilePositionInformation** (14) | Change the current file information, which is stored in a [**FILE_POSITION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_position_information) structure. |
| **FileEndOfFileInformation** (20) | Change the current end-of-file information, supplied in a [**FILE_END_OF_FILE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_end_of_file_information) structure. The operation can either truncate or extend the file. The caller must have opened the file with the FILE_WRITE_DATA flag set in the **DesiredAccess** parameter. |
| **FileValidDataLengthInformation** (39) | Change the current valid data length for the file, which is supplied in a [**FILE_VALID_DATA_LENGTH_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_valid_data_length_information) structure. The file must be on an NTFS volume, and the caller must have opened the file with the FILE_WRITE_DATA flag set in the **DesiredAccess** parameter. Non-administrators and remote users must have the **SeManageVolumePrivilege** privilege. |
| **FileShortNameInformation** (40) | Change the current short file name, which is supplied in a [**FILE_NAME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_name_information) structure. The file must be on an NTFS volume, and the caller must have opened the file with the **DesiredAccess** DELETE flag set in the **DesiredAccess** parameter. |
| **FileIoPriorityHintInformation** (43) | Change the current default IRP priority hint for the file handle. The new value is supplied in a [**FILE_IO_PRIORITY_HINT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_io_priority_hint_information) structure. This structure must be 8-byte aligned. |
| **FileReplaceCompletionInformation** (61) | Change or remove the I/O completion port for the specified file handle. The caller supplies a pointer to a [**FILE_COMPLETION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_completion_information) structure that specifies a port handle and a completion key. If the port handle is non-NULL, this handle specifies a new I/O completion port to associate with the file handle. To remove the I/O completion port associated with the file handle, set the port handle in the structure to NULL. To get a port handle, a user-mode caller can call the [**CreateIoCompletionPort**](https://learn.microsoft.com/windows/desktop/FileIO/createiocompletionport) function. |
| **FileDispositionInformationEx** (64) | Request to delete the file or cancel a previously requested deletion. The choice whether to delete or cancel, as well as settings for when and how the deletion should be performed, are supplied in a [**FILE_DISPOSITION_INFORMATION_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_disposition_information_ex) structure. The caller must have opened the file with the DELETE flag set in the **DesiredAccess** parameter. |
| **FileCaseSensitiveInformation** (71) | Change the information that is supplied in a [**FILE_CASE_SENSITIVE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_case_sensitive_information) structure. The caller must have opened the file with the FILE_WRITE_ATTRIBUTES flag set in the **DesiredAccess** parameter. This value is available starting with Windows 10, version 1803. |
| **FileLinkInformation** (72) | Create a hard link to an existing file, which is specified in a [**FILE_LINK_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_link_information) structure. Not all file systems support hard links; for example NTFS does while FAT does not. |
| **FileCaseSensitiveInformationForceAccessCheck** (75) | Change the information that is supplied in a [**FILE_CASE_SENSITIVE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_case_sensitive_information) structure. The caller must have opened the file with the FILE_WRITE_ATTRIBUTES flag set in the **DesiredAccess** parameter. This is a special version of the FileCaseSensitiveInformation operation that is used to force the IOManager to perform access checks for the kernel-mode driver, similar to the checks that apply to a user-mode caller. This operation is only recognized by the IOManager and a file system should never receive it. This value is available starting with Windows 10, version 1803. |
| **FileKnownFolderInformation** (76) | A [**FILE_KNOWN_FOLDER_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_known_folder_information) structure. Available starting in Windows Server 2022. |

## Return value

**NtSetInformationFile** returns STATUS_SUCCESS or an appropriate error status.

## Remarks

**NtSetInformationFile** changes information about a file. It ignores any member of a **FILE_**XXX**_INFORMATION** structure that is not supported by a particular device or file system.

If you set **FileInformationClass** to **FileDispositionInformation**, you can subsequently pass **FileHandle** to [**NtClose**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) but not to any other **Zw**Xxx**File** routine. Because **FileDispositionInformation** causes the file to be marked for deletion, it is a programming error to attempt any subsequent operation on the handle other than closing it.

If you set **FileInformationClass** to **FilePositionInformation**, and the preceding call to **NtCreateFile** included the FILE_NO_INTERMEDIATE_BUFFERING flag in the **CreateOptions** parameter, certain restrictions on the **CurrentByteOffset** member of the [**FILE_POSITION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_position_information) structure are enforced. For more information, see [**NtCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile).

If you set **FileInformationClass** to **FileEndOfFileInformation**, and the **EndOfFile** member of [**FILE_END_OF_FILE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_end_of_file_information) specifies an offset beyond the current end-of-file mark, **NtSetInformationFile** extends the file and pads the extension with zeros.

For more information about working with files, see [Using Files in a Driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-files-in-a-driver).

Callers of **NtSetInformationFile** must be running at IRQL = PASSIVE_LEVEL and [with special kernel APCs enabled](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

> [!NOTE]
>
> If the call to this function occurs in user mode, use the name "**NtSetInformationFile**" instead of "**ZwSetInformationFile**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**CreateIoCompletionPort**](https://learn.microsoft.com/windows/desktop/FileIO/createiocompletionport)

[**FILE_BASIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_basic_information)

[**FILE_COMPLETION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_completion_information)

[**FILE_DISPOSITION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_disposition_information)

[**FILE_END_OF_FILE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_end_of_file_information)

[**FILE_IO_PRIORITY_HINT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_io_priority_hint_information)

[**FILE_LINK_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_link_information)

[**FILE_NAME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_name_information)

[**FILE_POSITION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_position_information)

[**FILE_RENAME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_rename_information)

[**FILE_VALID_DATA_LENGTH_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_valid_data_length_information)

[**ZwClose**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)

[**ZwOpenFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenfile)

[**ZwQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)