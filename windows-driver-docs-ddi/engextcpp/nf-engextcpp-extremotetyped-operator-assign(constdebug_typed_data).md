# ExtRemoteTyped::operator= method

## Description

The *operator=* method is part of the **ExtRemoteTyped** class. The **ExtRemoteTyped** class provides the ability to manipulate typed data on the target. An instance of this class represents a small region of memory on the target. This region is interpreted as a specific type. This class provides methods for manipulating the memory according to the type and for accessing the object hierarchy on the target.

**ExtRemoteTyped** is a subclass of [ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotedata).

## Parameters

### `Typed`

An existing [ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped) object that represents the data and type to be assigned to this object.

## Return value

**operator=** returns the [ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped) object.

## See also

[ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotedata)

[DEBUG_TYPED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_debug_typed_data)