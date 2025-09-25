# _FILE_COMPLETION_INFORMATION structure

## Description

The **FILE_COMPLETION_INFORMATION** structure contains the port handle and key for an I/O completion port created for a file handle.

## Members

### `Port`

The handle to the completion port created for an associated file handle.

### `Key`

A custom defined value which is included in every I/O completion packet for **Port**.

## Remarks

The **FILE_COMPLETION_INFORMATION** structure is used to replace the completion information for a port handle set in **Port**. Completion information is replaced with the [ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile) routine with the *FileInformationClass* parameter set to **FileReplaceCompletionInformation**. The **Port** and **Key** members of **FILE_COMPLETION_INFORMATION** are set to their new values. To remove an existing completion port for a file handle, **Port** is set to NULL.

## See also

[ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)