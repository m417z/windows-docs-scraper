# IInkDivisionUnit::get_RotationTransform

## Description

Gets the transformation matrix that the [IInkDivisionUnit](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionunit) object uses to rotate the strokes to horizontal.

This property is read-only.

## Parameters

## Remarks

Text recognizers
perform best with horizontal handwriting. Apply this transformation to the [Strokes](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nf-msinkaut15-iinkdivisionresult-get_strokes) property of the [IInkDivisionUnit](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionunit) object before passing the strokes to an [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) object.

**Note** For an [IInkDivisionUnit](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionunit) object which represents a paragraph or drawing, this property returns **NULL**.

Use this property to level handwriting or to accurately draw lines or shapes around angled handwriting.

## See also

[IInkDivisionUnit Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionunit)

[InkTransform Class](https://learn.microsoft.com/windows/desktop/tablet/inktransform-class)