# IoCheckQuerySetFileInformation function

## Description

The **IoCheckQuerySetFileInformation** routine checks the validity of the parameters for either a query or set file information operation.

## Parameters

### `FileInformationClass`

A [FILE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_file_information_class) enum value that specifies the file information class to be checked.

### `Length`

Size, in bytes, of the buffer required for the specified file information operation.

### `SetOperation`

Boolean value that specifies the operation type. If *SetOperation* is **TRUE**, the operation is a set file operation; if **FALSE,** it is a query file operation.

## Return value

**IoCheckQuerySetFileInformation** returns STATUS_SUCCESS if the parameters are valid; otherwise, it returns one of the following error codes.

| Return Code | Description |
| ----------- | ----------- |
| STATUS_INVALID_INFO_CLASS | The value specified in *FileInformationClass* is not a valid information class. |
| STATUS_INFO_LENGTH_MISMATCH | The buffer size specified in *Length* is smaller than the buffer size required for the specified file operation. |

## Remarks

 **IoCheckQuerySetFileInformation** is used primarily by network servers running in kernel mode since no such parameter validity checking is done in the normal path.

## See also

[FILE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_file_information_class)

[ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)

[ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)