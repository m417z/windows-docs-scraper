# INamespaceWalk::GetIDArrayResult

## Description

Gets a list of objects found during a namespace walk initiated by [INamespaceWalk::Walk](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-inamespacewalk-walk).

## Parameters

### `pcItems` [out]

Type: **UINT***

The number of items stored in *pppidl*

### `prgpidl` [out]

Type: **LPITEMIDLIST****

The address of a pointer to an array of PIDLs representing the items found during the namespace walk.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use **INamespaceWalk::GetIDArrayResult**, **NSWF_DONT_ACCUMULATE_RESULT** cannot be specified in the call to [INamespaceWalk::Walk](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-inamespacewalk-walk).

It is the responsibility of the calling application to free this array. Call [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) for each PIDL as well as once for the array itself.

#### Examples

The following example creates the [INamespaceWalk](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-inamespacewalk) instance, begins the walk at the desktop, walks only the desktop folder and its immediate children, retrieves the PIDLs retrieved in the walk, and frees their array.

```cpp
void NamespaceWalk_Example()
{
    // Note that error checking has been omitted for clarity.

    INamespaceWalk *pnsw = NULL;
    IShellFolder *psfDesktop = NULL;

    // Get a pointer to the desktop to use as our root node
    hr = SHGetDesktopFolder(&psfDesktop);

    // Create the INamespaceWalk instance
    hr = CoCreateInstance(CLSID_NamespaceWalker,
                          NULL,
                          CLSCTX_INPROC,
                          IID_INamespaceWalk,
                          (void **)&pnsw);

    // Walk the desktop folder and one level of subfolders
    hr = pnsw->Walk(psfDesktop, NSWF_NONE_IMPLIES_ALL, 1, NULL);

    UINT cItems;
    PIDLIST_ABSOLUTE *ppidls;

    // Retrieve the array of PIDLs gathered in the walk
    hr = pnsw->GetIDArrayResult(&cItems, &ppidls);

    // Perform some action using the PIDLs

    // The calling function is responsible for freeing the PIDL array
    FreeIDListArrayFull(ppidls, cItems);

    return;
}

void FreeIDListArrayFull(PIDLIST_ABSOLUTE *ppidls, UINT cItems)
{
    // Free the array elements
    for (UINT i = 0; i < cItems; i++)
    {
        CoTaskMemFree(ppidls[i]);
    }

    // Free the array itself
    CoTaskMemFree(ppidls);

    return;
}
```