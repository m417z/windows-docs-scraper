# _FILE_POSITION_INFORMATION structure

## Description

The **FILE_POSITION_INFORMATION** structure is used as an argument to routines that query or set file information.

## Members

### `CurrentByteOffset`

The byte offset of the current file pointer.

## Remarks

FILE_READ_DATA or FILE_WRITE_DATA access to the file is required to change this information about the file, and the file must be opened for synchronous I/O.

If the file was opened or created with the FILE_NO_INTERMEDIATE_BUFFERING option, the value of **CurrentByteOffset** must be an integral multiple of the sector size of the underlying device.

## See also

[ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)

[ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)