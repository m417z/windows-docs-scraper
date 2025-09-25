# IShellView2::GetView

## Description

Requests the current or default Shell view, together with all other valid view identifiers (VIDs) supported by this implementation of [IShellView2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview2).

## Parameters

### `pvid` [out]

Type: **SHELLVIEWID***

A pointer to the GUID of the requested view. The following views are defined in Shlguid.h.

#### VID_LargeIcons

{0057D0E0-3573-11CF-AE69-08002B2E1262}

#### VID_SmallIcons

{089000C0-3573-11CF-AE69-08002B2E1262}

#### VID_List

{0E1FA5E0-3573-11CF-AE69-08002B2E1262}

#### VID_Details

{137E7700-3573-11CF-AE69-08002B2E1262}

#### VID_Tile

{65F125E5-7BE1-4810-BA9D-D271C8432CE3}

### `uView` [in]

Type: **ULONG**

The type of view requested.

#### SV2GV_CURRENTVIEW

Current Shell view.

#### SV2GV_DEFAULTVIEW

Default Shell view.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a standard COM error code otherwise.

## Remarks

**IShellView2::GetView** retrieves a "viewset", which is the requested view (default or current) together with all other valid views for this instance of [IShellView2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview2). Calling **IShellView2::GetView** with the **SV2GV_CURRENTVIEW** returns a GUID representing the current view and also iterates through the valid VIDs. This information is stored for later use in validating a new view before it is displayed.

The view can also be affected by other factors. A global user default VID and [view mode](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderviewmode) is set when the user presses the **Apply to All Folders** button in the **Folder Options** window. The VID is determined from **IShellView2::GetView** with the **SV2GV_CURRENTVIEW** flag
and the view mode is determined from [GetCurrentInfo](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellview-getcurrentinfo). The view can also be affected by the persisted folder default. Windows Explorer saves the VID and view mode of a folder if the user has previously visited it. In some cases, the folder you are navigating from also can influence the view mode created for the new view that you are entering.

The priority of these assorted views can be generally said to be the following:

1. Persisted folder default
2. Global user default
3. Default view (SV2GV_DEFAULTVIEW)
4. Previous view

The priority of the previous view can be higher if the **Remember each folder's view settings** option is not selected in **Folder Options**. Other factors such as policies can also come into play, so the list above should be viewed only as a very broad guideline.