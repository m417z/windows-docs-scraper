# ExtRemoteTyped::operator

## Description

The **operator*** overloaded operator returns the typed data that is pointed to by the typed data represented by this object.

## Parameters

## Return value

The **operator*** operator returns a new **ExtRemoteData** object that represents the typed data pointed to by the typed data represented by this object.

## Remarks

If the typed data represented by this object is an array, the first element in the array is returned.

The [ExtRemoteTyped::Dereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-dereference) method performs the same function.

## See also

[ExtRemoteTyped](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nl-engextcpp-extremotetyped)

[ExtRemoteTyped::Dereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotetyped-dereference)