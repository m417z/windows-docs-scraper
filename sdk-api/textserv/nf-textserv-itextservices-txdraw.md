# ITextServices::TxDraw

## Description

Draws the text services object.

## Parameters

### `dwDrawAspect` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the aspect to be drawn, that is, how the object is to be represented. Draw aspect can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DVASPECT_CONTENT** | Renders a screen image of the text content to the *hdcDraw* device context.<br><br> The *hicTargetDev* and *ptd* parameters give information on the target device context if any (usually a printer). |
| **DVASPECT_DOCPRINT** | Renders the object to the *hdcDraw* device context as though it were printed to a printer. Thus, the text services object can optimize for the printer (for example, not painting the background color, if white). Also, certain screen-specific elements (such as the selection) should not be rendered.<br><br>**ITextServices::TxDraw** should render the *lprcBounds* rectangle, starting at the current scrolling position. |

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

### `lprcBounds` [in]

Type: **LPCRECTL**

The bounding (client) rectangle.

### `lprcWBounds` [in]

Type: **LPCRECTL**

The clipping rectangle for metafiles.

### `lprcUpdate` [in]

Type: **LPRECT**

The update region inside *lprcBounds*.

### `pfnContinue`

Type: **BOOL CALLBACK***

Not supported.

### `dwContinue`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Parameter to pass to continue function.

### `lViewId`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the view to draw.

| Value | Meaning |
| --- | --- |
| **TXTVIEW_ACTIVE** | Draw the inplace active view. |
| **TXTVIEW_INACTIVE** | Draw a view other than the inplace active view; for example, a print preview. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The return value is typically **S_OK**.

## Remarks

This method renders the text services object. It accepts the same parameters as the corresponding [IViewObject::Draw](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw) method in OLE, with the extra *lprcUpdate* and the *lViewId* parameters. It can be used while the host is in-place active or inactive.

The *lprcBounds* parameter gives the rectangle to render, also called the client rectangle. This rectangle represents the position and extent of the entire image of the text services object to be drawn. It is expressed in the logical coordinate system of *hdcDraw*. If *lprcBounds* is **NULL** then the control must be active. In this case, the text services object should render the in-place active view (that is, the client rectangle that can be obtained by calling [TxGetClientRect](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetclientrect) on the host).

If the *lprcUpdate* parameter is not **NULL**, it gives the rectangle to update inside that client rectangle, in the logical coordinate system of *hdcDraw*. If *lprcUpdate* is **NULL**, the entire client rectangle should be painted.

The text services object should render with the appropriate zoom factor, which can be obtained from the client rectangle and the native size given by [TxGetExtent](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetextent). For a discussion of the zoom factor, see **TxGetExtent**.

General comments on OLE hosts and **ITextServices::TxDraw** (also for [ITextServices::OnTxSetCursor](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxsetcursor), and [ITextServices::TxQueryHitPoint](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-txqueryhitpoint)):

An OLE host can call the **ITextServices::TxDraw** method at any time with any rendering device context or client rectangle. An OLE object that is inactive only retains an extent. To get the rectangle in which to render, the host calls the [IViewObject::Draw](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw) method. This rectangle is valid only for the scope of that method. Thus, the same control can be rendered consecutively in different rectangles and different device contexts, for example, because it is displayed simultaneously in different views on the screen.

Normally, the client rectangle and device context passed to **ITextServices::TxDraw** should not be cached, because this would force the text services object to recalculate lines for every draw, which would impede performance. Instead, the text services object could cache the information that is computed for a specific client rectangle and device context (such as line breaks). On the next call to **ITextServices::TxDraw**, however, the validity of the cached information should be checked before it gets used, and updated information should be regenerated, if necessary.

Also, take great care when the control is in-place active. This problem is even more complex since **ITextServices::TxDraw** can still be called to render other views than the one that is in-place active. In other words, the client rectangle passed to **ITextServices::TxDraw** may not be the same as the active one (passed to [ITextServices::OnTxInPlaceActivate](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxinplaceactivate) and obtained through [TxGetClientRect](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetclientrect) on the host).

## See also

**Conceptual**

[DVTARGETDEVICE](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-dvtargetdevice)

[ITextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itextservices)

[IViewObject::Draw](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw)

[OnTxInPlaceActivate](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxinplaceactivate)

**Other Resources**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl)

**Reference**

[TxGetClientRect](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetclientrect)

[TxGetExtent](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetextent)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)