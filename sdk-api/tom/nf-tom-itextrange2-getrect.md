# ITextRange2::GetRect

## Description

Retrieves a rectangle of the specified type for the current range.

## Parameters

### `Type` [in]

Type: **long**

The type of rectangle to return. This parameter can include one value from each of the following tables.

#### tomAllowOffClient

#### tomClientCoord

#### tomObjectArg

#### tomTransform

Use one of these values to indicate the vertical position:

|  |  |
| --- | --- |
| TA_TOP | Top edge of the bounding rectangle. |
| TA_BASELINE | Base line of the text. |
| TA_BOTTOM | Bottom edge of the bounding rectangle. |

Use one of these values to indicate the horizontal position:

|  |  |
| --- | --- |
| TA_LEFT | Left edge of the bounding rectangle. |
| TA_CENTER | Center of the bounding rectangle. |
| TA_RIGHT | Right edge of the bounding rectangle. |

### `pLeft` [out]

Type: **long***

The left rectangle coordinate.

### `pTop` [out]

Type: **long***

The top rectangle coordinate.

### `pRight` [out]

Type: **long***

The right rectangle coordinate.

### `pBottom` [out]

Type: **long***

The bottom rectangle coordinate.

### `pHit` [out]

Type: **long***

The hit-test value for the range.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)