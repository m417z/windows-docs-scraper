# OleUIConvertW function

## Description

Invokes the standard **Convert** dialog box, allowing the user to change the type of a single specified object, or the type of all OLE objects of the specified object's class.

## Parameters

### `unnamedParam1` [in]

Pointer to an [OLEUICONVERT](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuiconverta) structure that contains information used to initialize the dialog box.

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
| **OLEUI_CTERR_CLASSIDINVALID** | A **clsid** value was invalid. |
| **OLEUI_CTERR_DVASPECTINVALID** | The **dvAspect** value was invalid. This member specifies the aspect of the object. |
| **OLEUI_CTERR_CBFORMATINVALID** | The **wFormat** value was invalid. This member specifies the data format of the object. |
| **OLEUI_CTERR_STRINGINVALID** | A string value (for example, **lpszUserType** or **lpszDefLabel**) was invalid. |

## Remarks

**OleUIConvert** populates the **Convert** dialog box's list box with object classes by traversing the registry and looking for entries in the Readable and ReadWritable keys. Every class that includes the original class' default file format in its Readable key is added to the Convert list, and every class that includes the original class' default file format in its ReadWritable key is added to the Activate As list. The Convert list is shown in the dialog box's list box when the **Convert** radio button is selected (the default selection), and the Activate As list is shown when **Activate As** is selected.

Note that you can change the type of all objects of a given class only when CF_CONVERTONLY is not specified.

The convert command, which invokes this function, should only be made available to the user if [OleUICanConvertOrActivateAs](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuicanconvertoractivateas) returns S_OK.

> [!NOTE]
> The oledlg.h header defines OLEUICONVERT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[OLEUICONVERT](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuiconverta)

[OleUICanConvertOrActivateAs](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuicanconvertoractivateas)