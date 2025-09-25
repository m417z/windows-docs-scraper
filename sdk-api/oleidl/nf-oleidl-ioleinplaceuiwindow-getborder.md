# IOleInPlaceUIWindow::GetBorder

## Description

Retrieves the outer rectangle for toolbars and controls while the object is active in place.

## Parameters

### `lprectBorder` [out]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure where the outer rectangle is to be returned. The structure's coordinates are relative to the window being represented by the interface.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **INPLACE_E_NOTOOLSPACE** | The object cannot install toolbars in this window object. |
| **E_OUTOFMEMORY** | Insufficient memory available for this operation. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

### Notes to Callers

The **IOleInPlaceUIWindow::GetBorder** function, when called on a document or frame window object, returns the outer rectangle (relative to the window) where the object can put toolbars or similar controls.

If the object is to install these tools, it should negotiate space for the tools within this rectangle using [IOleInPlaceUIWindow::RequestBorderSpace](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceuiwindow-requestborderspace) and then call [IOleInPlaceUIWindow::SetBorderSpace](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceuiwindow-setborderspace) to get this space allocated.

**Note** While executing **IOleInPlaceUIWindow::GetBorder**, do not make calls to the [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) or [GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb) functions, or a dialog box. Doing so may cause the system to deadlock. There are further restrictions on which OLE interface methods and functions can be called from within **GetBorder**.

## See also

[IOleInPlaceUIWindow](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceuiwindow)

[IOleInPlaceUIWindow::RequestBorderSpace](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceuiwindow-requestborderspace)

[IOleInPlaceUIWindow::SetBorderSpace](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceuiwindow-setborderspace)