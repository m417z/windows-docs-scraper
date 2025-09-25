# FILE_ALLOCATION_INFORMATION structure

## Description

The **FILE_ALLOCATION_INFORMATION** structure is used to set the allocation size for a file.

## Members

### `AllocationSize`

File allocation size, in bytes. Usually this value is a multiple of the sector or cluster size of the underlying physical device.

## Remarks

This operation can be performed in either of the following ways:

* Call [**FltSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetinformationfile) or [**ZwSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile), passing FileAllocationInformation as the value of **FileInformationClass** and passing a caller-allocated, FILE_ALLOCATION_INFORMATION-structured buffer as the value of **FileInformation**. The **FileHandle** parameter specifies the file whose allocation size is to be set.

* Create an IRP with major function code IRP_MJ_SET_INFORMATION.

This operation is valid only for files. It is undefined for directories.

File system minifilters must use [**FltSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetinformationfile), not [**ZwSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile), to set the allocation size for a file.

FILE_WRITE_DATA access is required to set this information.

A file's allocation size and end-of-file position are independent of each other, with the following exception: The end-of-file position must always be less than or equal to the allocation size. If the allocation size is set to a value that is less than the end-of-file position, the end-of-file position is automatically adjusted to match the allocation size.

The size of the **FileInformation** buffer passed to [**FltSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetinformationfile) or [**ZwSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile) must be >= ```sizeof(FILE_ALLOCATION_INFORMATION)```.

This structure must be aligned on a LONGLONG (8-byte) boundary.

## See also

[**FILE_END_OF_FILE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_end_of_file_information)

[**FltSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetinformationfile)

[**IRP_MJ_SET_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-information)

[**ZwSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)