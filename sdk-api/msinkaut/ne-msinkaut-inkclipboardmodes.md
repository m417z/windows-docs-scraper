# InkClipboardModes enumeration

## Description

Specifies the copy options of the Clipboard.

## Constants

### `ICB_Copy:0`

The ink is copied to the Clipboard.

### `ICB_Cut:0x1`

The ink is cut and copied to the Clipboard.

### `ICB_ExtractOnly:0x30`

The ink is not copied to the Clipboard. Typically, use this option if you want to add something else, such as text, to the ink before you copy it to the Clipboard.

### `ICB_DelayedCopy:0x20`

 Delayed rendering is used to reduce the amount of data that is stored on the Clipboard. The data is rendered when a paste request is made.

### `ICB_Default:ICB_Copy`

Copy mode is used to copy the Ink.

## Remarks

You can use the DelayedCopy flag to interact directly with the data object and add additional formats to the clipboard.

**Caution** To avoid potential memory leaks as a result of using the **DelayedCopy** flag, you must call the [OleFlushClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleflushclipboard) or [OleSetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard) method. This must be done before the application exits if the last call to the [ClipboardCopy](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-clipboardcopy) method used the **DelayedCopy** flag.

To remove the pointer from the clipboard, the parameter for the [OleSetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard) should be **NULL**. For the [SetDataObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idataobjectprovider-setdataobject) method, the *data* parameter should be **NULL**, and the *copy* parameter should be **TRUE**.

The [OleSetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard) and [SetDataObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idataobjectprovider-setdataobject) methods replace the contents of the clipboard.

## See also

[ClipboardCopy Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-clipboardcopy)

[ClipboardCopyWithRectangle Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-clipboardcopywithrectangle)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)