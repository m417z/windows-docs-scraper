## Description

Gets an attribute of this element as a string.

## Parameters

### `name`

Type: [in] **PCWSTR**

The name of the attribute.

### `value`

Type: [out] **PWSTR**

The value of the attribute.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code. Returns an error if the attribute name is not valid on this element. Returns an error if the attribute cannot be expressed as the specified string type. Returns an error if the attribute is not specified.

## See also

[ID2D1SvgElement](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgelement)