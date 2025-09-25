# ExtRemoteData::Set(const DEBUG_TYPED_DATA)

## Description

The **Set** method sets the region of the target's memory represented by the [ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong)) object.

## Parameters

### `Typed` [in]

Specifies the region of memory by using a [DEBUG_TYPED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_debug_typed_data) structure.

## Remarks

The **Set** method will read the contents of the specified region of memory and cache the data. The data can be retrieved using [ExtRemoteData::GetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getdata) or one of the ExtRemoteTyped::Get*Xxx* methods.

## See also

[ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong))

[ExtRemoteData::ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata)

[ExtRemoteData::GetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getdata)

[ExtRemoteData::Set (Offset, Bytes)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-set)