# ExtRemoteData::GetLongPtr

## Description

The **GetLongPtr** method returns a signed integer version (extended to LONG64) of the [ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong)) object, which represents the contents of the target's memory. The size of the unsigned integer from the target is the same size as a pointer on the target.

## Return value

**GetLongPtr** returns a signed integer version of the [ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong)) object, extended to LONG64.

## Remarks

The size of the memory represented by the [ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong)) object must be the same as the size of a pointer on the target, `ExtExtension::m_PtrSize`.

## See also

[ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong))

[ExtRemoteData::GetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getdata)

[ExtRemoteData::GetLong](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getlong)

[ExtRemoteData::GetLong64](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getlong64)

[ExtRemoteData::GetUlongPtr](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getulongptr)