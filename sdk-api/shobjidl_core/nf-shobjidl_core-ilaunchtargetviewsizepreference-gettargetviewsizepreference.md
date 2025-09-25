# ILaunchTargetViewSizePreference::GetTargetViewSizePreference

## Description

Retrieves the preferred view size of the application being launched.

## Parameters

### `targetSizeOnLaunch` [out]

Type: **[APPLICATION_VIEW_SIZE_PREFERENCE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-application_view_size_preference)***

Contains the address of a pointer to an [APPLICATION_VIEW_SIZE_PREFERENCE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-application_view_size_preference) for the target application.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ILaunchTargetViewSizePreference](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ilaunchtargetviewsizepreference)