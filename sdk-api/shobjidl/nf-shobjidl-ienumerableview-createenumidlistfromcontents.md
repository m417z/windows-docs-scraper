# IEnumerableView::CreateEnumIDListFromContents

## Description

Creates an enumerator of ID lists from the contents of the view.

## Parameters

### `pidlFolder` [in]

Type: **PCIDLIST_ABSOLUTE**

A PIDL that is relative to the Desktop.

### `dwEnumFlags` [in]

Type: **DWORD**

Specifies enumeration flags. See the [SHCONTF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shcontf) enumerated type.

### `ppEnumIDList` [out]

Type: **[IEnumIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumidlist)****

When this method returns, contains an [IEnumIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumidlist) interface pointer.

## Return value

Type: **HRESULT**

Returns a success value if successful, or an error value otherwise.