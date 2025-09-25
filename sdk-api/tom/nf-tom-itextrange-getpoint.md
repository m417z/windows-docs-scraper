# ITextRange::GetPoint

## Description

Retrieves screen coordinates for the start or end character position in the text range, along with the intra-line position.

## Parameters

### `Type`

Type: **long**

Flag that indicates the position to retrieve. This parameter can include one value from each of the following tables. The default value is tomStart + TA_BASELINE + TA_LEFT.

#### tomAllowOffClient

#### tomClientCoord

#### tomObjectArg

#### tomTransform

Use one of the following values to indicate the start or end of the range.

#### tomStart

#### tomEnd

Use one of the following values to indicate the vertical position.

|  |  |
| --- | --- |
| TA_TOP | Top edge of the bounding rectangle. |
| TA_BASELINE | Base line of the text. |
| TA_BOTTOM | Bottom edge of the bounding rectangle. |

Use one of the following values to indicate the horizontal position.

|  |  |
| --- | --- |
| TA_LEFT | Left edge of the bounding rectangle. |
| TA_CENTER | Center of the bounding rectangle. |
| TA_RIGHT | Right edge of the bounding rectangle. |

### `px`

Type: **long***

The x-coordinate.

### `py`

Type: **long***

The y-coordinate.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Either *px* or *py* is null. |
| **S_FALSE** | Failure for some other reason. |

## Remarks

The **ITextRange::GetPoint** method gives [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange) the ability to emulate UI-pointer commands; it is also handy for accessibility purposes.

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Other Resources**

**Reference**

[SetPoint](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-setpoint)

[SetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextalign)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)