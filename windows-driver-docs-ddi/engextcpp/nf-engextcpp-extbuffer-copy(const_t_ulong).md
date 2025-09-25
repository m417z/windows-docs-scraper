# ExtBuffer::Copy method

## Description

The **Copy** method sets the typed data represented by the [ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped) object by copying the information from another object.

## Parameters

### `Src`

### `Elts`

DEBUG_TYPED_DATA

### `Elts` [in]

DEBUG_TYPED_DATA

### `Typed` [in]

The typed data description to copy. This becomes the typed data represented by this object.

## Return value

This method does not return a value.

## Syntax

```cpp
void Copy(
  [in] const DEBUG_TYPED_DATA *Typed
);
```

## Remarks

## See also

[ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped)

[ExtRemoteTyped::operator=](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff544357(v=vs.85))

[DEBUG_TYPED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_debug_typed_data)