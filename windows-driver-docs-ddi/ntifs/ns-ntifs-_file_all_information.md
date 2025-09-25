# _FILE_ALL_INFORMATION structure

## Description

The **FILE_ALL_INFORMATION** structure is a container for several **FILE_*XXX*_INFORMATION** structures.

## Members

### `BasicInformation`

Contains basic information about the file, which includes the file attributes and the file creation time. This member is a [FILE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_basic_information) structure.

### `StandardInformation`

Contains standard information about a file, which includes the file allocation size, the end-of-file offset, and whether the file is a directory. This member is a [FILE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_standard_information) structure.

### `InternalInformation`

Contains the 8-byte file reference number for the file. This member is a [FILE_INTERNAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_internal_information) structure.

### `EaInformation`

Specifies the size of the extended attributes of the file. This member is a [FILE_EA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_ea_information) structure.

### `AccessInformation`

Specifies the client's access rights to the file. This member is a [FILE_ACCESS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_access_information) structure.

### `PositionInformation`

Specifies the current file position. This member is a [FILE_POSITION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_position_information) structure.

### `ModeInformation`

Specifies the access mode in which the file was created or opened. This member is a [FILE_MODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_mode_information) structure.

### `AlignmentInformation`

Specifies the device's memory address alignment requirement for data transfers. This member is a [FILE_ALIGNMENT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_alignment_information) structure.

### `NameInformation`

Contains the file name. This member is a [FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_name_information) structure. This structure contains the first character in the file name string. The additional characters in the file name string immediately follow the structure. To accommodate the full file name, the buffer that is allocated to contain a **FILE_ALL_INFORMATION** structure must be large enough to contain both the structure and the part of the file name string that follows the structure.

## Remarks

This structure is used by the [ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile) routine.

**FILE_ALL_INFORMATION** combines several file-information structures into a single structure to reduce the number of queries that are required to obtain information about a file.

## See also

[FILE_ACCESS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_access_information)

[FILE_ALIGNMENT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_alignment_information)

[FILE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_basic_information)

[FILE_EA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_ea_information)

[FILE_INTERNAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_internal_information)

[FILE_MODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_mode_information)

[FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_name_information)

[FILE_POSITION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_position_information)

[FILE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_standard_information)

[ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)