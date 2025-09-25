# WOF_EXTERNAL_FILE_ID structure

## Description

The **WOF_EXTERNAL_FILE_ID** structure contains a file ID that is used to open a handle to a minifilter or driver.

## Members

### `FileId`

The file ID used with the **FILE_OPEN_BY_FILE_ID** flag to open a file with the [**FltCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefile) or [**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) functions.

## Remarks

Use the [**FltCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefile) function to open a handle to a file system minifilter driver; otherwise, use the [**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) function to open a handle to a driver.

## See also

[**WOF_EXTERNAL_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_wof_external_info)

[**WOF_VERSION_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_wof_version_info)