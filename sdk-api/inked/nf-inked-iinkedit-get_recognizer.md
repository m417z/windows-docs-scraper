# IInkEdit::get_Recognizer

## Description

Gets or sets the [IInkRecognizer](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizer) object to use for recognition.

This property is read/write.

## Parameters

## Remarks

This property is run time only.

This property should only be changed if the [Status](https://learn.microsoft.com/windows/desktop/api/inked/nf-inked-iinkedit-get_status) property returns IES_Idle.

If a factoid is used for the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control, it must be reapplied after setting this property.

## See also

[Factoid Constants](https://learn.microsoft.com/windows/desktop/tablet/factoid-constants)

[IInkEdit](https://learn.microsoft.com/windows/win32/api/inked/nn-inked-iinkedit)

[IInkRecognizer Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizer)

[InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference)