# IInkRecognizerContext::get_SuffixText

## Description

Gets or sets the characters that come after the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection in the [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) object.

This property is read/write.

## Parameters

## Remarks

The suffix helps improve recognition results by supplying the recognizer with more context about the handwriting.

Setting the **SuffixText** property succeeds only if the [Strokes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_strokes) property is **NULL**. You must set the **SuffixText** property before you attach an [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection to the **Strokes** property of the [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class), or you must set the **Strokes** property to **NULL** and then set the **SuffixText** property.

**Note** If you use the latter method, you may need to reattach the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection to the [Strokes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_strokes) property of the [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) object.

Setting the **SuffixText** property to **NULL** removes any suffix text from the recognizer context.

The suffix text is ignored unless you have set both the [Coerce](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrecognitionmodes) and **WordMode****InkRecognitionModes** flags in the [RecognitionFlags](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_recognitionflags) property.

The [PrefixText](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_prefixtext) property gets or sets the characters that come before the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection in the [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) object and also helps improve the recognition result.

If your application provides a correction interface when converting ink to text, the application may allow the user to select characters within a word and use the stylus to generate replacement characters. Your application can use the [PrefixText](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_prefixtext) and **SuffixText** properties to improve recognition of the new ink.

## See also

[IInkRecognizerContext](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrecognizercontext)

[InkRecognizerContext Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class)

[PrefixText Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_prefixtext)

[RecognitionFlags Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_recognitionflags)

[Strokes Property](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nf-msinkaut15-iinkdivisionresult-get_strokes)