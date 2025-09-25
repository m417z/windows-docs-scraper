# ID2D1SvgElement::GetSpecifiedAttributeCount

## Description

Returns the number of specified attributes on this element. Attributes are only considered specified if they are explicitly set on the element or present within an inline style.
Properties that receive their value through CSS inheritance are not considered specified.
An attribute can become specified if it is set through a method call.
It can become unspecified if it is removed via [RemoveAttribute](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nf-d2d1svg-id2d1svgelement-removeattribute).

## Return value

Type: **UINT32**

Returns the number of specified attributes on this element.

## See also

[ID2D1SvgElement](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgelement)