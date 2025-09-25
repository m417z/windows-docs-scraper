# ITextHost::TxSetCursor

## Description

Establishes a new cursor shape (I-beam) in the text host's window.

## Parameters

### `hcur` [in]

Type: **[HCURSOR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the cursor.

### `fText` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If **TRUE**, indicates the caller is trying to set the text cursor. See the Remarks section for more information.

## Remarks

This method may be called at any time, whether the control is active or inactive.

**TxSetCursor** should be called by the text services object to set the mouse cursor. If the *fText* parameter is **TRUE**, the text services object is trying to set the text cursor (the cursor appears as an I-beam when it is over text that is not selected). In this case, the host can set it to whatever the control MousePointer property is. This is required for Microsoft Visual Basic compatibility since, through the MousePointer property, the Visual Basic programmer has control over the shape of the mouse cursor.

## See also

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

[Windowless Rich Edit Controls Overview](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)