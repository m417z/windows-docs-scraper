# SHCreateShellFolderView function

## Description

Creates a new instance of the default Shell folder view object (DefView).

## Parameters

### `pcsfv` [in]

Type: **const [SFV_CREATE](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-sfv_create)***

Pointer to a [SFV_CREATE](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-sfv_create) structure that describes the particulars used in creating this instance of the Shell folder view object.

### `ppsv` [out]

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)****

When this function returns successfully, contains an interface pointer to the new [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) object. On failure, this value is **NULL**.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**SHCreateShellFolderView** is recommended over [SHCreateShellFolderViewEx](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shcreateshellfolderviewex) because of the greater flexibility of its elements to participate in various scenarios, provide new functionality to the view, and interact with other objects.

When dealing with several instances of [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview), you might want to verify which is the default Shell folder view object. To do so, call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on the object using the IID_CDefView IID. This call succeeds only when made on the default Shell folder view object.

Data sources that use the default Shell folder view object must implement these interfaces:

* [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)
* [IShellFolder2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder2)
* [IPersistFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipersistfolder)
* [IPersistFolder2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipersistfolder2)

Optionally, they can also implement [IPersistFolder3](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipersistfolder3).

## See also

[SFV_CREATE](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-sfv_create)

[SHCreateShellFolderViewEx](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shcreateshellfolderviewex)