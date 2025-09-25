# IShellWindows::_NewEnum

## Description

Retrieves an enumerator for the collection of Shell windows.

## Parameters

### `ppunk` [out, retval]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

When this method returns, contains an interface pointer to an object that implements the [IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IShellWindows](https://learn.microsoft.com/windows/desktop/api/exdisp/nn-exdisp-ishellwindows)

[IShellWindows::Item](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-item)

[IShellWindows::get_Count](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-get_count)