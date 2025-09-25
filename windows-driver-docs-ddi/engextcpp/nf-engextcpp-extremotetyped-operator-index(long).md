# ExtRemoteTyped::operator (LONG)

## Description

The **operator[]** overloaded operator returns the typed data in the specified array element of the typed data represented by this object.

## Parameters

### `Index` [in]

The index of the array element.

## Return value

The **operator[]** operator returns a new **ExtRemoteTyped** object that represents the typed data for the specified element of the array.

## Remarks

If the typed data represented by this object is a pointer and not an array, the pointer is treated like an array.

The [ExtRemoteTyped::ArrayElement](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-arrayelement) performs a similar function.

## See also

[ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped)

[ExtRemoteTyped::ArrayElement](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-arrayelement)