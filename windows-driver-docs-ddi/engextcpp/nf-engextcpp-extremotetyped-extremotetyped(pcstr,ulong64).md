# ExtRemoteTyped::ExtRemoteTyped(PCSTR,ULONG64)

## Description

The **ExtRemoteTyped** constructor creates a new instance of the **ExtRemoteTyped** class.

## Parameters

### `Expr` [in]

An expression that evaluates to the desired symbol. This expression is evaluated by the default expression evaluator.

### `Offset` [in]

An additional parameter that can be used when evaluating the *Expr* expression. This additional parameter is available in the expression as the **$extin** pseudo-register. For example, to specify a process environment block (PEB) at a particular location, you could set *Expr* to the C++ expression `(ntdll!_PEB *)@$extin`. This casts the pseudo-register **$extin** to a pointer to a PEB. Then, set *Offset* to the location of the PEB structure.

## See also

[DEBUG_TYPED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_debug_typed_data)

[ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong))

[ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped)

[ExtRemoteTyped::ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-extremotetyped)

[ExtRemoteTyped::ExtRemoteTyped (DEBUG_TYPED_DATA)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-extremotetyped(constdebug_typed_data))

[ExtRemoteTyped::ExtRemoteTyped (ExtRemoteTyped)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-extremotetyped(constextremotetyped_))

[ExtRemoteTyped::ExtRemoteTyped (PCSTR)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-extremotetyped(pcstr))

[ExtRemoteTyped::ExtRemoteTyped (PCSTR, ULONG64, bool)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-extremotetyped(pcstr_ulong64_bool_pulong64_pcstr))

[ExtRemoteTyped::Set(bool)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(bool_ulong64_ulong_ulong64))

[ExtRemoteTyped::Set(pcstr ulong64 bool)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr_ulong64_bool_pulong64_pcstr))

[ExtRemoteTyped::Set(pcstr ulong64)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr_ulong64))

[ExtRemoteTyped::Set(pcstr)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr))

[ExtRemoteTypedList](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetypedlist-extremotetypedlist(extremotedata__pcstr_pcstr_ulong64_ulong_pulong64_bool))