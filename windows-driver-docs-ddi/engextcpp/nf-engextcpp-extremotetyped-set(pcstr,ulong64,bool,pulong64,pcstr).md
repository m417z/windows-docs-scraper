# ExtRemoteTyped::Set(PCSTR,ULONG64,bool,PULONG64,PCSTR)

## Description

The **Set** method sets the typed data represented by the [ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped) object.

## Parameters

### `Type` [in]

The type name of the type. *Type* can include a module qualifier--for example, **mymodule!mytype**. The module qualifier can be omitted, but it is recommended that it be included if the module is known.

### `Offset` [in]

Specifies the location of the data in the target's memory.

### `PtrTo` [in]

Specifies whether or not to set the **ExtRemoteTyped** instance to the specified typed data, or to a pointer to the specified typed data. If *PtrTo* is `true`, the **ExtRemoteTyped** instance will be a pointer to the typed data.

### `CacheCookie` [in, out, optional]

A cache cookie used for caching the type information. If *CacheCookie* is **NULL**, the debugger engine will search for the type information each time.

A *cache cookie* is a pointer to a ULONG64. It is associated with a particular symbol that is uniquely identified by the symbol's type ID and the address of the module that contains the symbol. The first time it is used, the ULONG64 that cache cookie points to must be set to 0. In this case, the debugger engine will search for the symbol information and cache it, then it will set the cookie so that the symbol information can be easily retrieved later. Whenever you use a subsequent method that will need information about the same symbol, use the cache cookie. The debugger engine will then be able to retrieve the symbol information from the cache instead of searching for it. Each cache cookie should only be used with a single type. If a cache cookie is used in conjunction with a different symbol, the cache cookie might be corrupted.

### `LinkField` [in, optional]

The name of a field in the typed data structure which contains the pointer to the next item in a list. *LinkField* should be set if *CacheCookie* is being used for the first time and will later be used with [ExtRemoteTypedList](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetypedlist-extremotetypedlist(extremotedata__pcstr_pcstr_ulong64_ulong_pulong64_bool)).

## Remarks

### Returns

This method does not return a value.

## See also

[ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped)

[ExtRemoteTyped::Set (PCSTR)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr))

[ExtRemoteTyped::Set (PCSTR, ULONG64)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr_ulong64))

[ExtRemoteTyped::Set (bool)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(bool_ulong64_ulong_ulong64))

[ExtRemoteTyped::SetPrint](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-setprint)

[ExtRemoteTypedList](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetypedlist-extremotetypedlist(extremotedata__pcstr_pcstr_ulong64_ulong_pulong64_bool))