# ITextServices::TxQueryHitPoint

## Description

Tests whether a specified point is within the rectangle of the text services object.

## Parameters

### `dwDrawAspect` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Draw aspect can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DVASPECT_CONTENT** | Renders a screen image of the text content to the *hdcDraw* device context.<br><br>The *hicTargetDev* and *ptd* parameters give information on the target device context if any (usually a printer). |
| **DVASPECT_DOCPRINT** | Renders the object to the *hdcDraw* device context as though it were printed to a printer. Thus, the text services object can optimize for the printer (for example, not painting the background color, if white). Also, certain screen-specific elements (such as the selection) should not be rendered.<br><br>[ITextServices::TxGetNaturalSize](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-txgetnaturalsize) should render the *lprcClient* rectangle, starting at the current scrolling position. |

### `lindex`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Not supported.

### `pvAspect` [in]

Type: **void***

Information for drawing optimizations.

### `ptd` [in]

Type: **[DVTARGETDEVICE](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-dvtargetdevice)***

Information on the target device.

### `hdcDraw` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Rendering device context.

### `hicTargetDev` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Target information context.

### `lprcClient` [in]

Type: **LPCRECT**

The control's client rectangle, in client (device) coordinates of the view in which the hit testing is done.

### `x` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

x-coordinate to check, in client coordinates, of the view in which hit testing is done.

### `y` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

y-coordinate to check, in client coordinates, of the view in which hit testing is done.

### `pHitResult` [out]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The result of the hit test. It can be any of the following **TXTHITRESULT** enumeration values.

| Value | Meaning |
| --- | --- |
| **TXTHITRESULT_CLOSE** | The point is in the client rectangle and close to a nontransparent area. |
| **TXTHITRESULT_HIT** | The point is in the client rectangle and either over text or the background is not transparent. |
| **TXTHITRESULT_NOHIT** | The point is outside of the client rectangle. |
| **TXTHITRESULT_TRANSPARENT** | The point is in the client rectangle and either not over text or the background was transparent. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The return value is an **HRESULT** code.

## Remarks

This method allows the host to implement transparent hit testing on text.

For more information, see the Remarks section in [ITextServices::TxDraw](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-txdraw) and [ITextServices::OnTxSetCursor](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxsetcursor).

## See also

**Conceptual**

[ITextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itextservices)

[OnTxSetCursor](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxsetcursor)

**Reference**

[TxDraw](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-txdraw)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)