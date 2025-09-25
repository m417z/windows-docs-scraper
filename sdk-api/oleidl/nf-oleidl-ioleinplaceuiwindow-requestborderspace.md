# IOleInPlaceUIWindow::RequestBorderSpace

## Description

Determines whether there is space available for tools to be installed around the object's window frame while the object is active in place.

## Parameters

### `pborderwidths` [in]

A pointer to a [BORDERWIDTHS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc136564(v=vs.85)) structure containing the requested widths (in pixels) needed on each side of the window for the tools.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **INPLACE_E_NOTOOLSPACE** | The object cannot install toolbars in this window object because the implementation does not support toolbars, or there is insufficient space to install the toolbars. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

### Notes to Callers

The active in-place object calls **IOleInPlaceUIWindow::RequestBorderSpace** to ask if tools can be installed inside the window frame. These tools would be allocated between the rectangle returned by [IOleInPlaceUIWindow::GetBorder](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceuiwindow-getborder) and the [BORDERWIDTHS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc136564(v=vs.85)) structure specified in the argument to this call.

The space for the tools is not actually allocated to the object until it calls [IOleInPlaceUIWindow::SetBorderSpace](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceuiwindow-setborderspace), allowing the object to negotiate for space (such as while dragging toolbars around), but deferring the moving of tools until the action is completed.

The object can install these tools by passing the width in pixels that is to be used on each side. For example, if the object required 10 pixels on the top, 0 pixels on the bottom, and 5 pixels on the left and right sides, it would pass the following [BORDERWIDTHS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc136564(v=vs.85)) structure to **IOleInPlaceUIWindow::RequestBorderSpace**:

``` syntax
lpbw->top    = 10
lpbw->bottom =  0
lpbw->lLeft  =  5
lpbw->right  =  5
```

**Note** While executing **IOleInPlaceUIWindow::RequestBorderSpace**, do not make calls to the [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) or [GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb) functions, or a dialog box. Doing so may cause the system to deadlock. There are further restrictions on which OLE interface methods and functions can be called from within **IOleInPlaceUIWindow::RequestBorderSpace**.

### Notes to Implementers

If the amount of space an active object uses for its toolbars is irrelevant to the container, it can simply return NOERROR as shown in the following **IOleInPlaceUIWindow::RequestBorderSpace** example. Containers should not unduly restrict the display of tools by an active in-place object.

``` syntax
HRESULT InPlaceUIWindow_RequestBorderSpace(
    IOleInPlaceFrame *  lpThis,
    LPCBORDERWIDTHS     pborderwidths)
{
    // Container allows the object to have as much border space as it
    // wants.
    return NOERROR;
}
```

## See also

[IOleInPlaceUIWindow](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceuiwindow)

[IOleInPlaceUIWindow::GetBorder](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceuiwindow-getborder)

[IOleInPlaceUIWindow::SetBorderSpace](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceuiwindow-setborderspace)