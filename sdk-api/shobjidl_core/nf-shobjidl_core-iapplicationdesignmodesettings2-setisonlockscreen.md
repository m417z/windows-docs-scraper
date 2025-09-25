# IApplicationDesignModeSettings2::SetIsOnLockScreen

## Description

This method determines whether or not the application, in design mode, can display information on the Windows 8 lock screen.

## Parameters

### `isOnLockScreen` [in]

Type: **BOOL**

When set to **TRUE**, the application will display information on the lock screen. When set to **FALSE**, information will not be displayed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IApplicationDesignModeSettings2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationdesignmodesettings2)