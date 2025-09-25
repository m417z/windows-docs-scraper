# ExtRemoteData::GetLong

## Description

The **GetLong** method returns a LONG version of the [ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong)) object, which represents the contents of the target's memory.

## Return value

**GetLong** returns the LONG version of the [ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong)) object.

## Remarks

The size of the memory represented by this [ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong)) object must be `sizeof(LONG)`.

## See also

[ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong))

[ExtRemoteData::GetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getdata)

[ExtRemoteData::GetLong64](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getlong64)

[ExtRemoteData::GetUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getulong)