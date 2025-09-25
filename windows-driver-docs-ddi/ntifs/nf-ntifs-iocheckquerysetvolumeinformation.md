# IoCheckQuerySetVolumeInformation function

## Description

The **IoCheckQuerySetVolumeInformation** routine checks the validity of the parameters for either a query or set volume information operation.

## Parameters

### `FsInformationClass`

A [FS_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_fsinfoclass) enum value that specifies the information class to be checked.

### `Length`

Size, in bytes, of the buffer required for the specified information operation.

### `SetOperation`

Boolean value that specifies the operation type. If *SetOperation* is **TRUE**, the operation is a set volume operation; if **FALSE,** it is a query volume operation.

## Return value

**IoCheckQuerySetVolumeInformation** returns STATUS_SUCCESS if the parameters are valid; otherwise, it returns one of the following error codes.

| Return Code | Description |
| ----------- | ----------- |
| STATUS_INVALID_INFO_CLASS | The value specified in *FsInformationClass* is not a valid information class. |
| STATUS_INFO_LENGTH_MISMATCH | The buffer size specified in *Length* is smaller than the buffer size required for the specified volume operation. |

## Remarks

 **IoCheckQuerySetVolumeInformation** is used primarily by network servers running in kernel mode since no such parameter validity checking is done in the normal path.

## See also

[FS_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_fsinfoclass)

[ZwQueryVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-zwqueryvolumeinformationfile)

[ZwSetVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetvolumeinformationfile)