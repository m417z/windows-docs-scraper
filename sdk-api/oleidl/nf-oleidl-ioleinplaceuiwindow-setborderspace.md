# IOleInPlaceUIWindow::SetBorderSpace

## Description

Allocates space for the border requested in the call to [IOleInPlaceUIWindow::RequestBorderSpace](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceuiwindow-requestborderspace).

## Parameters

### `pborderwidths` [in]

Pointer to a [BORDERWIDTHS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc136564(v=vs.85)) structure containing the requested width of the tools, in pixels. It can be **NULL**, indicating the object does not need any space.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **OLE_E_INVALIDRECT** | The rectangle does not lie within the specifications returned by [IOleInPlaceUIWindow::GetBorder](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceuiwindow-getborder). |

## Remarks

The object must call **IOleInPlaceUIWindow::SetBorderSpace**. It can do any one of the following:

* Use its own toolbars, requesting border space of a specific size.
* Use no toolbars, but force the container to remove its toolbars by passing a valid [BORDERWIDTHS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc136564(v=vs.85)) structure containing nothing but zeros in the *pborderwidths* parameter.
* Use no toolbars but allow the in-place container to leave its toolbars up by passing **NULL** as the *pborderwidths* parameter.

The [BORDERWIDTHS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc136564(v=vs.85)) structure used in this call would generally have been passed in a previous call to [IOleInPlaceUIWindow::RequestBorderSpace](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceuiwindow-requestborderspace), which must have returned S_OK.

If an object must renegotiate space on the border, it can call **IOleInPlaceUIWindow::SetBorderSpace** again with the new widths. If the call to **IOleInPlaceUIWindow::SetBorderSpace** fails, the object can do a full negotiation for border space with calls to [IOleInPlaceUIWindow::GetBorder](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceuiwindow-getborder), [IOleInPlaceUIWindow::RequestBorderSpace](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceuiwindow-requestborderspace), and **IOleInPlaceUIWindow::SetBorderSpace**.

**Note** While executing **IOleInPlaceUIWindow::SetBorderSpace**, do not make calls to the [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) or [GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb) functions, or a dialog box. Doing so may cause the system to deadlock. There are further restrictions on which OLE interface methods and functions can be called from within **IOleInPlaceUIWindow::SetBorderSpace**.

## See also

[IOleInPlaceUIWindow](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceuiwindow)

[IOleInPlaceUIWindow::GetBorder](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceuiwindow-getborder)

[IOleInPlaceUIWindow::RequestBorderSpace](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceuiwindow-requestborderspace)