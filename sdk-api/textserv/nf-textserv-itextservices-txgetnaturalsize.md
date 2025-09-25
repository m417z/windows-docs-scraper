# ITextServices::TxGetNaturalSize

## Description

Allows a control to be resized so it fits its content appropriately.

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
| **TXTNS_EMU** | Use English Metric Units (EMUs) instead of pixels as the measuring units for this method's parameters. |
| **TXTNS_FITTOCONTENT** | Resize the control to fit the entire text by formatting the text to the width that is passed in. The text services object returns the height of the entire text and the width of the widest line.<br><br>For example, this should be done when the user double-clicks one of the control's handles. |
| **TXTNS_FITTOCONTENT2** | Resize the control so that it fits indented content. |
| **TXTNS_FITTOCONTENT3** | Resize the control so that it fits indented content and trailing whitespace. |
| **TXTNS_FITTOCONTENTWSP** | Resize the control so that it fits unindented content and trailing whitespace. |
| **TXTNS_INCLUDELASTLINE** | For a plain-text control, include the height of the final carriage return when calculating the size. |
| **TXTNS_ROUNDTOLINE** | Resize the control to show an integral number of lines (no line is clipped). Format enough text to fill the width and height that is passed in, and then return a height that is rounded to the nearest line boundary.<br><br>**Note** The passed and returned width and height correspond to the view rectangle. The host should adjust back to the client rectangle as needed. Because these values represent the extent of the text object, they are input and output in HIMETRIC coordinates (each HIMETRIC unit is .01 millimeter), and measuring does not include any zoom factor. For a discussion of the zoom factor, see [TxGetExtent](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetextent). |

### `psizelExtent`

Type: **const SIZEL***

Not supported.

### `pwidth` [in, out]

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The width for the fitting defined by *dwMode*.

### `pheight` [in, out]

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The height for the fitting defined by *dwMode*.

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

The first four parameters are similar to equivalent parameters in [ITextServices::TxDraw](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-txdraw) and give the same information. In the case where the lines must be recalculated, it should use these values the same ways as in **ITextServices::TxDraw**.

The *pwidth* and *pheight* parameters are in/out parameters. The host passes in the tentative width and height of the natural extent of the text object. The text services object compares these values against its current cached state, and if different, recalculate lines. Then, it computes and returns the natural size, as specified by *dwMode*.

## See also

**Conceptual**

[DVTARGETDEVICE](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-dvtargetdevice)

[ITextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itextservices)

**Other Resources**

**Reference**

[TxDraw](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-txdraw)

[TxGetExtent](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetextent)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)