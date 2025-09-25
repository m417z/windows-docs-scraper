# ID2D1SvgElement::GetAttributeValue(PCWSTR,REFIID,void)

## Description

Gets an attribute of this element as an interface type.

## Parameters

### `name` [in]

Type: **PCWSTR**

The name of the attribute.

### `riid` [in]

Type: **REFIID**

The interface ID of the attribute value.

### `value`

Type: **void****

The value of the attribute.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code. Returns an error if the
attribute is not specified. Returns an error if the attribute name is not valid
on this element. Returns an error if the attribute cannot be expressed as the
specified interface type.

## See also

[ID2D1SvgElement](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgelement)