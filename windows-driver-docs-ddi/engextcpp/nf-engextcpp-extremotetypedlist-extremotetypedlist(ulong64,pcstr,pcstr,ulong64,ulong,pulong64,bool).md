# ExtRemoteTypedList::ExtRemoteTypedList(ULONG64,PCSTR,PCSTR,ULONG64,ULONG,PULONG64,bool)

## Description

The **ExtRemoteTypedList** constructors create a new instance that wraps a typed singly-linked or doubly-linked list.

## Parameters

### `Head` [in]

The location, in the target's memory, of the head of the list. The head is not considered to be an item in the list. The type of the head of the list is SINGLE_LIST_ENTRY or LIST_ENTRY.

### `Type` [in]

The type name for the list items. *Type* can include a module qualifier (for example, **mymodule!mytype**). If *TypeId* is not zero, *Type* is not used.

### `LinkField` [in]

The name of the field of the typed data structure that contains the pointer to the next list item. This is either the SINGLE_LIST_ENTRY structure or the LIST_ENTRY structure embedded in the list item.

### `TypeModBase` [in]

The location in the target's memory of the base address of the module that contains the type specified by *TypeId*. If *TypeId* is zero, *TypeModBase* is not used.

### `TypeId` [in]

The type ID of the type relative to the module specified by *TypeModBase*. If *TypeId* is zero, *Type* is used to specify the type of the list items.

### `CacheCookie` [in, out, optional]

The cache cookie to use for caching the type information. If *CacheCookie* is **NULL**, the debugger engine will search for the type information each time.

For more information about *CacheCookie*, see the following methods:

* [ExtRemoteTyped::Set(bool)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(bool_ulong64_ulong_ulong64))
* [ExtRemoteTyped::Set(pcstr)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr))
* [ExtRemoteTyped::Set(pcstr ulong64)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr_ulong64))
* [ExtRemoteTyped::Set(pcstr ulong64 bool)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr_ulong64_bool_pulong64_pcstr))

### `Double` [in]

Specifies whether the list is singly-linked or doubly-linked. If *Double* is `true`, the list is doubly-linked. If *Double* is `false`, the list is singly-linked.

## See also

[ExtRemoteTyped::Set(bool)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(bool_ulong64_ulong_ulong64))

[ExtRemoteTyped::Set(pcstr ulong64 bool)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr_ulong64_bool_pulong64_pcstr))

[ExtRemoteTyped::Set(pcstr ulong64)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr_ulong64))

[ExtRemoteTyped::Set(pcstr)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr))

[ExtRemoteTypedList](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetypedlist-extremotetypedlist(extremotedata__pcstr_pcstr_ulong64_ulong_pulong64_bool))

[ExtRemoteTypedList::ExtRemoteTypedList(ExtRemoteData)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetypedlist-extremotetypedlist(extremotedata__pcstr_pcstr_ulong64_ulong_pulong64_bool))