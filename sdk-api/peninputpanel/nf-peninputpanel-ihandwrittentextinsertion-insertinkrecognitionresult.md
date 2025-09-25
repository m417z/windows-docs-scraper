# IHandwrittenTextInsertion::InsertInkRecognitionResult

## Description

Inserts recognition results.

## Parameters

### `pIInkRecoResult` [in]

The [IInkRecognitionResult](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionresult) for the insertion which contains the recognition results and the collection of ink strokes for the insertion.

### `locale` [in]

The locale identifier of a specific culture for the input language of the recognizer used to produce alternates.

### `fAlternateContainsAutoSpacingInformation` [in]

Specifies whether the recognized text was generated with auto-spacing enabled on the recognized. **TRUE** if auto-spacing was enabled; otherwise, **FALSE**.

## Return value

This method can return one of these values.

## See also

[IHandWrittenTextInsertion](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-ihandwrittentextinsertion)