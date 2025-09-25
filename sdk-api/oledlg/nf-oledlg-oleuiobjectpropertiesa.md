# OleUIObjectPropertiesA function

## Description

Invokes the **Object Properties** dialog box, which displays **General**, **View**, and **Link** information about an object.

## Parameters

### `unnamedParam1` [in]

Pointer to the [OLEUIOBJECTPROPS](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuiobjectpropsa) structure.

## Return value

Standard Success/Error Definitions

| Return code | Description |
| --- | --- |
| **OLEUI_FALSE** | Unknown failure (unused). |
| **OLEUI_OK** | The user pressed the **OK** button. |
| **OLEUI_SUCCESS** | No error, same as OLEUI_OK. |
| **OLEUI_CANCEL** | The user pressed the **Cancel** button. |

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
| **OLEUI_OPERR_SUBPROPNULL** | *lpGP* or *lpVP* is **NULL**, or *dwFlags* and OPF_OBJECTISLINK and *lpLP* are **NULL**. |
| **OLEUI_OPERR_SUBPROPINVALID** | Insufficient write-access permissions for the structures pointed to by *lpGP*, *lpVP*, or *lpLP*. |
| **OLEUI_OPERR_PROPSHEETNULL** | The *lpLP* value is **NULL**. |
| **OLEUI_OPERR_PROPSHEETINVALID** | Insufficient write-access permissions for the structures pointed to by *lpGP*, *lpVP*, or *lpLP*. |
| **OLEUI_OPERR_SUPPROP** | The sub-link property pointer, *lpLP*, is **NULL**. |
| **OLEUI_OPERR_PROPSINVALID** | Insufficient write access for the sub-link property pointer, *lpLP*. |
| **OLEUI_OPERR_PAGESINCORRECT** | Some sub-link properties of the *lpPS* member are incorrect. |
| **OLEUI_OPERR_INVALIDPAGES** | Some sub-link properties of the *lpPS* member are incorrect. |
| **OLEUI_OPERR_NOTSUPPORTED** | A sub-link property of the *lpPS* member is incorrect. |
| **OLEUI_OPERR_DLGPROCNOTNULL** | A sub-link property of the *lpPS* member is incorrect. |
| **OLEUI_OPERR_LPARAMNOTZERO** | A sub-link property of the *lpPS* member is incorrect. |
| **OLEUI_GPERR_STRINGINVALID** | A string value (for example, *lplpszLabel* or *lplpszType*) is invalid. |
| **OLEUI_GPERR_CLASSIDINVALID** | The *clsid* value is invalid. |
| **OLEUI_GPERR_LPCLSIDEXCLUDEINVALID** | The *ClsidExcluded* value is invalid. |
| **OLEUI_GPERR_CBFORMATINVALID** | The *wFormat* value is invalid. |
| **OLEUI_VPERR_METAPICTINVALID** | The *hMetaPict* value is invalid. |
| **OLEUI_VPERR_DVASPECTINVALID** | The *dvAspect* value is invalid. |
| **OLEUI_OPERR_PROPERTYSHEET** | The *lpPS* value is incorrect. |
| **OLEUI_OPERR_OBJINFOINVALID** | The *lpObjInfo* value is **NULL** or the calling process doesn't have read access. |
| **OLEUI_OPERR_LINKINFOINVALID** | The *lpLinkInfo* value is **NULL** or the calling process doesn't have read access. |

## Remarks

**OleUIObjectProperties** is passed an [OLEUIOBJECTPROPS](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuiobjectpropsa) structure, which supplies the information needed to fill in the **General**, **View**, and **Link** tabs of the **Object Properties** dialog box.

> [!NOTE]
> The oledlg.h header defines OleUIObjectProperties as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[IOleUILinkInfo](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkinfoa)

[IOleUIObjInfo](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuiobjinfoa)

[OLEUIGNRLPROPS](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuignrlpropsa)

[OLEUILINKPROPS](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuilinkpropsa)

[OLEUIOBJECTPROPS](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuiobjectpropsa)

[OLEUIVIEWPROPS](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuiviewpropsa)