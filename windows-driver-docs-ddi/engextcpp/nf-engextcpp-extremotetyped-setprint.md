# ExtRemoteTyped::SetPrint

## Description

The **SetPrint** method sets the typed data represented by the [ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped) object by formatting an expression and then evaluating that expression.

## Parameters

### `Format` [in]

The format string used to create the expression. This is the same as the format string used by the C **printf** function.

**Note** While other methods and functions in the debugger engine API provide additional, debugger-specific conversion characters, **SetPrint** only supports the conversion characters used by **printf**.

### `...`

The arguments for the format string, as in **printf**. The arguments should match the conversion characters in *Format*.

## Return value

This method does not return a value.

## See also

[ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped)

[ExtRemoteTyped::Set(bool)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(bool_ulong64_ulong_ulong64))

[ExtRemoteTyped::Set(pcstr ulong64 bool)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr_ulong64_bool_pulong64_pcstr))

[ExtRemoteTyped::Set(pcstr ulong64)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr_ulong64))

[ExtRemoteTyped::Set(pcstr)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-set(pcstr))