# OleUIPasteSpecialW function

## Description

Invokes the standard **Paste Special** dialog box, allowing the user to select the format of the clipboard object to be pasted or paste-linked.

## Parameters

### `unnamedParam1` [in]

A pointer to an [OLEUIPASTESPECIAL](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuipastespeciala) structure.

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
| **OLEUI_ERR_LOADSTRING** | Unable to call [LoadString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadstringa) to get localized resources from the library. |
| **OLEUI_ERR_OLEMEMALLOC** | A call to the standard [IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc) allocator failed. |

Function Specific Errors

| Return code | Description |
| --- | --- |
| **OLEUI_ERR_STANDARDMAX** | Errors common to all dialog boxes lie in the range OLEUI_ERR_STANDARDMIN to OLEUI_ERR_STANDARDMAX. This value allows the application to test for standard messages in order to display error messages to the user. |
| **OLEUI_IOERR_SRCDATAOBJECTINVALID** | The **lpSrcDataObject** member of [OLEUIPASTESPECIAL](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuipastespeciala) is invalid. |
| **OLEUI_IOERR_ARRPASTEENTRIESINVALID** | The **arrPasteEntries** member of [OLEUIPASTESPECIAL](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuipastespeciala) is invalid. |
| **OLEUI_IOERR_ARRLINKTYPESINVALID** | The **arrLinkTypes** member of [OLEUIPASTESPECIAL](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuipastespeciala) is invalid. |
| **OLEUI_PSERR_CLIPBOARDCHANGED** | The clipboard contents changed while the dialog box was displayed. |
| **OLEUI_PSERR_GETCLIPBOAARDFAILED** | The **lpSrcDataObj** member is incorrect. |

## Remarks

The design of the **Paste Special** dialog box assumes that if you are willing to permit a user to link to an object, you are also willing to permit the user to embed that object. For this reason, if any of the OLEUIPASTE_LINKTYPE flags associated with the [OLEUIPASTEFLAG](https://learn.microsoft.com/windows/desktop/api/oledlg/ne-oledlg-oleuipasteflag) enumeration are set, then the OLEUIPASTE_PASTE flag must also be set in order for the data formats to appear in the **Paste Special** dialog box.

The text displayed in the **Source** field of the standard **Paste Special** dialog box, which is implemented in Oledlg32.dll, is the null-terminated string whose offset in bytes is specified in the **dwSrcofCopy** member of the [OBJECTDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/oleidl/ns-oleidl-objectdescriptor) structure for the object to be pasted. If an **OBJECTDESCRIPTOR** structure is not available for this object, the dialog box displays whatever text may be associated with CF_LINKSOURCEDESCRIPTOR. If neither structure is available, the dialog box looks for CF_FILENAME. If CF_FILENAME is not found, the dialog box displays the string "Unknown Source".

To free an **HMETAFILEPICT** returned from the **Insert Object** or **Paste Special** dialog box, delete the attached metafile on the handle, as follows.

``` syntax
void FreeHmetafilepict(HMETAFILEPICT hmfp)
{
    if (hmfp != NULL)
    {
        LPMETAFILEPICT pmfp = GlobalLock(hmfp);

        DeleteMetaFile(pmfp->hMF);
        GlobalUnlock(hmfp);
        GlobalFree(hmfp);
    }
    else
    {
        // Handle null pointers here.
        exit(0);
    }
}
```

> [!NOTE]
> The oledlg.h header defines OLEUIPASTESPECIAL as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[OLEUIPASTEFLAG](https://learn.microsoft.com/windows/desktop/api/oledlg/ne-oledlg-oleuipasteflag)