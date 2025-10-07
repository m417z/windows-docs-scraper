# CallDivideResultsStrokeIds function

Retrieves the [**Id**](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-get_id) properties for the [**IInkStrokeDisp**](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) objects of the corresponding word, line, paragraph, or drawing determined by ink analysis.

This function is not intended to be used by application code.

## Parameters

*hDivider* \[in\]

A handle to the [Divider](https://learn.microsoft.com/windows/win32/tablet/the-divider-object) object.

*aWordStrokeIds\[\]* \[out\]

An array of the stroke IDs of the ink in the word.

*aLineStrokeIds\[\]* \[out\]

An array of the stroke IDs of the ink in the line.

*aParagraphStrokeIds\[\]* \[out\]

An array of the stroke IDs of the ink in the paragraph.

*aDrawingStrokeIds\[\]* \[out\]

An array of the stroke IDs of the ink in the drawing.

## Return value

This function can return one of these values.

| Return code | Description |
|----------------------------------------------------------------------------------------------|-------------------------------------------------|
| **S\_OK** | The function succeeded.<br> |
| **E\_INVALIDARG** | The *hDivider* parameter is invalid.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP Tablet PC Edition \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| Library<br> | InkDiv.dll |

