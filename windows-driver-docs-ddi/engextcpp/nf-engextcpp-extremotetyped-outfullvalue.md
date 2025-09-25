# ExtRemoteTyped::OutFullValue

## Description

The **OutFullValue** method prints the type and value of the typed data represented by this object.

## Remarks

The **OutFullValue** method prints more detail than the [ExtRemoteTyped::OutSimpleValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-outsimplevalue) method. For example, **OutFullValue** prints dereferenced pointers and the values that they point to.

The type and value information is sent to the debugger engine's output callbacks.

### Returns

This method does not return a value.

## See also

[ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped)

[ExtRemoteTyped::OutSimpleValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-outsimplevalue)