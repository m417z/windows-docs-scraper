# IInkEdit::put_MaxLength

## Description

 Gets or sets a value indicating whether there is a maximum number of characters an [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control can hold and, if so, specifies the maximum number of characters.

This property is read/write.

## Parameters

## Remarks

The default for the **MaxLength** property is 0, indicating no maximum other than that created by memory constraints on the user's system. Any number greater than 0 indicates the maximum number of characters.

Use the **MaxLength** property to limit the number of characters a user can enter in an [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control.

If text that exceeds the **MaxLength** property setting is assigned to an [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control from code, no error occurs; however, only the maximum number of characters is assigned to the [Text](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-text) property, and extra characters are truncated. Changing this property doesn't affect the current contents of an InkEdit control, but will affect any subsequent changes to the contents.

## See also

[IInkEdit](https://learn.microsoft.com/windows/win32/api/inked/nn-inked-iinkedit)

[InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference)