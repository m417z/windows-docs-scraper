# IInkEdit::put_InkMode

## Description

Gets or sets a value that specifies whether ink collection is disabled, ink is collected, or ink and gestures are collected.

This property is read/write.

## Parameters

## Remarks

The value of this property is always Disabled if it is used on a system that has Microsoft Windows XP Tablet PC Edition installed but no recognizers are present. If used on a system with Windows Vista or Windows XP Tablet PC Edition installed, the value can be set to any of the values in the [InkMode](https://learn.microsoft.com/windows/desktop/api/inked/ne-inked-inkmode) enumeration type.

This property should be changed only if the [Status](https://learn.microsoft.com/windows/desktop/api/inked/nf-inked-iinkedit-get_status) property returns IES_Idle.

## See also

[IInkEdit](https://learn.microsoft.com/windows/win32/api/inked/nn-inked-iinkedit)

[InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference)

[InkMode Enumeration](https://learn.microsoft.com/windows/desktop/api/inked/ne-inked-inkmode)