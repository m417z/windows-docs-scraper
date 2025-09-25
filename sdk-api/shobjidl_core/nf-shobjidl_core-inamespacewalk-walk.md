# INamespaceWalk::Walk

## Description

Initiates a recursive walk of the namespace from the specified root to the given depth.

## Parameters

### `punkToWalk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

The root node from which to begin the walk. This can be represented by one of the following objects.

* [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)
* [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)
* [IParentAndItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iparentanditem)
* [IEnumFullIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumfullidlist)
* [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)
* [IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray)
* [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)

Specifying the desktop's [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) as the root allows the possibility of walking the entire Windows namespace if *cDepth* is sufficiently large.

### `dwFlags` [in]

Type: **DWORD**

One or more of the following flags that control the walk operation.

**NSWF_DEFAULT (0x00000000)**

Use this value when you do not want to set any of the other flags.

**NSWF_NONE_IMPLIES_ALL (0x00000001)**

Collect all of the items in the folder if both of these criteria are met:

* *punkToWalk* is a folder ([IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) or [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)).
* None of the items in the folder are currently selected.

**NSWF_ONE_IMPLIES_ALL (0x00000002)**

Collect all of the items in the folder if both of these criteria are met:

* *punkToWalk* is a folder ([IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) or [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)).
* One of the items in the folder is currently selected.

**NSWF_DONT_TRAVERSE_LINKS (0x00000004)**

Do not follow links (.lnk, .url, and folder shortcuts) in the recursion; instead, return them as regular items.

**NSWF_DONT_ACCUMULATE_RESULT (0x00000008)**

Do not collect the PIDLs of the nodes during the namespace walk.

**NSWF_TRAVERSE_STREAM_JUNCTIONS (0x00000010)**

Include the contents of stream junction points in the walk. For instance, walk into the contents of a .cab file.

**NSWF_FILESYSTEM_ONLY (0x00000020)**

Walk only file system nodes.

**NSWF_SHOW_PROGRESS (0x00000040)**

Display a dialog box with a progress bar while walking the namespace.

**NSWF_FLAG_VIEWORDER (0x00000080)**

Return items in view order. This applies only when *punkToWalk* is an [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) object.

**NSWF_IGNORE_AUTOPLAY_HIDA (0x00000100)**

Do not use the AutoPlay HIDA in the data object. This applies only when *punkToWalk* is an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) object.

**NSWF_ASYNC (0x00000200)**

Perform the walk asynchronously by running it on a background thread.

**NSWF_DONT_RESOLVE_LINKS (0x00000400)**

Traverse links to return their targets (for .lnk, .url and folder shortcuts) but do not verify that those targets exist ([Resolve](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-resolve)). This is an optimization and does not affect the results except in the case where a missing or moved target could be found and returned.

**NSWF_ACCUMULATE_FOLDERS (0x00000800)**

**NSWF_DONT_SORT (0x00001000)**

Do not maintain the sort order of the items being walked.

**NSWF_USE_TRANSFER_MEDIUM (0x00002000)**

**NSWF_DONT_TRAVERSE_STREAM_JUNCTIONS (0x00004000)**

**NSWF_ANY_IMPLIES_ALL (0x00008000)**

Introduced in Windows 8.

### `cDepth` [in]

Type: **int**

The maximum depth to descend through the namespace hierarchy. This depth is zero-based. Set to 0 to walk only the folder identified by *punkToWalk* but none of its subfolders.

### `pnswcb` [in]

Type: **[INamespaceWalkCB](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nn-shobjidl_core-inamespacewalkcb)***

[INamespaceWalkCB](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nn-shobjidl_core-inamespacewalkcb) callback function used by [INamespaceWalk](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nn-shobjidl_core-inamespacewalk). This parameter can be **NULL**. The object can optionally implement the **INamespaceWalkCB2** and [IActionProgress](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nn-shobjidl_core-iactionprogress) interfaces. See remarks below.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If you do not pass the **NSWF_SHOW_PROGRESS** flag and the object pointed to by the *pnswcb* parameter implements [IActionProgress](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nn-shobjidl_core-iactionprogress), then the **INamespaceWalk::Walk** method calls the **IActionProgress::QueryCancel** method periodically to determine whether the operation should be canceled.

## See also

[INamespaceWalk](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-inamespacewalk)

[INamespaceWalkCB](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-inamespacewalkcb)