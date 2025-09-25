# IFolderView2::GetSelectionState

## Description

Gets the selection state including check state.

## Parameters

### `pidl` [in]

Type: **PCUITEMID_CHILD**

A PIDL of the item.

### `pdwFlags` [out]

Type: **DWORD***

Zero or one of the following [_SVSIF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_svsif) constants that specify the current type of selection: **SVSI_FOCUSED**, **SVSI_SELECT**, **SVSI_CHECK**, or **SVSI_CHECK2**. Other **_SVSIF** constants are not returned by this API.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.