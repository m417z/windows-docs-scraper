# IExplorerBrowser::FillFromObject

## Description

Creates a results folder and fills it with items.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

An interface pointer on the source object that will fill the [IResultsFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iresultsfolder). This can be an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) or any object that can be used with [INamespaceWalk](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-inamespacewalk).

### `dwFlags` [in]

Type: **[EXPLORER_BROWSER_FILL_FLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-explorer_browser_fill_flags)**

One of the [EXPLORER_BROWSER_FILL_FLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-explorer_browser_fill_flags) values.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The object passed via interface pointer *punk* fills [IResultsFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iresultsfolder).

The parameter *dwFlags* can be any of the [EXPLORER_BROWSER_FILL_FLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-explorer_browser_fill_flags) or any of the flags defined in [BrowseObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellbrowser-browseobject)'s *wFlags* parameter, except for flags that indicate navigation.

The parameter *punk* can be any object that [INamespaceWalk](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-inamespacewalk) can consume. If called with [EBF_SELECTFROMDATAOBJECT](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-explorer_browser_fill_flags), *punk* must be an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) and the namespace will be walked at the parent level of the data object, including all peer items, but selecting only those contained in the data object. This flag is most commonly used when [FOLDERSETTINGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-foldersettings) have *FWF_CHECKSELECT* enabled, allowing check-selection of a set of items that have been compiled in the data object.

**Note** If a pointer to an item identifier list (PIDL) in the data object is fully qualified, the parent folder cannot be successfully walked, because desktop folder items would be added to the list.

This method may be called more than once, with each successive call adding additional items to the view. [IExplorerBrowser::RemoveAll](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowser-removeall) may be called to clear the contents of the results folder. This function should be called with [EBF_NODROPTARGET](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-explorer_browser_fill_flags) to prevent users from drag dropping new items into the view, unless this is desired. Setting [EBO_NAVIGATEONCE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-explorer_browser_options) is also recommended so that the browser will stay in the ResultsFolder, preventing the user from navigating to a folder that may be represented in the data object.

To manipulate items in the results folder directly, call [IExplorerBrowser::GetCurrentView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowser-getcurrentview) to get the view from ExplorerBrowser and then ask the view for results folder using [GetFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview-getfolder). Using the obtained results folder enables manipulation of the data in the folder with more flexibility than with the methods that [IExplorerBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexplorerbrowser) provides.

## See also

[FOLDERFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderflags)

[IExplorerBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexplorerbrowser)