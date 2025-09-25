## Description

The **IO_CREATE_STREAM_FILE_OPTIONS** structure contains the create options for a new stream file object.

## Members

### `Size`

Size in bytes of the stream options structure. Set to ```sizeof(IO_CREATE_STREAM_FILE_OPTIONS)```.

### `Flags`

The flags for the stream file create options. This value can be one of the following.

| Value | Meaning |
| ----- | ------- |
| IO_CREATE_STREAM_FILE_RAISE_ON_ERROR | On an error condition, **IoCreateStreamFileObjectEx2** will raise the error status as an exception instead of returning it. This flag is specified to maintain error status behavior of the other stream file object creation routines. |
| IO_CREATE_STREAM_FILE_LITE | A file object is created without a file handle. No close operation is sent for the file object when it is deleted. |

### `TargetDeviceObject`

A pointer to the device object to set as the target for operations on the file handle. **TargetDeviceObject** must be in the same device stack as **DeviceObject** parameter. This member is optional.

## Remarks

## See also

[**IoCreateStreamFileObjectEx2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocreatestreamfileobjectex2)