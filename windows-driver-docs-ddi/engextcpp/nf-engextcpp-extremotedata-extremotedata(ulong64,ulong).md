# ExtRemoteData::ExtRemoteData(ULONG64,ULONG)

## Description

The **ExtRemoteData** constructor creates a new instance of the[ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotedata) class.

## Parameters

### `Offset` [in]

Location of the beginning of the memory region in the target's virtual address space.

### `Bytes` [in]

Number of bytes in the memory region.

## Remarks

If a memory region is specified, the contents of the region are read from the target and cached. The data can be retrieved using [ExtRemoteData::GetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getdata) or one of the ExtRemoteTyped::Get*Xxx* methods.

The constructor is called by the ExtRemoteData::Set(Typed), ExtRemoteData::Set(Offset Bytes) methods and the ExtRemoteData::GetData method.

## See also

[ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotedata)

[ExtRemoteData::GetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getdata)

[ExtRemoteData::ExtRemoteData (Name, Offset, Bytes)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong))