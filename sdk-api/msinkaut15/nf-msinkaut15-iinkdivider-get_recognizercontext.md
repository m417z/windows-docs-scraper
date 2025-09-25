# IInkDivider::get_RecognizerContext

## Description

Gets or sets the [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) object that the [InkDivider](https://learn.microsoft.com/windows/desktop/tablet/inkdivider-class) object uses for layout analysis.

This property is read/write.

## Parameters

## Remarks

If you set the **RecognizerContext** property, it should be the first thing you do after constructing the [InkDivider](https://learn.microsoft.com/windows/desktop/tablet/inkdivider-class) object. An error is generated if you attempt to set the **RecognizerContext** property after the [Divider.Strokes](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nf-msinkaut15-iinkdivider-get_strokes) property has been set, after a [Divider.Divide](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nf-msinkaut15-iinkdivider-divide) call has been made, or if you attempt to set it more than one time.

In addition, this property generates an error if you assign a recognizer context to it that:

* Is not a text recognizer.
* Does not free support.

If the value of this property is **NULL** when strokes are assigned to the [InkDivider](https://learn.microsoft.com/windows/desktop/tablet/inkdivider-class) object, then the **InkDivider** object uses no recognizer context.

**Note** The [InkDivider](https://learn.microsoft.com/windows/desktop/tablet/inkdivider-class) object uses the default property settings of the [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) object, and ignores any strokes assigned to the **InkRecognizerContext** object.

## See also

[IInkDivider](https://learn.microsoft.com/windows/win32/api/msinkaut15/nn-msinkaut15-iinkdivider)

[InkDivider Class](https://learn.microsoft.com/windows/desktop/tablet/inkdivider-class)

[InkRecognizerContext Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class)