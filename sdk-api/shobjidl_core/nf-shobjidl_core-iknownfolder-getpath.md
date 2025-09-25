# IKnownFolder::GetPath

## Description

Retrieves the path of a known folder as a string.

## Parameters

### `dwFlags` [in]

Type: **DWORD**

Flags that specify special retrieval options. This value can be 0; otherwise, one or more of the [KNOWN_FOLDER_FLAG](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ne-shlobj_core-known_folder_flag) values.

### `ppszPath` [out]

Type: **LPWSTR***

When this method returns, contains the address of a pointer to a null-terminated buffer that contains the path. The calling application is responsible for calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to free this resource when it is no longer needed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Equivalent to [SHGetKnownFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetknownfolderpath)

## See also

[IKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfolder)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))

[SHGetKnownFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetknownfolderpath)