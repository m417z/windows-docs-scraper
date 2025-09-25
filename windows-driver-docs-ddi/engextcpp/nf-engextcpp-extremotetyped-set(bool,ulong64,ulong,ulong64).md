# ExtRemoteTyped::Set(bool,ULONG64,ULONG,ULONG64)

## Description

The **Set** method sets the typed data represented by the [ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped) object.

## Parameters

### `PtrTo` [in]

Specifies whether or not to set the **ExtRemoteTyped** instance to the specified typed data, or to a pointer to the specified typed data. If *PtrTo* is `true`, the **ExtRemoteTyped** instance will be a pointer to the typed data.

### `TypeModBase` [in]

The base address of the module to which the type belongs.

### `TypeId` [in]

The type ID of the type.

### `Offset` [in]

Specifies the location of the data in the target's memory.

## Remarks

### Returns

This method does not return a value.

## See also

[ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped)

[ExtRemoteTyped::Set (PCSTR)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr))

[ExtRemoteTyped::Set (PCSTR, ULONG64)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr_ulong64))

[ExtRemoteTyped::Set (PCSTR, ULONG64, bool)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr_ulong64_bool_pulong64_pcstr))

[ExtRemoteTyped::SetPrint](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-setprint)

[ExtRemoteTypedList](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetypedlist-extremotetypedlist(extremotedata__pcstr_pcstr_ulong64_ulong_pulong64_bool))