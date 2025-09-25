# FILE_REPARSE_POINT_INFORMATION structure

## Description

The **FILE_REPARSE_POINT_INFORMATION** structure is used to query for information about a reparse point.

## Members

### `FileReference`

The 8-byte file reference number for the file. NTFS generates this number and assigns it to the file automatically when the file is created.

### `Tag`

The reparse point tag that indicates the structure of the reparse data. See [About reparse points](https://learn.microsoft.com/windows-hardware/drivers/ifs/reparse-points) for more information about reparse point tags.

## Remarks

This information can be queried in either of the following ways:

* Call [**ZwQueryDirectoryFileEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwquerydirectoryfileex), passing **FileReparsePointInformation** as the value of **FileInformationClass** and passing a caller-allocated, **FILE_REPARSE_POINT_INFORMATION**-structured buffer as the value of **FileInformation**.

* Create an IRP with major function code [**IRP_MJ_DIRECTORY_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-directory-control) and minor function code IRP_MN_QUERY_DIRECTORY.

No specific access rights are required to query this information.

This structure must be LONG-aligned.

See [About reparse points](https://learn.microsoft.com/windows-hardware/drivers/ifs/reparse-points) for more information about reparse points.

## See also

[**FltTagFileEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flttagfileex)

[**IRP_MJ_DIRECTORY_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-directory-control)

[**ZwQueryDirectoryFileEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwquerydirectoryfileex)