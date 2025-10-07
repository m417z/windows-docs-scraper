# CallDivideResults function

Retrieves analysis results from the [**InkDivider**](https://learn.microsoft.com/windows/win32/tablet/inkdivider-class) object.

This function is not intended to be used by application code.

## Parameters

*hDivider* \[in\]

A handle to the [**InkDivider**](https://learn.microsoft.com/windows/win32/tablet/inkdivider-class) object.

*aWordStrokeIds* \[out\]

An array of identifiers associated with the word that is passed in to the [**InkDivider**](https://learn.microsoft.com/windows/win32/tablet/inkdivider-class) class.

*aLineStrokeIds* \[out\]

An array of [**ID**](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-get_id) properties for the [**IInkStrokeDisp**](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) objects associated with the line that is passed in to the [**InkDivider**](https://learn.microsoft.com/windows/win32/tablet/inkdivider-class) class.

*aParagraphStrokeIds* \[out\]

An array of the [**ID**](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-get_id) properties for the [**IInkStrokeDisp**](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) objects associated with the paragraph from the [**InkDivider**](https://learn.microsoft.com/windows/win32/tablet/inkdivider-class) class.

*aDrawingStrokeIds* \[out\]

An array of [**ID**](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-get_id) properties for the [**IInkStrokeDisp**](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) objects associated with the drawing from the [**InkDivider**](https://learn.microsoft.com/windows/win32/tablet/inkdivider-class) class.

*pastrWords* \[out\]

An array of words returned from ink analysis.

*pastrLines* \[out\]

An array of lines returned from ink analysis.

*pastrParagraphs* \[out\]

An array of paragraphs returned from ink analysis.

*aWordRotationCenterX* \[out\]

An array of the center points of the words along the x-axis from ink analysis.

*aWordRotationCenterY* \[out\]

An array of the center points of the words along the y-axis from ink analysis.

*aWordAngle* \[out\]

An array containing the angles by which to rotate the words for best analysis results.

*aLineRotationCenterX* \[out\]

An array containing the center points of the lines along the x-axis.

*aLineRotationCenterY* \[out\]

An array containing the center points of the lines along the y-axis.

*aLineAngle* \[out\]

An array containing the angles by which to rotate the lines for best analysis results.

## Return value

This function can return one of these values.

| Return code | Description |
|-----------------------------------------------------------------------------------------------|-------------------------------------------------------------------|
| **S\_OK** | The function succeeded.<br> |
| **E\_INVALIDARG** | The *hDivider* parameter is invalid.<br> |
| **E\_OUTOFMEMORY** | Could not allocate enough memory to store the results.<br> |

## Remarks

To avoid memory leaks you must release the resources for *pastrWords*, *pastrLines*, and *pastrParagraphs*.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP Tablet PC Edition \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| Library<br> | InkDiv.dll |

