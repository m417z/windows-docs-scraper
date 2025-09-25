# ExtRemoteData::ReadBuffer

## Description

The **ReadBuffer** method reads data from the target's memory. The data is located in the beginning of the region represented by the [ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong)) object. However, the size of the data can be different.

## Parameters

### `Buffer` [out]

Pointer that receives the data read from the target.

### `Bytes` [in]

Specifies the number of bytes to read. The *Buffer* buffer must be at least this size.

### `MustReadAll` [in]

Specifies what happens if the debugger engine is unable to read all the data from the target. If *MustReadAll* is `true` and the debugger engine is unable to read *Bytes* bytes from the target, an **ExtRemoteException** will be thrown. If *MustReadAll* is `false`, no exception will be thrown if the engine is unable to read the requested number of bytes from the target.

## Return value

**ReadBuffer** returns the number of bytes read from the target and copied into the *Buffer* buffer. If *MustReadAll* is `true`, the value of *Bytes* will be returned (unless an exception is thrown).

## See also

[ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong))

[ExtRemoteData::WriteBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-writebuffer)