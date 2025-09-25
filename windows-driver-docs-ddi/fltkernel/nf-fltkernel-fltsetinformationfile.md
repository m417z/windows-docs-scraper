# FltSetInformationFile function

## Description

**FltSetInformationFile** sets information for a given file.

## Parameters

### `Instance` [in]

Opaque instance pointer for the caller. This parameter is required and cannot be **NULL**.

### `FileObject` [in]

File object pointer for the file. This parameter is required and cannot be **NULL**.

### `FileInformation` [in]

Pointer to a caller-allocated buffer that contains information to be set for the file. The *FileInformationClass* parameter specifies the type of information. This parameter is required and cannot be **NULL**.

### `Length` [in]

Size, in bytes, of the *FileInformation* buffer.

### `FileInformationClass` [in]

Specifies the type of information to be set for the file. The following values are defined.

| Value | Meaning |
| --- | --- |
| **FileAllocationInformation** | Set [FILE_ALLOCATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_allocation_information) for the file. |
| **FileBasicInformation** | Set [FILE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_basic_information) for the file. |
| **FileDispositionInformation** | Set [FILE_DISPOSITION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_disposition_information) for the file. |
| **FileEndOfFileInformation** | Set [FILE_END_OF_FILE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_end_of_file_information) for the file. |
| **FileLinkInformation** | Set [FILE_LINK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_link_information) for the file. |
| **FilePositionInformation** | Set [FILE_POSITION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_position_information) for the file. |
| **FileRenameInformation** | Set [FILE_RENAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_rename_information) for the file. For more information about file renaming, see the following Remarks section. |
| **FileValidDataLengthInformation** | Set [FILE_VALID_DATA_LENGTH_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_valid_data_length_information) for the file. |

## Return value

**FltSetInformationFile** returns STATUS_SUCCESS or an appropriate NTSTATUS value.

## Remarks

A minifilter driver calls **FltSetInformationFile** to set information for a given file. The file must currently be open.

A file rename operation imposes the following restriction on the parameter values passed to **FltSetInformationFile**: As noted in the reference entry for [FILE_RENAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_rename_information), a file or directory can only be renamed within a volume. In other words, a rename operation cannot cause a file or directory to be moved to a different volume. Unlike [ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile), **FltSetInformationFile** does not validate the contents of the FILE_RENAME_INFORMATION structure. Thus the caller of **FltSetInformationFile** is responsible for ensuring that the new name for the file or directory is on the same volume as the old name.

Minifilter drivers must use **FltSetInformationFile** , not [ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile), to rename a file.

## See also

[FILE_ALLOCATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_allocation_information)

[FILE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_basic_information)

[FILE_DISPOSITION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_disposition_information)

[FILE_END_OF_FILE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_end_of_file_information)

[FILE_LINK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_link_information)

[FILE_POSITION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_position_information)

[FILE_RENAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_rename_information)

[FILE_VALID_DATA_LENGTH_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_valid_data_length_information)

[FltQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryinformationfile)

[FltQueryVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformationfile)

[ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)