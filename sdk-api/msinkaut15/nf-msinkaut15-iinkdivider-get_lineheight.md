# IInkDivider::get_LineHeight

## Description

Gets or sets the expected handwriting height, in HIMETRIC units.

This property is read/write.

## Parameters

## Remarks

The **LineHeight** property must be in the range of 100 to 50,000 HIMETRIC units.

The [InkDivider](https://learn.microsoft.com/windows/desktop/tablet/inkdivider-class) object uses the **LineHeight** property to help distinguish between drawing and handwriting.

Setting the **LineHeight** property after strokes have been assigned to the [InkDivider](https://learn.microsoft.com/windows/desktop/tablet/inkdivider-class) object generates an error.

## See also

[IInkDivider](https://learn.microsoft.com/windows/win32/api/msinkaut15/nn-msinkaut15-iinkdivider)

[InkDivider Class](https://learn.microsoft.com/windows/desktop/tablet/inkdivider-class)

[Strokes Property [InkDivider Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nf-msinkaut15-iinkdivider-get_strokes)