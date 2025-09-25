# ExtRemoteTyped::ExtRemoteTyped(PCSTR,ULONG64,bool,PULONG64,PCSTR)

## Description

The **ExtRemoteTyped** constructor creates a new instance of the **ExtRemoteTyped** class.

## Parameters

### `Type` [in]

An expression that evaluates to the desired symbol. This expression is evaluated by the default expression evaluator.

### `Offset` [in]

The location of the data in the target's virtual address space.

### `PtrTo` [in]

Specifies whether or not to set the [ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped) instance to the specified typed data, or to a pointer to the specified typed data. If *PtrTo* is true, the **ExtRemoteTyped** instance will contain a pointer to the typed data.

### `CacheCookie` [in, out, optional]

The cache cookie to use for caching type information. If *CacheCookie* is **NULL**, the debugger engine will search for type information each time.

For more information about *CacheCookie*, see the following methods:

* [ExtRemoteTyped::Set(bool)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(bool_ulong64_ulong_ulong64))
* [ExtRemoteTyped::Set(pcstr)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr))
* [ExtRemoteTyped::Set(pcstr ulong64)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr_ulong64))
* [ExtRemoteTyped::Set(pcstr ulong64 bool)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr_ulong64_bool_pulong64_pcstr))

### `LinkField` [in, optional]

The name of a field in the typed data that contains the pointer to the next item in a list. *LinkField* should be set if *CacheCookie* is being used for the first time and will later be used with [ExtRemoteTypedList](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetypedlist-extremotetypedlist(extremotedata__pcstr_pcstr_ulong64_ulong_pulong64_bool)).

## See also

[DEBUG_TYPED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_debug_typed_data)

[ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong))

[ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped)

[ExtRemoteTyped::ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-extremotetyped)

[ExtRemoteTyped::ExtRemoteTyped (DEBUG_TYPED_DATA)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-extremotetyped(constdebug_typed_data))

[ExtRemoteTyped::ExtRemoteTyped (ExtRemoteTyped)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-extremotetyped(constextremotetyped_))

[ExtRemoteTyped::ExtRemoteTyped (PCSTR)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-extremotetyped(pcstr))

[ExtRemoteTyped::ExtRemoteTyped (PCSTR, ULONG64)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-extremotetyped(pcstr_ulong64))

[ExtRemoteTyped::Set(bool)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(bool_ulong64_ulong_ulong64))

[ExtRemoteTyped::Set(pcstr ulong64 bool)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr_ulong64_bool_pulong64_pcstr))

[ExtRemoteTyped::Set(pcstr ulong64)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr_ulong64))

[ExtRemoteTyped::Set(pcstr)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr))

[ExtRemoteTypedList](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetypedlist-extremotetypedlist(extremotedata__pcstr_pcstr_ulong64_ulong_pulong64_bool))