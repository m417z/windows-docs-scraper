# IInkStrokes::ToString

## Description

[**ToString** is no longer available for use as of Windows Vista. Instead, see the [String](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_string) property for the equivalent of this method for the [IInkRecognitionAlternate](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate) object.
]

Has the default recognizer perform recognition on the collection of strokes and returns the top string of the top alternate of the recognition result.

## Parameters

### `ToString` [out, retval]

The top string of the [TopAlternate](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionresult-get_topalternate) property of the [IInkRecognitionResult](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionresult) object, after the default recognizer performs recognition on the collection of strokes.

For more information about the **BSTR** data type, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_FAIL** | Operation failed. |
| **E_OUTOFMEMORY** | Out of memory. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **TPC_E_RECOGNIZER_NOT_REGISTERED** | No recognizers are installed, the recognizers registry key is corrupted, or your environment does not support handwriting recognition. |

## Remarks

**ToString** should not be used for handwriting recognition applications; it can be used for debugging purposes.

**ToString** returns **NULL** if:

* The [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection is empty.
* A default recognizer cannot be created.
* The default recognizer does not support free input.

## See also

[IInkRecognizer Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizer)

[IInkStrokes](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkstrokes)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))