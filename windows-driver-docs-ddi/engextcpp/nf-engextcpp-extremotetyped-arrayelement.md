# ExtRemoteTyped::ArrayElement

## Description

The **ArrayElement** method returns the typed data in the specified array element of the typed data represented by the **ExtRemoteTyped** object.

## Parameters

### `Index` [in]

The index of the array element.

## Return value

**ArrayElement** returns a new **ExtRemoteData** object that represents the typed data for the specified element of the array.

## Remarks

If the typed data represented by this object is a pointer and not an array, the pointer is treated like an array.

The [ExtRemoteTyped::operator[]](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff544357(v=vs.85)) overloaded operator performs a similar function.

## See also

[ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped)

[ExtRemoteTyped::operator[]](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff544357(v=vs.85))