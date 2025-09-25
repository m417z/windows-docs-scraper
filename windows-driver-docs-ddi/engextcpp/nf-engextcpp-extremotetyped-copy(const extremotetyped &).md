# ExtRemoteTyped::Copy(const ExtRemoteTyped &)

## Description

The **Copy** method sets the typed data represented by the [ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped) object by copying the information from another object.

## Parameters

### `Typed` [in, ref]

An existing [ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped) object that represents the typed data description to copy. This becomes the typed data represented by this object.

## Remarks

The typed data can also be copied using the [ExtRemoteTyped::Copy(Debug Typed Data)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-copy(constdebug_typed_data)) method.

### Returns

This method does not return a value.

## See also

[DEBUG_TYPED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_debug_typed_data)

[ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped)

[ExtRemoteTyped::operator=](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff544357(v=vs.85))