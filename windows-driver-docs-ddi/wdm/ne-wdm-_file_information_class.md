## Description

A **FILE_INFORMATION_CLASS** value specifies which structure to use to query or set information for a file object.

## Constants

### `FileDirectoryInformation:1`

A [**FILE_DIRECTORY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_directory_information) structure.

### `FileFullDirectoryInformation:2`

A [**FILE_FULL_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_full_dir_information) structure.

### `FileBothDirectoryInformation:3`

A [**FILE_BOTH_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_both_dir_information) structure.

### `FileBasicInformation:4`

A [**FILE_BASIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_basic_information) structure.

### `FileStandardInformation:5`

A [**FILE_STANDARD_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_standard_information) structure.

### `FileInternalInformation:6`

A [**FILE_INTERNAL_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_internal_information) structure.

### `FileEaInformation:7`

A [**FILE_EA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_ea_information) structure.

### `FileAccessInformation:8`

A [**FILE_ACCESS_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_access_information) structure.

### `FileNameInformation:9`

A [**FILE_NAME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_name_information) structure.

### `FileRenameInformation:10`

A [**FILE_RENAME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_rename_information) structure.

### `FileLinkInformation:11`

A [**FILE_LINK_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_link_information) structure.

### `FileNamesInformation:12`

A [**FILE_NAMES_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_names_information) structure.

### `FileDispositionInformation:13`

A [**FILE_DISPOSITION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_disposition_information) structure.

### `FilePositionInformation:14`

A [**FILE_POSITION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_position_information) structure.

### `FileFullEaInformation:15`

A [**FILE_FULL_EA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_full_ea_information) structure.

### `FileModeInformation:16`

A [**FILE_MODE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_mode_information) structure.

### `FileAlignmentInformation:17`

A [**FILE_ALIGNMENT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_alignment_information) structure.

### `FileAllInformation:18`

A [**FILE_ALL_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_all_information) structure.

### `FileAllocationInformation:19`

A [**FILE_ALLOCATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_allocation_information) structure.

### `FileEndOfFileInformation:20`

A [**FILE_END_OF_FILE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_end_of_file_information) structure.

### `FileAlternateNameInformation:21`

A [**FILE_NAME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_name_information) structure.

### `FileStreamInformation:22`

A message buffer that contains one or more [**FILE_STREAM_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_stream_information) structures.

### `FilePipeInformation:23`

A [**FILE_PIPE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_pipe_information) structure.

### `FilePipeLocalInformation:24`

A [**FILE_PIPE_LOCAL_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_pipe_local_information) structure.

### `FilePipeRemoteInformation:25`

A [**FILE_PIPE_REMOTE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_pipe_remote_information) structure.

### `FileMailslotQueryInformation:26`

A [**FILE_MAILSLOT_QUERY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_mailslot_query_information) structure.

### `FileMailslotSetInformation:27`

A [**FILE_MAILSLOT_SET_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_mailslot_set_information) structure.

### `FileCompressionInformation:28`

A [**FILE_COMPRESSION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_compression_information) structure.

### `FileObjectIdInformation:29`

A [**FILE_OBJECTID_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_objectid_information) structure.

### `FileCompletionInformation:30`

This value is reserved for system use.

### `FileMoveClusterInformation:31`

This value is reserved for system use.

### `FileQuotaInformation:32`

A [**FILE_QUOTA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_quota_information) structure.

### `FileReparsePointInformation:33`

A [**FILE_REPARSE_POINT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_reparse_point_information) structure.

### `FileNetworkOpenInformation:34`

A [**FILE_NETWORK_OPEN_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_network_open_information) structure.

### `FileAttributeTagInformation:35`

A [**FILE_ATTRIBUTE_TAG_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_attribute_tag_information) structure.

### `FileTrackingInformation:36`

This value is reserved for system use.

### `FileIdBothDirectoryInformation:37`

A [**FILE_ID_BOTH_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_id_both_dir_information) structure.

### `FileIdFullDirectoryInformation:38`

A [**FILE_ID_FULL_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_id_full_dir_information) structure.

### `FileValidDataLengthInformation:39`

A [**FILE_VALID_DATA_LENGTH_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_valid_data_length_information) structure.

### `FileShortNameInformation:40`

A [**FILE_NAME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_name_information) structure.

### `FileIoCompletionNotificationInformation:41`

This value is reserved for system use. This value is available starting with Windows Vista.

### `FileIoStatusBlockRangeInformation:42`

This value is reserved for system use. This value is available starting with Windows Vista.

### `FileIoPriorityHintInformation:43`

A [**FILE_IO_PRIORITY_HINT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_io_priority_hint_information) structure. This value is available starting with Windows Vista.

### `FileSfioReserveInformation:44`

This value is reserved for system use. This value is available starting with Windows Vista.

### `FileSfioVolumeInformation:45`

This value is reserved for system use. This value is available starting with Windows Vista.

### `FileHardLinkInformation:46`

A [**FILE_LINKS_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_links_information) structure. This value is available starting with Windows Vista.

### `FileProcessIdsUsingFileInformation:47`

A **FILE_PROCESS_IDS_USING_FILE_INFORMATION** structure. This value is reserved for system use. This value is available starting with Windows Vista.

### `FileNormalizedNameInformation:48`

A [**FILE_NAME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_name_information) structure. This value is defined starting with Windows Vista. It is supported starting with Windows 8.

### `FileNetworkPhysicalNameInformation:49`

A [**FILE_NETWORK_PHYSICAL_NAME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_network_physical_name_information) structure. This value is available starting with Windows Vista.

### `FileIdGlobalTxDirectoryInformation:50`

A [**FILE_ID_GLOBAL_TX_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_id_global_tx_dir_information) structure. This value is available starting with Windows 7.

### `FileIsRemoteDeviceInformation:51`

A **FILE_IS_REMOTE_DEVICE_INFORMATION** structure. This value is reserved for system use. This value is available starting with Windows 7.

### `FileUnusedInformation:52`

This value is reserved for system use. This value is available starting with Windows 7.

### `FileNumaNodeInformation:53`

A **FILE_NUMA_NODE_INFORMATION** structure. This value is reserved for system use. This value is available starting with Windows 7.

### `FileStandardLinkInformation:54`

A **FILE_STANDARD_LINK_INFORMATION** structure. This value is reserved for system use. This value is available starting with Windows 7.

### `FileRemoteProtocolInformation:55`

A [**FILE_REMOTE_PROTOCOL_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_remote_protocol_information) structure. This value is available starting with Windows 7.

### `FileRenameInformationBypassAccessCheck:56`

A [**FILE_RENAME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_rename_information) structure. This is a special version of the **FileRenameInformation** operation that is used by kernel-mode drivers only in order to bypass security access checks. This operation is only recognized by the *IOManager* and a file system should never receive it. This value is available starting with Windows 10.

### `FileLinkInformationBypassAccessCheck:57`

A [**FILE_LINK_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_link_information) structure. This is a special version of the **FileLinkInformation** operation that is used by kernel-mode drivers only in order to bypass security access checks. This operation is only recognized by the *IOManager* and a file system should never receive it. This value is available starting with Windows 10.

### `FileVolumeNameInformation:58`

A **FILE_VOLUME_NAME_INFORMATION** structure. This value is reserved for system use. This value is available starting with Windows 10.

### `FileIdInformation:59`

A **FILE_ID_INFORMATION** structure. This value is reserved for system use. This value is available starting with Windows 10.

### `FileIdExtdDirectoryInformation:60`

A **FILE_ID_EXTD_DIR_INFORMATION** structure. This value is reserved for system use. This value is available starting with Windows 10.

### `FileReplaceCompletionInformation:61`

A [**FILE_COMPLETION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_completion_information) structure to change or remove the completion port associated with a file handle. This value is available starting with Windows 8.1.

### `FileHardLinkFullIdInformation:62`

A **FILE_LINKS_FULL_ID_INFORMATION** structure. This value is reserved for system use. This value is available starting with Windows 10.

### `FileIdExtdBothDirectoryInformation:63`

A **FILE_ID_EXTD_BOTH_DIR_INFORMATION** structure. This value is reserved for system use. This value is available starting with Windows 10.

### `FileDispositionInformationEx:64`

A [**FILE_DISPOSITION_INFORMATION_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_disposition_information_ex) structure that indicates how the operating system should delete a file. This value is available starting with Windows 10, version 1709.

### `FileRenameInformationEx:65`

A [**FILE_RENAME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_rename_information) structure which contains additional flags. This value is available starting with Windows 10, version 1709.

### `FileRenameInformationExBypassAccessCheck:66`

A [**FILE_RENAME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_rename_information) structure which contains additional flags. This value is available starting with Windows 10, version 1709. This is a special version of the **FileRenameInformation** operation that is used by kernel-mode drivers only in order to bypass security access checks. This operation is only recognized by the *IOManager* and a file system should never receive it.

### `FileDesiredStorageClassInformation:67`

A [**FILE_DESIRED_STORAGE_CLASS_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_file_information_class) structure, declared in ntifs.h. This value is available starting with Windows 10, version 1709.

### `FileStatInformation:68`

A [**FILE_STAT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_stat_information) structure, declared in ntifs.h. This value is available starting with Windows 10, version 1709.

### `FileMemoryPartitionInformation:69`

Reserved. This value is available starting with Windows 10, version 1709.

### `FileStatLxInformation:70`

A [**FILE_STAT_LX_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_stat_lx_information) structure, declared in ntifs.h. This information class is used for fields refer to Linux metadata used/created by the Windows Subsystem for Linux. This value is available starting with Windows 10 April 2018 Update.

### `FileCaseSensitiveInformation:71`

A [**FILE_CASE_SENSITIVE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_case_sensitive_information) structure, declared in ntifs.h. This value is available starting with Windows 10 April 2018 Update.

### `FileLinkInformationEx:72`

A [**FILE_LINK_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_link_information) structure which contains additional flags. This value is available starting with Windows 10, version 1809.

### `FileLinkInformationExBypassAccessCheck:73`

A [**FILE_LINK_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_link_information) structure which contains additional flags. This is a special version of the **FileLinkInformation** operation that is used by kernel-mode drivers only in order to bypass security access checks. This operation is only recognized by the *IOManager* and a file system should never receive it. This value is available starting with Windows 10, version 1809.

### `FileStorageReserveIdInformation:74`

A [**FILE_SET_STORAGE_RESERVE_ID_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_storage_reserve_id_information) structure, declared in ntifs.h. This value is available starting with Windows 10, version 1809.

### `FileCaseSensitiveInformationForceAccessCheck:75`

A [**FILE_CASE_SENSITIVE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_case_sensitive_information) structure, declared in ntifs.h. This is a special version of the **FileCaseSensitiveInformation** operation that is used to force the IOManager to perform access checks for the kernel-mode driver, similar to the checks that apply to a user-mode caller. This operation is only recognized by the IOManager and a file system should never receive it. This value is available starting with Windows 10, version 1809.

### `FileKnownFolderInformation:76`

A [**FILE_KNOWN_FOLDER_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_known_folder_information) structure, declared in ntifs.h. This value is available starting with Windows Server 2022.

### `FileStatBasicInformation:77`

A [**FILE_STAT_BASIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_stat_basic_information) structure, declared in ntifs.h. This value is available starting with Windows 11, build 26048.

### `FileId64ExtdDirectoryInformation:78`

A [**FILE_ID_64_EXTD_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_id_64_extd_dir_information) structure, declared in ntifs.h. This value is available starting with Windows 11, version 23H2.

### `FileId64ExtdBothDirectoryInformation:79`

A [**FILE_ID_64_EXTD_BOTH_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_id_64_extd_both_dir_information) structure, declared in ntifs.h. This value is available starting with Windows 11, version 23H2.

### `FileIdAllExtdDirectoryInformation:80`

A [**FILE_ID_ALL_EXTD_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_id_all_extd_dir_information) structure, declared in ntifs.h. This value is available starting with Windows 11, version 23H2.

### `FileIdAllExtdBothDirectoryInformation:81`

A [**FILE_ID_ALL_EXTD_BOTH_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_id_all_extd_both_dir_information) structure, declared in ntifs.h. This value is available starting with Windows 11, version 23H2.

### `FileMaximumInformation`

Maximum value of this enumeration. This value is available starting with Windows 7.