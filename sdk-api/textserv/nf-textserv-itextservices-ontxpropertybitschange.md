# ITextServices::OnTxPropertyBitsChange

## Description

Sets properties (represented by bits) for the control.

## Parameters

### `dwMask` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Bits representing properties to be changed. For the possible bit values, see the TXTBIT_* values list in *dwBits*.

### `dwBits` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

New values for bit properties. It can be any combination of the following.

| Value | Meaning |
| --- | --- |
| **TXTBIT_ALLOWBEEP** | If **TRUE**, beeping is enabled. |
| **TXTBIT_AUTOWORDSEL** | If **TRUE**, the AutoWordSelect feature is enabled. |
| **TXTBIT_BACKSTYLECHANGE** | If **TRUE**, the backstyle changed. See [TxGetBackStyle](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetbackstyle). |
| **TXTBIT_CHARFORMATCHANGE** | If **TRUE**, the character format changed. |
| **TXTBIT_CLIENTRECTCHANGE** | If **TRUE**, the client rectangle changed. |
| **TXTBIT_DISABLEDRAG** | If **TRUE**, dragging is disabled. |
| **TXTBIT_D2DDWRITE** | Use Direct2D/DirectWrite for this instance, and not GDI/Uniscribe. |
| **TXTBIT_D2DPIXELSNAPPED** | Render glyphs to the nearest pixel positions. Valid only if D2DDWRITE is set. |
| **TXTBIT_D2DSUBPIXELLINES** | Draw lines with subpixel precision. Don't pixel-snap text lines, underline, and strikethrough in the secondary text flow direction (usually vertical). Valid only if D2DDWRITE is set and D2DPIXELSNAPPED is not set. |
| **TXTBIT_D2DSIMPLETYPOGRAPHY** | Render text using simple typography (no glyph rendering). This value is valid only if TXTBIT_D2DDWRITE is also specified. |
| **TXTBIT_EXTENTCHANGE** | If **TRUE**, the size of the client rectangle changed. |
| **TXTBIT_HIDESELECTION** | If **TRUE**, the text services object should hide the selection when the control is inactive. If **FALSE**, the selection should be displayed when the control is inactive.<br><br>Note, this implies **TXTBIT_SAVESELECTION** is **TRUE**. |
| **TXTBIT_MAXLENGTHCHANGE** | If **TRUE**, the maximum length for text in the control changed. |
| **TXTBIT_MULTILINE** | If **TRUE**, the text services object should work in multiline mode. Use the **TXTBIT_WORDWRAP** value to determine whether to wrap the lines to the view rectangle or clip them.<br><br>If **FALSE**, the text services object should not process a carriage return/line feed from the ENTER key and it should truncate incoming text containing hard line breaks just before the first line break. It is also acceptable to truncate text that is set with [ITextServices::TxSetText](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-txsettext), because it is the responsibility of the host not to use a single-line control when bound to a multiline field. |
| **TXTBIT_NOTHREADREFCOUNT** | Don't reference TLS data on behalf of this instance. |
| **TXTBIT_PARAFORMATCHANGE** | If **TRUE**, the paragraph format changed. |
| **TXTBIT_READONLY** | If **TRUE**, the text services object should not accept any editing change through the user interface. However, it should still accept programmatic changes through [EM_SETTEXTEX](https://learn.microsoft.com/windows/desktop/Controls/em-settextex), [EM_REPLACESEL](https://learn.microsoft.com/windows/desktop/Controls/em-replacesel), and [ITextServices::TxSetText](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-txsettext). Also, the user should still be able to move the insertion point, select text, and carry out other operations that don't modify content, such as Copy. |
| **TXTBIT_RICHTEXT** | If **TRUE**, the text services object should be in rich-text mode.<br><br>If **FALSE**, it is in plain-text mode.<br><br>Note, this affects how editing commands are applied. For example, applying bold to part of the text in a plain-edit control makes the entire text bold. However, for a rich-edit control, this makes only the selected text bold. |
| **TXTBIT_SAVESELECTION** | If **TRUE**, the boundaries of the selection should be saved when the control is inactive.<br><br>If **FALSE**, when the control goes active again the selection boundaries can be reset to start = 0, length = 0. |
| **TXTBIT_SCROLLBARCHANGE** | If **TRUE**, the scroll bar has changed. |
| **TXTBIT_SELBARCHANGE** | If **TRUE**, the selection bar width has changed |
| **TXTBIT_SHOWACCELERATOR** | If set, the accelerator character should be underlined.<br><br>This must be set in order to call [TxGetAcceleratorPos](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetacceleratorpos). |
| **TXTBIT_SHOWPASSWORD** | Show password strings. |
| **TXTBIT_USECURRENTBKG** | Not supported. |
| **TXTBIT_USEPASSWORD** | If **TRUE**, display text using the password character obtained by [TxGetPasswordChar](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetpasswordchar).<br><br>The notification on this property can mean either that the password character changed or that the password character was not used before but is used now (or vice versa). |
| **TXTBIT_VERTICAL** | Not supported. |
| **TXTBIT_VIEWINSETCHANGE** | If **TRUE**, the inset changed. |
| **TXTBIT_WORDWRAP** | If **TRUE** and TXTBIT_MULTILINE is also **TRUE**, multiline controls should wrap the line to the view rectangle. If this property is **FALSE** and **TXTBIT_MULTILINE** is **TRUE**, the lines should not be wrapped but clipped. The right side of the view rectangle should be ignored.<br><br>If **TXTBIT_MULTILINE** is **FALSE**, this property has no effect. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, the return value is **S_OK**.

If the method fails, the return value is the following [HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) code. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Not implemented. |

## Remarks

The client rectangle is the rectangle that the text services object is responsible for painting and managing. The host relies on the text services object for painting that area. The text services object must not paint or invalidate areas outside of that rectangle. In addition, the host will forward mouse messages to the text services object when the cursor is over this rectangle. This rectangle is expressed in client coordinates of the containing window.

The view inset is the amount of space on each side between the client rectangle and the view rectangle. The view rectangle (also called the Formatting rectangle) is the rectangle in which the text should be formatted. For more information, see [TxGetViewInset](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetviewinset).

The backstyle is the style of the background of the client rectangle. It can be either TXTBACK_TRANSPARENT or TXTBACK_SOLID. See **TXTBACKSTYLE**.

The scroll bar property indicates changes to the scroll bar: which scroll bar is present, whether scroll bars are hidden or disabled when scrolling is impossible, and also if auto-scrolling is enabled when the insertion point gets off the client rectangle.

## See also

**Conceptual**

[ITextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itextservices)

**Other Resources**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

**Reference**

[TxGetAcceleratorPos](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetacceleratorpos)

[TxGetBackStyle](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetbackstyle)

[TxGetClientRect](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetclientrect)

[TxGetPasswordChar](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetpasswordchar)

[TxSetText](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-txsettext)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)