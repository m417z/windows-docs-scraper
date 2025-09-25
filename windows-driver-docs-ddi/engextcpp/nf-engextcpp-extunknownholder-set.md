# ExtUnknownHolder::Set method

## Description

The **Set** method sets the typed data represented by the [ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped) object.

## Parameters

### `Unk`

### `PtrTo` [in]

Specifies whether or not to set the **ExtRemoteTyped** instance to the specified typed data, or to a pointer to the specified typed data. If *PtrTo* is `true`, the **ExtRemoteTyped** instance will be a pointer to the typed data.

### `TypeModBase` [in]

The base address of the module to which the type belongs.

### `TypeId` [in]

The type ID of the type.

### `Offset` [in]

Specifies the location of the data in the target's memory.

## Syntax

```cpp
void Set(
  [in] bool    PtrTo,
  [in] ULONG64 TypeModBase,
  [in] ULONG   TypeId,
  [in] ULONG64 Offset
);
```

## See also

[ExtRemoteTyped::Set (PCSTR)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr).md)

[ExtRemoteTypedList](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetypedlist)

[ExtRemoteTyped::SetPrint](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-setprint)

[ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped)