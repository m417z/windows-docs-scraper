# ExtRemoteTyped::Set(PCSTR,ULONG64)

## Description

The **Set** method sets the typed data represented by the [ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped) object.

## Parameters

### `Expr` [in]

An expression that evaluates to the desired symbol. This expression is evaluated by the default expression evaluator.

### `Offset` [in]

Specifies an additional parameter that can be used when evaluating the *Expr* expression. This additional parameter is available in the expression as the **$extin** pseudo-register. For example, to specify a process environment block (PEB) at a particular location, you could set *Expr* to the C++ expression `(ntdll!_PEB *)@$extin`. This casts the pseudo-register **$extin** to a pointer to a PEB. Then, set *Offset* to the location of the PEB instance.

## Remarks

### Returns

This method does not return a value.

## See also

[ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped)

[ExtRemoteTyped::Set (PCSTR)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr))

[ExtRemoteTyped::Set (PCSTR, ULONG64, bool)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr_ulong64_bool_pulong64_pcstr))

[ExtRemoteTyped::Set (bool)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(bool_ulong64_ulong_ulong64))

[ExtRemoteTyped::SetPrint](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-setprint)

[ExtRemoteTypedList](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetypedlist-extremotetypedlist(extremotedata__pcstr_pcstr_ulong64_ulong_pulong64_bool))