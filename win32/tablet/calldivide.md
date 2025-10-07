# CallDivide function

Retrieves analysis information from the [**InkDivider**](https://learn.microsoft.com/windows/win32/tablet/inkdivider-class) object.

This function is not intended to be used by application code.

## Parameters

*hDivider* \[in\]

A handle to the [**InkDivider**](https://learn.microsoft.com/windows/win32/tablet/inkdivider-class) object.

*pWordSize* \[in\]

The size of the word returned by the [**InkDivider**](https://learn.microsoft.com/windows/win32/tablet/inkdivider-class) object.

*pLineSize* \[in\]

The size of the line returned by the [**InkDivider**](https://learn.microsoft.com/windows/win32/tablet/inkdivider-class) object.

*pParagraphSize* \[in\]

The size of the paragraph returned by the [**InkDivider**](https://learn.microsoft.com/windows/win32/tablet/inkdivider-class) object.

*pDrawingSize* \[in\]

The size of the drawing returned by the [**InkDivider**](https://learn.microsoft.com/windows/win32/tablet/inkdivider-class) object.

*pWordCount* \[out\]

The number of words returned by ink analysis.

*pLineCount* \[out\]

The number of lines returned by ink analysis.

*pParagraphCount* \[out\]

The number of paragraphs returned by ink analysis.

## Return value

This function can return one of these values.

| Return code | Description |
|----------------------------------------------------------------------------------------------|------------------------------------------------|
| **S\_OK** | The function suceeded.<br> |
| **E\_INVALIDARG** | One or more parameters are invalid.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP Tablet PC Edition \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| Library<br> | InkDiv.dll |

