# IMEDLG structure

## Description

Used when invoking the Microsoft IME's Dictionary Tool or Word Register Dialog Window from the app.

## Members

### `cbIMEDLG`

The size of this structure. You must set this value before using the structure.

### `hwnd`

The parent window handle of the Register Word Dialog.

### `lpwstrWord`

**NULL**, or the string to be registered. It shows in the Word Register Dialog's "Display" field.

### `nTabId`

The initial tab ID, 0 or 1.

## See also

[IFECommon::InvokeDictToolDialog](https://learn.microsoft.com/windows/desktop/api/msime/nf-msime-ifecommon-invokedicttooldialog)

[IFECommon::InvokeWordRegDialog](https://learn.microsoft.com/windows/desktop/api/msime/nf-msime-ifecommon-invokewordregdialog)