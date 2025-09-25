# OleUIChangeSourceW function

## Description

Invokes the **Change Source** dialog box, allowing the user to change the source of a link.

## Parameters

### `unnamedParam1` [in]

Pointer to the in-out [OLEUICHANGESOURCE](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuichangesourcea) structure for this dialog box.

## Return value

Standard Success/Error Definitions

| Return code | Description |
| --- | --- |
| **OLEUI_FALSE** | Unknown failure (unused). |
| **OLEUI_OK** | The user pressed the OK button. |
| **OLEUI_SUCCESS** | No error, same as OLEUI_OK. |
| **OLEUI_CANCEL** | The user pressed the Cancel button. |

Standard Field Validation Errors

| Return code | Description |
| --- | --- |
| **OLEUI_ERR_STANDARDMIN** | Errors common to all dialog boxes lie in the range OLEUI_ERR_STANDARDMIN to OLEUI_ERR_STANDARDMAX. This value allows the application to test for standard messages in order to display error messages to the user. |
| **OLEUI_ERR_STRUCTURENULL** | The pointer to an OLEUIXXX structure passed into the function was **NULL**. |
| **OLEUI_ERR_STRUCTUREINVALID** | Insufficient permissions for read or write access to an OLEUIXXX structure. |
| **OLEUI_ERR_CBSTRUCTINCORRECT** | The *cbstruct* value is incorrect. |
| **OLEUI_ERR_HWNDOWNERINVALID** | The *hWndOwner* value is invalid. |
| **OLEUI_ERR_LPSZCAPTIONINVALID** | The *lpszCaption* value is invalid. |
| **OLEUI_ERR_LPFNHOOKINVALID** | The *lpfnHook* value is invalid. |
| **OLEUI_ERR_HINSTANCEINVALID** | The *hInstance* value is invalid. |
| **OLEUI_ERR_LPSZTEMPLATEINVALID** | The *lpszTemplate* value is invalid. |
| **OLEUI_ERR_HRESOURCEINVALID** | The *hResource* value is invalid. |

Initialization Errors

| Return code | Description |
| --- | --- |
| **OLEUI_ERR_FINDTEMPLATEFAILURE** | Unable to find the dialog box template. |
| **OLEUI_ERR_LOADTEMPLATEFAILURE** | Unable to load the dialog box template. |
| **OLEUI_ERR_DIALOGFAILURE** | Dialog box initialization failed. |
| **OLEUI_ERR_LOCALMEMALLOC** | A call to [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) or the standard [IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc) allocator failed. |
| **OLEUI_ERR_GLOBALMEMALLOC** | A call to [GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) or the standard [IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc) allocator failed. |
| **OLEUI_ERR_LOADSTRING** | Unable to call LoadString for localized resources from the library. |
| **OLEUI_ERR_OLEMEMALLOC** | A call to the standard [IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc) allocator failed. |

Function Specific Errors

| Return code | Description |
| --- | --- |
| **OLEUI_ERR_STANDARDMAX** | Errors common to all dialog boxes lie in the range OLEUI_ERR_STANDARDMIN to OLEUI_ERR_STANDARDMAX. This value allows the application to test for standard messages in order to display error messages to the user. |
| **OLEUI_CSERR_LINKCNTRNULL** | The *lpOleUILinkContainer* value is **NULL**. |
| **OLEUI_CSERR_LINKCNTRINVALID** | The *lpOleUILinkContainer* value is invalid. |
| **OLEUI_CSERR_FROMNOTNULL** | The *lpszFrom* value is not **NULL**. |
| **OLEUI_CSERR_TONOTNULL** | The *lpszTo* value is not **NULL**. |
| **OLEUI_CSERR_SOURCEINVALID** | The *lpszDisplayName* or *nFileLength* value is invalid, or cannot retrieve the link source. |
| **OLEUI_CSERR_SOURCEPARSEERROR** | The *nFilename* value is wrong. |

## Remarks

The link source is not changed by the **Change Source** dialog box itself. Instead, it is up to the caller to change the link source using the returned file and item strings. The **Edit Links** dialog box typically does this for the caller.

> [!NOTE]
> The oledlg.h header defines OLEUICHANGESOURCE as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera)

[OLEUICHANGESOURCE](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuichangesourcea)

[OleUIEditLinks](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuieditlinksa)