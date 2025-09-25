# ITextServices::OnTxSetCursor

## Description

Notifies the text services object to set the cursor.

## Parameters

### `dwDrawAspect` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Draw aspect can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DVASPECT_CONTENT** | Renders a screen image of the text content to the *hdcDraw* device context. The *hicTargetDev* and *ptd* parameters give information on the target device context if any (usually a printer). |
| **DVASPECT_DOCPRINT** | Renders the object to the *hdcDraw* device context as though it were printed to a printer. Thus, the text services object can optimize for the printer (for example, not painting the background color, if white). Also, certain screen-specific elements (such as the selection) should not be rendered.<br><br>**ITextServices::OnTxSetCursor** should render the *lprcClient* rectangle, starting at the current scrolling position. |

### `lindex`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Not supported.

### `pvAspect` [in]

Type: **void***

Information for drawing optimizations.

### `ptd` [in]

Type: **[DVTARGETDEVICE](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-dvtargetdevice)***

The target device.

### `hdcDraw` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Rendering device context.

### `hicTargetDev` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Target information context.

### `lprcClient` [in]

Type: **LPCRECT**

The control's client rectangle. The coordinates of the rectangle are in client coordinates of the containing window. **NULL** is a legal value.

### `x` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

x position of cursor, in the client coordinates of the containing window.

### `y` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

y position of cursor, in the client coordinates of the containing window.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, the return value is **S_OK**.

If the method fails, the return value is the following **HRESULT** code. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more illegal parameters. |

## Remarks

The text services object may remeasure as a result of this call to determine the correct cursor. The correct cursor is set through [TxSetCursor](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txsetcursor).

The *lprcClient* parameter is the client rectangle of the view of the control over which the mouse cursor is positioned. The *lprcClient* parameter is in device coordinates of the containing window in the same way the [WM_SIZE](https://learn.microsoft.com/windows/desktop/winmsg/wm-size) message is. This may not be the view that was rendered last. Furthermore, if the control is in-place active, this may not be the current active view . As a consequence, the text services object should check this rectangle against its current cache's value and determine whether recalculating the lines is necessary or not. The zoom factor should be included in this computation. For a discussion of the zoom factor, see [TxGetExtent](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetextent).

This method should be called only for screen views of the control. Therefore the device context (DC) is not passed in, but should be assumed to be a screen DC.

For more information, see the Remarks in [ITextServices::TxDraw](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-txdraw).

## See also

**Conceptual**

[ITextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itextservices)

**Other Resources**

**Reference**

[TxDraw](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-txdraw)

[TxGetExtent](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetextent)

[TxSetCursor](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txsetcursor)

[WM_SIZE](https://learn.microsoft.com/windows/desktop/winmsg/wm-size)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)