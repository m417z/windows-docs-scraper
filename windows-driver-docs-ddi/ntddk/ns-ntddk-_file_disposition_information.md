# _FILE_DISPOSITION_INFORMATION structure

## Description

The **FILE_DISPOSITION_INFORMATION** structure is used as an argument to the [ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile) routine.

## Members

### `DeleteFile`

Indicates whether the operating system file should delete the file when the file is closed. Set this member to **TRUE** to delete the file when it is closed. Otherwise, set to **FALSE**. Setting this member to **FALSE** has no effect if the handle was opened with FILE_FLAG_DELETE_ON_CLOSE.

## Remarks

The caller must have DELETE access to a given file in order to call **ZwSetInformationFile** with **DeleteFile** set to **TRUE** in this structure. Subsequently, the only legal operation by such a caller is to close the open file handle.

A file marked for deletion is not actually deleted until all open handles for the file object have been closed and the link count for the file is zero.

## See also

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)