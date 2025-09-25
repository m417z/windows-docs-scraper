# ID2D1SvgElement::GetSpecifiedAttributeName

## Description

Gets the name of the attribute at the given index.

## Parameters

### `index`

Type: **UINT32**

The index of the attribute.

### `name` [out]

Type: **PWSTR**

Outputs the name of the attribute.

### `nameCount`

Type: **UINT32**

Length of the string returned in the name argument.

### `inherited` [out, optional]

Type: **BOOL***

Outputs whether the attribute is set to the inherit value.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1SvgElement](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgelement)