# ExtRemoteData::WriteBuffer

## Description

The **WriteBuffer** method writes data to the target's memory. The data is located in the beginning of the region represented by the [ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong)) object. However, the size of the data can be different.

## Parameters

### `Buffer` [in]

Specifies the data to write to the target.

### `Bytes` [in]

Specifies the number of bytes to write. The *Buffer* buffer must be at least this size.

### `MustWriteAll`

## Return value

**WriteBuffer** returns the number of bytes written to the target from the *Buffer* buffer. If *MustReadAll* is `true`, the value of *Bytes* will be returned (unless an exception is thrown).

## See also

[ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong))

[ExtRemoteData::ReadBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-readbuffer)