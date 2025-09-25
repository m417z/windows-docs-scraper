# ExtCheckedPointer::operator= method

## Description

The **operator=** overloaded assignment operator sets the typed data represented by the [ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped) object by copying the information from another object.

## Syntax

```
ExtRemoteTyped & operator=(
  [in] const DEBUG_TYPED_DATA *Typed
);
```

## Parameters

### `Ptr`

### `Typed` [in]

A pointer to a [DEBUG_TYPED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_debug_typed_data) structure that describes the data and type to be assigned to this object.

## Return value

**operator=** returns the [ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped) object.

## Remarks

The typed data can also be copied using the [ExtBuffer::Copy method](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extbuffer-copy(const_t_ulong).md)

## See also

[ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped)

[DEBUG_TYPED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_debug_typed_data)

[ExtRemoteTyped::Operator= (ExtRemoteTyped)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extbuffer-operator-assign(extbuffer__t__).md)

