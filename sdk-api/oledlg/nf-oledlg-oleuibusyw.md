# OleUIBusyW function

## Description

Invokes the standard **Busy** dialog box, allowing the user to manage concurrency.

## Parameters

### `unnamedParam1` [in]

Pointer to an [OLEUIBUSY](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuibusya) structure that contains information used to initialize the dialog box.

## Return value

This function returns the following values:

Standard Success/Error Definitions

| Return code | Description |
| --- | --- |
| **OLEUI_FALSE** | Unknown failure (unused). |
| **OLEUI_SUCCESS** | No error, same as OLEUI_OK. |
| **OLEUI_OK** | The user pressed the **OK** button. |
| **OLEUI_CANCEL** | The user has pressed the **Cancel** button and that the caller should cancel the operation. |
| **OLEUI_BZ_SWITCHTOSELECTED** | The user has pressed **Switch To** and [OleUIBusy](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuibusya) was unable to determine how to switch to the blocking application. In this case, the caller should either take measures to attempt to resolve the conflict itself, if possible, or retry the operation. **OleUIBusy** will only return OLEUI_BZ_SWITCHTOSELECTED if the user has pressed the **Switch To** button, *hTask* is **NULL** and the BZ_NOTRESPONDING flag is set. |
| **OLEUI_BZ_SWITCHTOSELECTED** | The user has pressed **Switch To** and [OleUIBusy](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuibusya) was unable to determine how to switch to the blocking application. In this case, the caller should either take measures to attempt to resolve the conflict itself, if possible, or retry the operation. **OleUIBusy** will only return OLEUI_BZ_SWITCHTOSELECTED if the user has pressed the **Switch To** button, *hTask* is **NULL** and the BZ_NOTRESPONDING flag is set. |
| **OLEUI_BZ_SWITCHTOSELECTED** | The user has pressed **Switch To** and [OleUIBusy](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuibusya) was unable to determine how to switch to the blocking application. In this case, the caller should either take measures to attempt to resolve the conflict itself, if possible, or retry the operation. **OleUIBusy** will only return OLEUI_BZ_SWITCHTOSELECTED if the user has pressed the **Switch To** button, *hTask* is **NULL** and the BZ_NOTRESPONDING flag is set. |
| **OLEUI_BZ_RETRYSELECTED** | The user has either pressed the **Retry** button or attempted to resolve the conflict (probably by switching to the blocking application). In this case, the caller should retry the operation. |
| **OLEUI_BZ_CALLUNBLOCKED** | The dialog box has been informed that the operation is no longer blocked. |

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
| **OLEUI_ERR_LOADSTRING** | Unable to call [LoadString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadstringa) for the localized resources from the library. |
| **OLEUI_ERR_OLEMEMALLOC** | A call to the standard [IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc) allocator failed. |

Function Specific Errors

| Return code | Description |
| --- | --- |
| **OLEUI_ERR_STANDARDMAX** | Errors common to all dialog boxes lie in the range OLEUI_ERR_STANDARDMIN to OLEUI_ERR_STANDARDMAX. This value allows the application to test for standard messages in order to display error messages to the user. |
| **OLEUI_BZERR_HTASKINVALID** | The hTask specified in the *hTask* member of the [OLEUIBUSY](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuibusya) structure is invalid. |

## Remarks

The standard OLE Server **Busy** dialog box notifies the user that the server application is not receiving messages. The dialog box then asks the user to cancel the operation, switch to the task that is blocked, or continue waiting.

> [!NOTE]
> The oledlg.h header defines OLEUIBUSY as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[OLEUIBUSY](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuibusya)