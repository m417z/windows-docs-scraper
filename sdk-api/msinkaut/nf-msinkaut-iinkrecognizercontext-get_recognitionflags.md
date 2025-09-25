# IInkRecognizerContext::get_RecognitionFlags

## Description

Gets or sets the flags that specify how the recognizer interprets the ink and determines the result string.

This property is read/write.

## Parameters

## Remarks

The **RecognitionFlags** property gets or sets flags that specify things such as whether the recognizer treats all ink as a single word or whether the recognizer coerces the result based on the factoid that you specified for the context.

Setting the **RecognitionFlags** property succeeds only if the [Strokes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_strokes) property is **NULL**.

For a list of modes that you can use, see the [InkRecognitionModes](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrecognitionmodes) enumeration type.

**Note** You can combine modes using the bitwise **OR** operator.

## See also

[IInkRecognizerContext](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrecognizercontext)

[InkRecognitionModes Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrecognitionmodes)

[InkRecognizerContext Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class)