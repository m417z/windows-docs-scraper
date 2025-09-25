# IExplorerBrowser::BrowseToIDList

## Description

Browses to a pointer to an item identifier list (PIDL)

## Parameters

### `pidl` [in]

Type: **PCUIDLIST_RELATIVE**

A pointer to a const [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) (item identifier list) that specifies an object's location as the destination to navigate to. This parameter can be **NULL**. For more information, see Remarks.

### `uFlags` [in]

Type: **UINT**

A flag that specifies the category of the *pidl*. This affects how navigation is accomplished. Must be the value zero, or a bitwise combination of the following values.

#### SBSP_ABSOLUTE

An absolute PIDL, relative to the desktop.

#### SBSP_RELATIVE

A relative PIDL, relative to the current folder.

#### SBSP_PARENT

Browse to the parent folder, ignore the PIDL.

#### SBSP_NAVIGATEBACK

Navigate back, ignore the PIDL.

#### SBSP_NAVIGATEFORWARD

Navigate forward, ignore the PIDL.

#### SBSP_KEEPWORDWHEELTEXT

**Windows Vista and later**. This flag indicates that any search text entered by a WordWheel (the Search box in Windows Explorer) should be preserved during this navigation, so that items at the new location are filtered in the same way they were filtered at the previous location.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The parameter *pidl* may be **NULL** if the flags specified in *uFlags* indicate navigation through the built-in TravelLog, that is, SBSP_NAVIGATEBACK or SBSP_NAVIGATEFORWARD.

 This method supports only a subset of the SBSP flags listed in the shobjidl.h file. Consequently, this method returns E_INVALIDARG if SBSP_NEWBROWSER or SBSP_EXPLOREMODE are specified in *uFlags*.

## See also

[BrowseObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellbrowser-browseobject)

[IExplorerBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexplorerbrowser)