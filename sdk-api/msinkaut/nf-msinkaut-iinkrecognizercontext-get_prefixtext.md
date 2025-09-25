# IInkRecognizerContext::get_PrefixText

## Description

Gets or sets the characters that come before the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection in the [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) object.

This property is read/write.

## Parameters

## Remarks

The prefix helps improve recognition results by supplying the recognizer with more context about the handwriting.

Setting the **PrefixText** property succeeds only if the [Strokes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_strokes) property is **NULL**. You must set the **PrefixText** property before you attach a [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection to the **Strokes** property of the [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class), or you must set the **Strokes** property to **NULL** and then set the **PrefixText** property.

**Note** If you use the latter method, you may need to reattach the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection to the [Strokes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_strokes) property of the [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) object.

Setting the **PrefixText** property to **NULL** removes any prefix text from the recognizer context.

The prefix text is ignored unless you have set both the [IRM_Coerce](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrecognitionmodes) and **IRM_WordMode****InkRecognitionModes** flags in the [RecognitionFlags](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_recognitionflags) property.

The [SuffixText](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_suffixtext) property gets or sets the characters that come after the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection in the [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) object and also helps improve the recognition result.

If your application provides a correction interface when converting ink to text, the application may allow the user to select characters within a word and use the stylus to generate replacement characters. Your application can use the **PrefixText** and [SuffixText](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_suffixtext) properties to improve recognition of the new ink.

## See also

[IInkRecognizerContext](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrecognizercontext)

[InkRecognizerContext Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class)

[RecognitionFlags Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_recognitionflags)

[Strokes Property](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nf-msinkaut15-iinkdivisionresult-get_strokes)

[SuffixText Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_suffixtext)