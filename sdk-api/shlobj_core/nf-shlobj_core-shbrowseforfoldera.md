# SHBrowseForFolderA function

## Description

Displays a dialog box that enables the user to select a Shell folder.

## Parameters

### `lpbi` [in]

Type: **LPBROWSEINFO**

A pointer to a [BROWSEINFO](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-browseinfoa) structure that contains information used to display the dialog box.

## Return value

Type: **PIDLIST_ABSOLUTE**

Returns a PIDL that specifies the location of the selected folder relative to the root of the namespace. If the user chooses the **Cancel** button in the dialog box, the return value is **NULL**.

It is possible that the PIDL returned is that of a folder shortcut rather than a folder. For a full discussion of this case, see the Remarks section.

## Remarks

For Windows Vista or later, it is recommended that you use [IFileDialog](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifiledialog) with the FOS_PICKFOLDERS option rather than the SHBrowseForFolder function. This uses the Open Files dialog in pick folders mode and is the preferred implementation.

You must initialize Component Object Model (COM) before you call **SHBrowseForFolder**. If you initialize COM using [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex), you must set the COINIT_APARTMENTTHREADED flag in its *dwCoInit* parameter. You can also use [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize), which always use apartment threading. If you require drag-and-drop functionality, **OleInitialize** is recommended because it initializes the required OLE as well as COM.

**Note** If COM is initialized using [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) with the COINIT_MULTITHREADED flag, **SHBrowseForFolder** fails if the calling application uses the BIF_USENEWUI or BIF_NEWDIALOGSTYLE flag in the [BROWSEINFO](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-browseinfoa) structure.

It is the responsibility of the calling application to call [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to free the IDList returned by **SHBrowseForFolder** when it is no longer needed.

There are two styles of dialog box available. The older style is displayed by default and is not resizable. The newer style provides a number of additional features, including drag-and-drop capability within the dialog box, reordering, deletion, shortcut menus, the ability to create new folders, and other shortcut menu commands. Initially, it is larger than the older dialog box, but the user can resize it. To specify a dialog box using the newer style, set the **BIF_USENEWUI** flag in the **ulFlags** member of the [BROWSEINFO](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-browseinfoa) structure.

If you implement a callback function, specified in the **lpfn** member of the [BROWSEINFO](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-browseinfoa) structure, you receive a handle to the dialog box. One use of this window handle is to modify the layout or contents of the dialog box. Because it is not resizable, modifying the older style dialog box is relatively straightforward. Modifying the newer style dialog box is much more difficult, and not recommended. Not only does it have a different size and layout than the old style, but its dimensions and the positions of its controls change every time it is resized by the user.

If the BIF_RETURNONLYFSDIRS flag is set in the **ulFlags** member of the [BROWSEINFO](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-browseinfoa) structure, the **OK** button remains enabled for "\\server" items, as well as "\\server\share" and directory items. However, if the user selects a "\\server" item, passing the PIDL returned by **SHBrowseForFolder** to [SHGetPathFromIDList](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetpathfromidlista) fails.

### Custom Filtering

As of Windows XP, **SHBrowseForFolder** supports custom filtering on the contents of the dialog box. To create a custom filter, follow these steps.

1. Set the BIF_NEWDIALOGSTYLE flag in the **ulFlags** member of the [BROWSEINFO](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-browseinfoa) structure pointed to by the *lpbi* parameter.
2. Specify a callback function in the **lpfn** member of that same [BROWSEINFO](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-browseinfoa) structure.
3. Code the callback function to receive the BFFM_INITIALIZED and BFFM_IUNKNOWN messages. On receipt of the BFFM_IUNKNOWN message, the callback function's *lParam* parameter contains a pointer to the dialog box's implementation of [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown). Call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on that **IUnknown** to obtain a pointer to an instance of [IFolderFilterSite](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderfiltersite).
4. Create an object that implements [IFolderFilter](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderfilter).
5. Call [IFolderFilterSite::SetFilter](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderfiltersite-setfilter), passing to it a pointer to your [IFolderFilter](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderfilter). **IFolderFilter** methods can then be used to include and exclude items from the tree.
6. Once the filter is created, the [IFolderFilterSite](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderfiltersite) interface is no longer needed. Call [IFolderFilterSite::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) if you have no further use for it.

### Dealing With Shortcuts

**Note** This section applies to only Windows 2000 and earlier systems. By default, Windows XP and later systems return the PIDL of a shortcut's target rather than the shortcut itself, as long as the BIF_NOTRANSLATETARGETS flag is not set in the [BROWSEINFO](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-browseinfoa) structure.

If **SHBrowseForFolder** returns a PIDL to a shortcut, sending that PIDL to [SHGetPathFromIDList](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetpathfromidlista) returns the path of the shortcut itself rather than the path of its target. The path to the shortcut's target can be obtained by using the [IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) interface as shown in this example.

```
#include

// Macros for interface casts
#ifdef __cplusplus
#define IID_PPV_ARG(IType, ppType) IID_##IType, reinterpret_cast(static_cast(ppType))
#else
#define IID_PPV_ARG(IType, ppType) &IID_##IType, (void**)(ppType)
#endif

// Retrieves the UIObject interface for the specified full PIDL
STDAPI SHGetUIObjectFromFullPIDL(LPCITEMIDLIST pidl, HWND hwnd, REFIID riid, void **ppv)
{
    LPCITEMIDLIST pidlChild;
    IShellFolder* psf;

    *ppv = NULL;

    HRESULT hr = SHBindToParent(pidl, IID_PPV_ARG(IShellFolder, &psf), &pidlChild);
    if (SUCCEEDED(hr))
    {
        hr = psf->GetUIObjectOf(hwnd, 1, &pidlChild, riid, NULL, ppv);
        psf->Release();
    }
    return hr;
}

#define ILSkip(pidl, cb)       ((LPITEMIDLIST)(((BYTE*)(pidl))+cb))
#define ILNext(pidl)           ILSkip(pidl, (pidl)->mkid.cb)

HRESULT SHILClone(LPCITEMIDLIST pidl, LPITEMIDLIST *ppidl)
{
    DWORD cbTotal = 0;

    if (pidl)
    {
        LPCITEMIDLIST pidl_temp = pidl;
        cbTotal += sizeof (pidl_temp->mkid.cb);

        while (pidl_temp->mkid.cb)
        {
            cbTotal += pidl_temp->mkid.cb;
            pidl_temp += ILNext (pidl_temp);
        }
    }

    *ppidl = (LPITEMIDLIST)CoTaskMemAlloc(cbTotal);

    if (*ppidl)
        CopyMemory(*ppidl, pidl, cbTotal);

    return  *ppidl ? S_OK: E_OUTOFMEMORY;
}

// Get the target PIDL for a folder PIDL. This also deals with cases of a folder
// shortcut or an alias to a real folder.
STDAPI SHGetTargetFolderIDList(LPCITEMIDLIST pidlFolder, LPITEMIDLIST *ppidl)
{
    IShellLink *psl;
	
    *ppidl = NULL;

    HRESULT hr = SHGetUIObjectFromFullPIDL(pidlFolder, NULL, IID_PPV_ARG(IShellLink, &psl));

    if (SUCCEEDED(hr))
    {
        hr = psl->GetIDList(ppidl);
        psl->Release();
    }

    // It's not a folder shortcut so get the PIDL normally.
    if (FAILED(hr))
        hr = SHILClone(pidlFolder, ppidl);

    return hr;
}

// Get the target folder for a folder PIDL. This deals with cases where a folder
// is an alias to a real folder, folder shortcuts, the My Documents folder, and
// other items of that nature.
STDAPI SHGetTargetFolderPath(LPCITEMIDLIST pidlFolder, LPWSTR pszPath, UINT cchPath)
{
    LPITEMIDLIST pidlTarget;
	
    *pszPath = 0;

    HRESULT hr = SHGetTargetFolderIDList(pidlFolder, &pidlTarget);

    if (SUCCEEDED(hr))
    {
        SHGetPathFromIDListW(pidlTarget, pszPath);   // Make sure it is a path
        CoTaskMemFree(pidlTarget);
    }

    return *pszPath ? S_OK : E_FAIL;
}
```

```

// Retrieves the UIObject interface for the specified full PIDLstatic
HRESULT SHGetUIObjectFromFullPIDL(LPCITEMIDLIST pidl, HWND hwnd, REFIID riid, void **ppv)
{
    LPCITEMIDLIST pidlChild;
    IShellFolder* psf;
    *ppv = NULL;

    HRESULT hr = SHBindToParent(pidl, IID_IShellFolder, (LPVOID*)&psf, &pidlChild);
    if (SUCCEEDED(hr))
    {
        hr = psf->GetUIObjectOf(hwnd, 1, &pidlChild, riid, NULL, ppv);
        psf->Release();
    }
    return hr;
}

static HRESULT SHILClone(LPCITEMIDLIST pidl, LPITEMIDLIST *ppidl)
{
    DWORD cbTotal = 0;
    if (pidl)
    {
        LPCITEMIDLIST pidl_temp = pidl;
        cbTotal += pidl_temp->mkid.cb;

        while (pidl_temp->mkid.cb)
        {
            cbTotal += pidl_temp->mkid.cb;
            pidl_temp = ILNext(pidl_temp);
        }
    }

    *ppidl = (LPITEMIDLIST)CoTaskMemAlloc(cbTotal);
    if (*ppidl)
        CopyMemory(*ppidl, pidl, cbTotal);

    return  *ppidl ? S_OK: E_OUTOFMEMORY;
}

// Get the target PIDL for a folder PIDL. This also deals with cases of a folder
// shortcut or an alias to a real folder.
static HRESULT SHGetTargetFolderIDList(LPCITEMIDLIST pidlFolder, LPITEMIDLIST *ppidl)
{
    IShellLink *psl;
    *ppidl = NULL;

    HRESULT hr = SHGetUIObjectFromFullPIDL(pidlFolder, NULL, IID_IShellLink, (LPVOID*)&psl);
    if (SUCCEEDED(hr))
    {
        hr = psl->GetIDList(ppidl);
        psl->Release();
    }

    // It's not a folder shortcut so get the PIDL normally.
    if (FAILED(hr))
        hr = SHILClone(pidlFolder, ppidl);
    return hr;
}

// Get the target folder for a folder PIDL. This deals with cases where a folder
// is an alias to a real folder, folder shortcuts, the My Documents folder,
// and so on.
STDAPI SHGetTargetFolderPath(LPCITEMIDLIST pidlFolder, LPWSTR pszPath, UINT cchPath)
{
    LPITEMIDLIST pidlTarget;
    *pszPath = 0;

    HRESULT hr = SHGetTargetFolderIDList(pidlFolder, &pidlTarget);
    if (SUCCEEDED(hr))
    {
        SHGetPathFromIDListW(pidlTarget, pszPath);

        // Make sure it is a path
        CoTaskMemFree(pidlTarget);
    }

    return *pszPath ? S_OK : E_FAIL;
}
```

> [!NOTE]
> The shlobj_core.h header defines SHBrowseForFolder as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Open and Save as Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/open-and-save-as-dialog-boxes)