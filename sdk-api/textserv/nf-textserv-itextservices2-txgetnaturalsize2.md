# ITextServices2::TxGetNaturalSize2

## Description

Resizes a control so it fits its content appropriately. This method is similar to [TxGetNaturalSize](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-txgetnaturalsize), but also retrieves the ascent of the top line of text.

## Parameters

### `dwAspect`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The aspect for the drawing. It can be any of the values from the [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect) enumeration.

### `hdcDraw`

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The device context into which drawing occurs.

### `hicTargetDev`

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The device context for which text should be formatted (that is, for WYSIWYG).

### `ptd`

Type: **[DVTARGETDEVICE](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-dvtargetdevice)***

More information on the target device.

### `dwMode`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The type of fitting requested. It can be one of the following.

| Value | Meaning |
| --- | --- |
| **TXTNS_EMU** | Use English Metric Units (EMUs) instead of pixels as the measuring units (both ways) for this method's parameters. |
| **TXTNS_FITTOCONTENT** | Resize the control to fit the entire text by formatting the text to the width that is passed in. The text services object returns the height of the entire text and the width of the widest line.<br><br>For example, this should be done when the user double-clicks one of the control's handles. |
| **TXTNS_FITTOCONTENT2** | Resize the control so that it fits indented content. |
| **TXTNS_FITTOCONTENT3** | Resize the control so that it fits indented content and trailing white space. |
| **TXTNS_FITTOCONTENTWSP** | Resize the control so that it fits unindented content and trailing white space. |
| **TXTNS_INCLUDELASTLINE** | For a plain-text control, include the height of the final carriage return when calculating the size. |
| **TXTNS_ROUNDTOLINE** | Resize the control to show an integral number of lines (no line is clipped). Format enough text to fill the width and height that is passed in, and then return a height that is rounded to the nearest line boundary.<br><br>**Note** The passed and returned width and height correspond to the view rectangle. The host should adjust back to the client rectangle as needed. Because these values represent the extent of the text object, they are input and output in HIMETRIC coordinates (each HIMETRIC unit is 0.01 millimeter), and measuring does not include any zoom factor. For a discussion of the zoom factor, see [TxGetExtent](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetextent). |

### `psizelExtent`

Type: **const SIZEL***

Sizes of extents (in HIMETRIC units) to use for zooming.

### `pwidth`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The width for the fitting defined by *dwMode*.

### `pheight`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The height for the fitting defined by *dwMode*.

### `pascent`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

For single-line controls, receives the ascent (units above the baseline) of characters in the top line of text.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, the return value is **S_OK**.

If text services could not activate the object, the return value is one of the following **HRESULT** codes. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_FAIL** | Unable to determine correct size. |
| **E_INVALIDARG** | One or more arguments are not valid. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

The first four parameters are similar to equivalent parameters in [ITextServices::TxDraw](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-txdraw) and give the same information. In the case where the lines must be recalculated, **TxGetNaturalSize2** uses these values in the same ways as in **ITextServices::TxDraw**.

The *pwidth* and *pheight* parameters are in/out parameters. The host passes in the tentative width and height of the natural extent of the text object. The text services object compares these values against its current cached state, and if different, recalculates lines. Then, it computes and returns the natural size, as specified by *dwMode*.

#### Examples

The following example shows how to initialize the *psizelExtent* parameter for to a zoom factor of 1:1. The ellipses indicate code that you need to provide.

```cpp

LONG dxpi = GetDeviceCaps(hdc, LOGPIXELSX);
LONG dypi = GetDeviceCaps(hdc, LOGPIXELSY);
LONG dyAscent = 0;
LONG dx = ... ;  // Text image width, in pixels
LONG dy = ... ;  // Text image height, in pixels
SIZEL sizel;     // dx and dy, in HIMETRIC

ITextServices2 *pserv = ... ; // Interface for single-line control

sizel.cx = MulDiv(dx, HIMETRIC_PER_INCH, dxpi);
sizel.cy = MulDiv(dy, HIMETRIC_PER_INCH, dypi);

pserv->TxGetNaturalSize2(DVASPECT_DOCPRINT, hdc, hdcNil, pNil,
    TXTNS_FITTOCONTENT, &sizel, &dx, &dy, &dyAscent)))

```

## See also

[ITextServices2](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itextservices2)