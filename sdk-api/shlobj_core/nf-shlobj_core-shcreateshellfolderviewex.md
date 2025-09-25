# SHCreateShellFolderViewEx function

## Description

Creates a new instance of the default Shell folder view object. It is recommended that you use [SHCreateShellFolderView](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shcreateshellfolderview) rather than this function.

## Parameters

### `pcsfv` [in]

Type: **[CSFV](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-csfv)***

Pointer to a structure that describes the details used in creating this instance of the Shell folder view object.

### `ppsv` [out]

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)****

The address of an [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) interface pointer that, when this function returns successfully, points to the new view object. On failure, this value is **NULL**.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

[SHCreateShellFolderView](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shcreateshellfolderview) is recommended over **SHCreateShellFolderViewEx** because of the greater flexibility of its elements to participate in various scenarios, provide new functionality to the view, and interact with other objects.

When dealing with several instances of [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview), you might want to verify which is the default Shell folder view object. To do so, call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on the object using IID_CDefView. This call succeeds only on the default Shell folder view object.

## See also

[SHCreateShellFolderView](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shcreateshellfolderview)