# ExtRemoteData::Set (engextcpp.h)

## Description

The **Set** method sets the region of the target's memory represented by the [ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong)) object.

## Parameters

### `Offset` [in]

Location of the beginning of the memory region in the target's virtual address space.

### `Bytes` [in]

Number of bytes in the memory region.

## Remarks

The **Set** method will read the contents of the specified region of memory and cache the data. The data can be retrieved using [ExtRemoteData::GetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getdata) or one of the ExtRemoteTyped::Get*Xxx* methods.

## Returns

This method does not return a value.

## See also

[ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong))

[ExtRemoteData::ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata)

[ExtRemoteData::GetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getdata)

[ExtRemoteData::Set (Typed)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-set(constdebug_typed_data))