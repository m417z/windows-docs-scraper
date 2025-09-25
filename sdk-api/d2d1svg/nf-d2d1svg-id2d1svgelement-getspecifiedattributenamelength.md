# ID2D1SvgElement::GetSpecifiedAttributeNameLength

## Description

Gets the string length of the name of the specified attribute at the given index. The output string length does not include room for the null terminator.

## Parameters

### `index`

Type: **UINT32**

The index of the attribute.

### `nameLength` [out]

Type: **UINT32***

Outputs the string length of the name of the specified attribute.

### `inherited` [out, optional]

Type: **BOOL***

Indicates whether the attribute is set to the inherit value.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1SvgElement](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgelement)