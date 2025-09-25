# ExtRemoteData::GetString(PSTR,ULONG,ULONG,bool,PULONG)

## Description

The **GetString** method reads a null-terminated string from the target's memory. The string is located in the beginning of the region represented by the [ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong)) object.

## Parameters

### `Buffer` [out]

Receives the null-terminated string read from the target. The type of *Buffer* must be the same as the type of the string on the target. If the string is a Unicode string, the type of *Buffer* must be PWSTR. If the string is a multibyte string, the type of *Buffer* must be PSTR.

**Note** the remainder of the *Buffer* buffer, after the string, can be overwritten by this method.

### `BufferChars` [in]

Specifies the size, in characters, of the *Buffer* buffer.

### `MaxChars` [in]

Specifies the maximum number of characters to read from the target.

### `MustFit` [in]

Specifies what happens if the string is larger than *BufferChars* characters. If *MustFit* is `true` and the string is larger than *BufferChars* characters, an **ExtRemoteException** will be thrown. If *MustFit* is `false` and the string is larger than *BufferChars* characters, the string will be truncated and null-terminated to fit inside the *Buffer* buffer.

### `NeedChars`

## Return value

**GetString** returns the null-terminated string that was read from the target. This is *Buffer*.

## Remarks

This method can only be used if the region represented by the [ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong)) object is in virtual memory. It will not work if the region specifies physical memory.

## See also

[ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong))

[ExtRemoteData::ReadBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-readbuffer)