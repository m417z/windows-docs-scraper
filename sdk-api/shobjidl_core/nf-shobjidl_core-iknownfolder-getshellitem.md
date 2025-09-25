# IKnownFolder::GetShellItem

## Description

Retrieves the location of a known folder in the Shell namespace in the form of a Shell item ([IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) or derived interface).

## Parameters

### `dwFlags` [in]

Type: **DWORD**

Flags that specify special retrieval options. This value can be 0; otherwise, one or more of the [KNOWN_FOLDER_FLAG](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ne-shlobj_core-known_folder_flag) values.

### `riid`

Type: **REFIID**

A reference to the IID of the requested interface.

### `ppv` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riid*. This is typically [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) or [IShellItem2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem2).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfolder)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))