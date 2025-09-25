# ExtRemoteData::GetW32Bool

## Description

The **GetW32Bool** method returns a BOOL version of the [ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong)) object, which represents the contents of the target's memory.

## Return value

**GetW32Bool** returns the BOOL version of the [ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong)) object.

## Remarks

The size of the memory represented by the [ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong)) object must be `sizeof(BOOL)`.

**Note** There are several different types that can be used to represent a Boolean value. BOOL is one of these types. For the C++ **bool** type, use [ExtRemoteData::GetStdBool](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getstdbool). For the BOOLEAN type, use [ExtRemoteData::GetBoolean](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getboolean).

## See also

[ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong))

[ExtRemoteData::GetBoolean](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getboolean)

[ExtRemoteData::GetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getdata)

[ExtRemoteData::GetStdBool](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getstdbool)