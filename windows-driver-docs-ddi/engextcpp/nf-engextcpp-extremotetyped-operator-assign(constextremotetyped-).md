# ExtRemoteTyped::operator=(const ExtRemoteTyped &)

## Description

The **operator=** overloaded assignment operator sets the typed data represented by the [ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped) object by copying the information from another object.

## Parameters

### `Typed` [in, ref]

An existing [ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped) object that represents the data and type to be assigned to this object.

## Return value

**operator=** returns the [ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped) object.

## Remarks

The typed data can also be copied using the [ExtRemoteTyped::Copy(Debug Typed Data)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-copy(constdebug_typed_data)) or [ExtRemoteTyped::Copy(ExtRemoteTyped)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-copy(constextremotetyped_)) methods.

## See also

[DEBUG_TYPED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_debug_typed_data)

[ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped)

[ExtRemoteTyped::Operator= (DEBUG_TYPED_DATA)](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff544342(v=vs.85))