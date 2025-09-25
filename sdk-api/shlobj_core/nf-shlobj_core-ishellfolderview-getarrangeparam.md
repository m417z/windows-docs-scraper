# IShellFolderView::GetArrangeParam

## Description

Gets the arrangement parameter of the view, which is how the view has been sorted.

**Note** This method is deprecated as of Windows Vista. It might be altered or unavailable in subsequent versions of Windows. We recommend that you use [IFolderView2::GetSortColumns](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview2-getsortcolumns) instead.

## Parameters

### `plParamSort` [out]

Type: **LPARAM***

The lower sixteen bits of *plParamSort* define the sorting rule. Most applications set the sorting rule to the default value of zero, indicating that the items should be sorted by name. The system does not define any other sorting rules. Some folder objects might allow calling applications to use the lower sixteen bits of *plParamSort* to specify folder-specific sorting rules. The rules and their associated *plParamSort* values are defined by the folder.

When the system folder view object calls **IShellFolderView::GetArrangeParam**, the lower sixteen bits of *plParamSort* are used to specify the column to be used for the arranging.

The upper sixteen bits of *plParamSort* are used for flags that modify the sorting rule. The system currently defines the following modifier flags.

#### SHCIDS_ALLFIELDS

[Version 5.0](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). Arrange all the information contained in the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure, not just the display names. This flag is valid only for folder objects that support the [IShellFolder2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder2) interface. For instance, if the two items are files, the folder arranges their names, sizes, file times, attributes, and any other information in the structures. If this flag is set, the lower sixteen bits of *plParamSort* must be zero.

#### SHCIDS_CANONICALONLY

[Version 5.0](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). When arranging by name, arrange the system names but not the display names. When this flag is passed, the two items are arranged by whatever criteria the Shell folder determines most efficient, as long as it implements a consistent sort function. This flag cannot be combined with other flags.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.