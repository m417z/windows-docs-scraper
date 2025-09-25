# IImePad::Request

## Description

Called by an [IImePadApplet](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepadapplet) to insert text into an app.

**Request** is the only method that [IImePadApplet](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepadapplet) can call. By calling this method with one of the **IMEPADREQ_*** request IDs, **IImePadApplet** can insert text into an app and can control IME's composition string in an app.

## Parameters

### `pIImePadApplet` [in]

The interface pointer of the calling applet.

### `reqId` [in]

The type of request (the request ID). This must be set to one of the following values:

| Value | Meaning |
| --- | --- |
| **IMEPADREQ_INSERTSTRING** | Insert a string into the app as a composition string.<br><br>* *wParam*: Pointer to the **NULL**-terminated string (**LPWSTR**) to be inserted into the app.<br>* *lParam*: Not used. Must be set to 0. |
| **IMEPADREQ_SENDCONTROL** | Controls composition of the string and caret in the app.<br><br>* *wParam*: Specifies the control value (**IMEPADCTRL_***) that requests IME to process the composition string and caret position. See Remarks for a list of the **IMEPADCTRL_*** values.<br>* *lParam*: Not used. Must be set to 0. |
| **IMEPADREQ_SETAPPLETSIZE** | Set a new applet window size.<br><br>* *wParam*: LOWORD(*wParam*) specifies the applet's width. HIWORD(*wParam*) specifies applet's height<br>* *lParam*: Not used. Must be set to 0. |
| **IMEPADREQ_GETCOMPOSITIONSTRING** | Gets the current composition string text.<br><br>* *wParam*: Points to the buffer (**LPWSTR**) that is to receive the current composition string text.<br>* *lParam*: The maximum number of characters to copy, including the terminating null character. |
| **IMEPADREQ_GETCOMPOSITIONSTRINGINFO** | Gets information about the current composition string.<br><br>* *wParam*: Pointer to a [IMECOMPOSITIONSTRINGINFO](https://learn.microsoft.com/windows/desktop/api/imepad/ns-imepad-imecompositionstringinfo) structure that receives the composition information.<br>* *lParam*: Not used. Must be set to 0. |
| **IMEPADREQ_DELETESTRING** | Delete the composition string.<br><br>* *wParam*: LOWORD(*wParam*) specifies the start position of the composition string to be deleted.   HIWORD(*wParam*) specifies the length of the composition string to delete.<br>* *lParam*: Not used. Must be set to 0. |
| **IMEPADREQ_CHANGESTRING** | Replace part of the composition string.<br><br>* *wParam*: Pointer to the replacement string (**LPWSTR**).<br>* *lParam*: LOWORD(*lParam*) specifies the start position of the composition string to be replaced.   HIWORD(*lParam*) specifies the length of the composition string to be replaced. |
| **IMEPADREQ_GETAPPLHWND** | Gets the application window handle.<br><br>* *wParam*: The **HWND** handle address (**HWND** *) to receive the application window handle.<br>* *lParam*: Not used. Must be set to 0. |
| **IMEPADREQ_FORCEIMEPADWINDOWSHOW** | Keeps the ImePad window visible.<br><br>* *wParam*: **TRUE** to keep the IMEPad window visible.<br>* *lParam*: Not used. Must be set to 0. |
| **IMEPADREQ_POSTMODALNOTIFY** | Causes [IImePad](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepad) to call the applet's [Notify](https://learn.microsoft.com/windows/desktop/api/imepad/nf-imepad-iimepadapplet-notify) method asynchronously with a specific notification Id and user-defined data.<br><br>* *wParam*: The notify code (**IMEPN_***). See the Remarks for [IImePadApplet::Notify](https://learn.microsoft.com/windows/desktop/api/imepad/nf-imepad-iimepadapplet-notify) for the possible **IMEPN_*** codes.<br>* *lParam*: User-defined data |
| **IMEPADREQ_GETDEFAULTUILANGID** | Gets the recommended (default) ImePad applet UI Language.<br><br>* *wParam*: Address of Language ID (**LANGID** *) to receive the default UI Language.<br>* *lParam*: Not used. Must be set to 0. |
| **IMEPADREQ_GETCURRENTUILANG** | Get the current ImePad applet UI Language.<br><br>* *wParam*: Address of Language ID (**LANGID** *) to receive the current UI Language.<br>* *lParam*: Not used. Must be set to 0. |
| **IMEPADREQ_GETAPPLETUISTYLE** | Gets the applet's UI style (**IPAWS_*** flags).<br><br>* *wParam*: Address to receive the applet UI style (**DWORD** *). The style is a combination of **IPAWS_*** flags; see Remarks for the possible **IPAWS_*** flags.<br>* *lParam*: Not used. Must be set to 0. |
| **IMEPADREQ_SETAPPLETUISTYLE** | Sets the applet's UI style (**IPAWS_*** flags).<br><br>* *wParam*: Applet UI style. The style is a combination of **IPAWS_*** flags; see Remarks for the possible **IPAWS_*** flags.<br>* *lParam*: Not used. Must be set to 0. |
| **IMEPADREQ_ISAPPLETACTIVE** | Determines if the applet is active.<br><br>* *wParam*: Address to receive the value (**BOOL** *). If it's **TRUE**, the applet is active; otherwise the applet is not active.<br>* *lParam*: Not used. Must be set to 0. |
| **IMEPADREQ_ISIMEPADWINDOWVISIBLE** | Determines if ImePad is visible.<br><br>* *wParam*: Address to receive the value (**BOOL** *). If it's **TRUE**, ImePad is visible; otherwise ImePad is not visible.<br>* *lParam*: Not used. Must be set to 0. |
| **IMEPADREQ_SETAPPLETMINMAXSIZE** | Set the minimum and maximum applet size.<br><br>* *wParam*: LOWORD(*wParam*) specifies the applet width.   HIWORD(*wParam*) specifies the applet height.<br>* *lParam*: **TRUE** sets the maximum size; **FALSE** to sets the minimum size. |
| **IMEPADREQ_GETCONVERSIONSTATUS** | Gets the current application IME's conversion status. For a complete list of conversion and sentence modes, see the header file Imm.h.<br><br>* *wParam*: Address to receive the conversion mode (**DWORD** *).<br>* *lParam*: Address to receive the sentence mode (**DWORD** *). |
| **IMEPADREQ_GETVERSION** | Gets [IImePad](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepad)'s version information.<br><br>* *wParam*: Address to receive Major version (**DWORD** *).<br>* *lParam*: Address to receive Minor version (**DWORD** *). |
| **IMEPADREQ_GETCURRENTIMEINFO** | Gets the IME information that invoked ImePad.<br><br>* *wParam*: Address to receive the IME's language ID (**DWORD** *).<br>* *lParam*: Address to receive the IME's input ID (**DWORD** *). |

### `wParam` [in, out]

Additional information specific to *reqId*.

### `lParam` [in, out]

Additional information specific to *reqId*.

## Return value

**S_OK** if successful, otherwise **E_FAIL**.

## Remarks

### Possible **IMEPADCTRL_*** values

These are the possible values that *wParam* can take when *reqId* is set to **IMEPADREQ_SENDCONTROL**:

| Name | Value | Description |
| --- | --- | --- |
| **IMEPADCTRL_CONVERTALL** | 1 | Convert all composition strings. |
| **IMEPADCTRL_DETERMINALL** | 2 | Determine all composition strings. |
| **IMEPADCTRL_DETERMINCHAR** | 3 | Determine specified count's composition string character. |
| **IMEPADCTRL_CLEARALL** | 4 | Clear all composition strings. |
| **IMEPADCTRL_CARETLEFT** | 6 | Move character caret to the left. |
| **IMEPADCTRL_CARETRIGHT** | 7 | Move character caret to the right. |
| **IMEPADCTRL_CARETTOP** | 8 | Move character caret to the top of the composition string. |
| **IMEPADCTRL_CARETBOTTOM** | 9 | Move character caret to the end of the composition string. |
| **IMEPADCTRL_CARETBACKSPACE** | 10 | Delete composition string's character before the caret (like the BACKSPACE key). |
| **IMEPADCTRL_CARETDELETE** | 11 | Delete composition string's character after the caret (like the DELETE key). |
| **IMEPADCTRL_PHRASEDELETE** | 12 | Delete the composition string's phrase. |
| **IMEPADCTRL_INSERTSPACE** | 13 | Insert a space character—full width or half width depending on the IME configuration. |
| **IMEPADCTRL_INSERTFULLSPACE** | 14 | Insert full width space. |
| **IMEPADCTRL_INSERTHALFSPACE** | 15 | Insert half width space. |
| **IMEPADCTRL_ONIME** | 16 | Set IME ON. |
| **IMEPADCTRL_OFFIME** | 17 | Set IME OFF. |
| **IMEPADCTRL_ONPRECONVERSION** | 18 | Set pre-conversion ON. |
| **IMEPADCTRL_OFFPRECONVERSION** | 19 | Set pre-conversion OFF. |
| **IMEPADCTRL_PHONETICCANDIDATE** | 20 | Open IME's candidate. |

### Possible **IPAWS_*** values

These are the possible values that can be received via *wParam* when *reqId* is set to **IMEPADREQ_GETAPPLETUISTYLE**, or that *wParam* can be set to when *reqId* is set to **IMEPADREQ_SETAPPLETUISTYLE**:

| Name | Description |
| --- | --- |
| **IPAWS_ENABLED** | Show the applet as an enabled window. |
| **IPAWS_SIZINGNOTIFY** | Send the **IMEPN_SIZECHANGING** or **IMEPN_SIZECHANGED** notify code to the applet. |
| **IPAWS_VERTICALFIXED** | Vertically fixed. |
| **IPAWS_HORIZONTALFIXED** | Horizontally fixed. |
| **IPAWS_SIZEFIXED** | Size is fixed. |
| **IPAWS_MAXWIDTHFIXED** | Max width is fixed. |
| **IPAWS_MAXHEIGHTFIXED** | Max height is fixed. |
| **IPAWS_MAXSIZEFIXED** | Max size is fixed. |
| **IPAWS_MINWIDTHFIXED** | Min width is fixed. |
| **IPAWS_MINHEIGHTFIXED** | Min height is fixed. |
| **IPAWS_MINSIZEFIXED** | Min size is fixed. |

## See also

[IImePad](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepad)

[IImePadApplet](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepadapplet)

[IMECOMPOSITIONSTRINGINFO](https://learn.microsoft.com/windows/desktop/api/imepad/ns-imepad-imecompositionstringinfo)