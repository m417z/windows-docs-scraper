# IInkEdit::put_SelInks

## Description

Gets or sets the array of embedded [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) objects (if displayed as ink) in the current selection.

This property is read/write.

## Parameters

## Remarks

Ink must be recognized before being accessed through this property. If it is not recognized first, the **SelInks** property always contains zero [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) objects. You must either call the [Recognize](https://learn.microsoft.com/windows/desktop/api/inked/nf-inked-iinkedit-recognize) method (if the [RecognitionTimeout](https://learn.microsoft.com/windows/desktop/api/inked/nf-inked-iinkedit-get_recognitiontimeout) property equals 0) or wait until the ink is automatically recognized (when the value of the **RecognitionTimeout** property is greater than 0) to access ink through this property.

The [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control ignores any [InkDrawingAttributes](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class) on ink set through the **SelInks** property. Instead, the InkEdit control applies alternate drawing attributes according to the attributes of nearby text.

This property is run time only.

## See also

[IInkEdit](https://learn.microsoft.com/windows/win32/api/inked/nn-inked-iinkedit)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference)

[RecoTimeout Property](https://learn.microsoft.com/windows/desktop/api/inked/nf-inked-iinkedit-get_recognitiontimeout)

[Recognize Method [InkEdit Control]](https://learn.microsoft.com/windows/desktop/api/inked/nf-inked-iinkedit-recognize)