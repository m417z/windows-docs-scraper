# IFolderFilter::ShouldShow

## Description

Specifies whether an individual item should be allowed through the filter and which should be blocked. When used with [SHBrowseForFolder](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shbrowseforfoldera), specifies which items should be shown in the dialog box tree view and which should not. The determination to show or not show an item is up to the application.

## Parameters

### `psf` [in]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to the folder's [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) interface.

### `pidlFolder` [in]

Type: **PCIDLIST_ABSOLUTE**

The PIDL of the folder.

### `pidlItem` [in]

Type: **PCUITEMID_CHILD**

The relative PIDL of the child item of *pidlFolder* in question.

## Return value

Type: **HRESULT**

Returns S_OK if the item should be shown, S_FALSE if it should not be shown, or a standard error code if an error is encountered. If an error is encountered, the item is not shown.

## Remarks

The host calls this method for each item in the folder referred to by *psf* or *pidlFolder*.

It is recommended that your implementation convert the *psf* and *pidlItem* information into an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem), which is easier to consume. The following example shows this:

```
STDMETHODIMP ShouldShow(IShellFolder *psf,
                        PCIDLIST_ABSOLUTE pidlFolder,
                        PCUITEMID_CHILD pidlItem)
{
    IShellItem *psi;

    HRESULT hr = SHCreateItemWithParent(NULL, psf, pidlItem, IID_PPV_ARGS(&psi));
    if (SUCCEEDED(hr))
    {
        // Determine here whether the item should be shown. This determination
        // is application-dependent.

        psi->Release();
    }

    return hr;
}
```

## See also

[IFolderFilter](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderfilter)