# IShellWindows::Item

## Description

Returns the registered Shell window for a specified index.

## Parameters

### `index` [in, optional]

Type: **VARIANT**

A [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) of type VT_UI4, VT_I2, or VT_I4. If the type is VT_UI4, the value of *index* is interpreted as a member of [ShellWindowTypeConstants](https://learn.microsoft.com/windows/desktop/api/exdisp/ne-exdisp-shellwindowtypeconstants); in this case, **Item** returns the window that is closest to the foreground window and has a matching type. If the type is VT_I, or VT_I4, *index* is treated as an index into the Shell windows collection.

### `Folder` [out, retval]

Type: **[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch)****

A reference to the window's [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface, or **NULL** if the specified window was not found.

## Return value

Type: **HRESULT**

One of the following values, or a standard result code.

| Return code | Description |
| --- | --- |
| **S_OK** | The specified window was found. |
| **S_FALSE** | The specified window was not found. |

## See also

[IShellWindows](https://learn.microsoft.com/windows/desktop/api/exdisp/nn-exdisp-ishellwindows)

[IShellWindows::_NewEnum](https://learn.microsoft.com/windows/win32/api/exdisp/nf-exdisp-ishellwindows-_newenum)

[IShellWindows::get_Count](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-get_count)