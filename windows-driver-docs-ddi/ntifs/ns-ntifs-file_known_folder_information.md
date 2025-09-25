## Description

The **FILE_KNOWN_FOLDER_INFORMATION** structure contains information about a known folder (for example, *Documents*, *Downloads*, *Pictures*, and so forth).

## Members

### `Type`

A [**FILE_KNOWN_FOLDER_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-file_known_folder_type) value that identifies the known folder.

## Remarks

When a function is called to set or query information for a file object with a [**FILE_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_file_information_class) value of **FileKnownFolderInformation**, that function’s **FileInformation** parameter points to a caller-allocated **FILE_KNOWN_FOLDER_INFORMATION** structure. The **See Also** section lists a few such set/query functions.

## See also

[**FILE_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_file_information_class)

[**FILE_KNOWN_FOLDER_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-file_known_folder_type)

[**NtQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)

[**NtSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)

[**ZwQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwqueryinformationfile)

[**ZwSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwsetinformationfile)