# OleUIPromptUserA function

## Description

Displays a dialog box with the specified template and returns the response (button identifier) from the user. This function is used to display OLE warning messages, for example, Class Not Registered.

## Parameters

### `nTemplate` [in]

The resource number of the dialog box to be displayed. See Remarks.

### `hwndParent` [in]

The handle to the parent window of the dialog box.

### `...`

Optional. The title of the dialog box followed by a list of arguments for the format string in the static control (IDC_PU_TEXT) of the dialog box. The caller must be sure to pass the correct number and types of arguments.

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

## Remarks

The following dialog box templates are defined in Windows Interface Guidelines--A Guide for Designing Software. The nTemplate parameter must be a currently defined resource, however, additional templates can be added to prompt.dlg.

``` syntax
IDD_LINKSOURCEUNAVAILABLE
IDD_CANNOTUPDATELINK
IDD_SERVERNOTREG
IDD_CANNOTRESPONDVERB
IDD_SERVERNOTFOUND
```

> [!NOTE]
> The oledlg.h header defines OleUIPromptUser as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).