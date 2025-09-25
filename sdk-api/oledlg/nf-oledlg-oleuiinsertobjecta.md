# OleUIInsertObjectA function

## Description

Invokes the standard **Insert Object** dialog box, which allows the user to select an object source and class name, as well as the option of displaying the object as itself or as an icon.

## Parameters

### `unnamedParam1` [in]

 Pointer to the in-out [OLEUIINSERTOBJECT](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuiinsertobjecta) structure for this dialog box.

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
| **OLEUI_IOERR_LPSZFILEINVALID** | The **lpszFile** value is invalid or user has insufficient write access permissions.This **lpszFile** member points to the name of the file linked to or inserted. |
| **OLEUI_IOERR_PPVOBJINVALID** | The *ppvOjb* value is invalid. This member points to the location where the pointer for the object is returned. |
| **OLEUI_IOERR_LPIOLECLIENTSITEINVALID** | The **lpIOleClientSite** value is invalid. This member points to the client site for the object. |
| **OLEUI_IOERR_LPISTORAGEINVALID** | The **lpIStorage** value is invalid. This member points to the storage to be used for the object. |
| **OLEUI_IOERR_SCODEHASERROR** | The **sc** member of *lpIO* has additional error information. |
| **OLEUI_IOERR_LPCLSIDEXCLUDEINVALID** | The **lpClsidExclude** value is invalid. This member contains the list of CLSIDs to exclude. |
| **OLEUI_IOERR_CCHFILEINVALID** | The **cchFile** or **lpszFile** value is invalid. The **cchFile** member specifies the size of the **lpszFile** buffer. The **lpszFile** member points to the name of the file linked to or inserted. |

## Remarks

**OleUIInsertObject** allows the user to select the type of object to be inserted from a list box containing the object applications registered on the user's system. To populate that list box, **OleUIInsertObject** traverses the registry, adding every object server it finds that meets the following criteria:

* The registry entry does not include the NotInsertable key.
* The registry entry includes an OLE 1.0 style Protocol\\StdFileEditing\\Server key.
* The registry entry includes the Insertable key.
* The object's CLSID is not included in the list of objects to exclude (the **lpClsidExclude** member of [OLEUIINSERTOBJECT](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuiinsertobjecta)).

By default, **OleUIInsertObject** does not validate object servers, however, if the IOF_VERIFYSERVEREXIST flag is included in the dwFlags member of the [OLEUIINSERTOBJECT](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuiinsertobjecta) structure, **OleUIInsertObject** verifies that the server exists. If it does not exist, then the server's object is not added to the list of available objects. Server validation is a time-extensive operation and is a significant performance factor.

To free an **HMETAFILEPICT** returned from the **Insert Object** or **Paste Special** dialog box, delete the attached metafile on the handle, as follows:

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
> The oledlg.h header defines OLEUIINSERTOBJECT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[OLEUIINSERTOBJECT](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuiinsertobjecta)

[OpenFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfile)