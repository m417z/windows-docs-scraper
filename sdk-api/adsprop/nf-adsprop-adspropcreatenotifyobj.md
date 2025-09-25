# ADsPropCreateNotifyObj function

## Description

The **ADsPropCreateNotifyObj** function is used to create, or obtain, a notification object for use by an Active Directory Domain Services property sheet extension.

## Parameters

### `pAppThdDataObj` [in]

A pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) object that represents the directory object that the property page applies to. This is the **IDataObject** passed to the property page [IShellExtInit::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellextinit-initialize) method.

### `pwzADsObjName` [in]

The Active Directory Domain Services object name obtained by calling the [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) method for the [CFSTR_DSOBJECTNAMES](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/cfstr-dsobjectnames-clipboard-format) clipboard format on the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) represented by *pAppThdDataObj*.

### `phNotifyObj` [out]

Pointer to an **HWND** value that receives the handle of the notification object.

## Return value

Returns **S_OK** if successful, or an OLE-defined error value otherwise.

## Remarks

The **ADsPropCreateNotifyObj** function is used in the implementation of an Active Directory Domain Services property sheet extension. The extension must first request the [CFSTR_DSOBJECTNAMES](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/cfstr-dsobjectnames-clipboard-format) data from the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface passed to [IShellExtInit::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellextinit-initialize) by calling [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata). This provides the data object and object name required to call **ADsPropCreateNotifyObj**.

When the notification object is no longer required, a [WM_ADSPROP_NOTIFY_EXIT](https://learn.microsoft.com/windows/desktop/AD/wm-adsprop-notify-exit) message is sent to the notification object. This causes the notification object to destroy itself. When the **WM_ADSPROP_NOTIFY_EXIT** message is sent, the notification object handle should be considered invalid.

#### Examples

The following C++ example shows how to use the **ADsPropCreateNotifyObj** function.

```cpp
HWND CreateADsNotificationObject(IDataObject *pDataObject)
{
    STGMEDIUM   stm;
    FORMATETC   fe;
    HRESULT     hr;
    HWND        hwndNotifyObject = NULL;

    if(NULL == pDataObject)
    {
        return NULL;
    }

    fe.cfFormat = RegisterClipboardFormat(CFSTR_DSOBJECTNAMES);
    if(0 == fe.cfFormat)
    {
        return NULL;
    }
    fe.ptd = NULL;
    fe.dwAspect = DVASPECT_CONTENT;
    fe.lindex = -1;
    fe.tymed = TYMED_HGLOBAL;
    hr = pDataObject->GetData(&fe, &stm);
    if(SUCCEEDED(hr))
    {
        LPDSOBJECTNAMES pdson =
            (LPDSOBJECTNAMES)GlobalLock(stm.hGlobal);

        if(pdson)
        {
            LPWSTR  pwszName = (LPWSTR)((LPBYTE)pdson +
                pdson->aObjects[0].offsetName);

            hr = ADsPropCreateNotifyObj(pDataObject,
                pwszName,
                &hwndNotifyObject);

            GlobalUnlock(stm.hGlobal);
        }

        ReleaseStgMedium(&stm);
    }

    return hwndNotifyObject;
}

```

## See also

[CFSTR_DSOBJECTNAMES](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/cfstr-dsobjectnames-clipboard-format)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata)

[IShellPropSheetExt::AddPages](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellpropsheetext-addpages)

[WM_ADSPROP_NOTIFY_EXIT](https://learn.microsoft.com/windows/desktop/AD/wm-adsprop-notify-exit)