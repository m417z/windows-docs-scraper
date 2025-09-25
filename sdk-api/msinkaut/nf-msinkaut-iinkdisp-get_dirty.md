# IInkDisp::get_Dirty

## Description

Gets or sets the value that specifies whether the strokes of an [InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object have been modified since the last time the ink was saved.

This property is read/write.

## Parameters

## Remarks

After ink is saved, the dirty flag is automatically cleared and the value of this property is **VARIANT_FALSE**. To save ink, call the [Save Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-save) method.

## See also

[IInkDisp](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdisp)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[Save Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-save)