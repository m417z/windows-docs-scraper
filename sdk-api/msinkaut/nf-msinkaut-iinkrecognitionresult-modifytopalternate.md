# IInkRecognitionResult::ModifyTopAlternate

## Description

Changes the top alternate of a recognition result by using the specified alternate.

## Parameters

### `Alternate` [in]

The [IInkRecognitionAlternate](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate) to use to modify the top alternate.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **TPC_E_NOT_RELEVANT** | The lattice does not contain data. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INVALIDARG** | The alternate does not match the known range, or it was not obtained from this lattice. |
| **E_INK_EXCEPTION** | An exception occurred while processing. |
| **E_OUTOFMEMORY** | Cannot allocate memory to complete the operation. |

## Remarks

By default, the best result string of the recognition result corresponds to the **top alternate**. However, you can use this method to specify that alternates other than the top alternate are used in the result. When you choose an alternate other than the top alternate, you are essentially choosing a different path through the lattice of alternates that are associated with the results.

To retrieve the alternates that can be used to modify the recognition result, call the [AlternatesFromSelection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms698186(v=vs.85)) method.

**Note** A call to **ModifyTopAlternate Method** may modify the [TopString](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionresult-get_topstring) and [TopAlternate](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionresult-get_topalternate) properties.

The alternate used in the function can be a word alternate in an entire sentence. For example, an alternate obtained by using [AlternatesFromSelection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms698186(v=vs.85)) (0, 5) for "Hello World" only changes the "Hello" part of the word leaving the "World" part intact.

## See also

[GetAlternatesFromSelection Method](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms698186(v=vs.85))

[IInkRecognitionAlternate Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate)

[IInkRecognitionResult Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionresult)

[TopAlternate Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionresult-get_topalternate)

[TopString Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionresult-get_topstring)