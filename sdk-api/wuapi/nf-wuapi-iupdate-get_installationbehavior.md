# IUpdate::get_InstallationBehavior

## Description

Gets an interface that contains the installation options of the update.

This property is read-only.

## Parameters

## Return value

Returns S_OK if successful. Otherwise, returns a COM or Windows error code.

## Remarks

If the current update represents a bundle, the **InstallationBehavior** property of the bundle will be determined by the **InstallationBehavior** property of the child updates of the bundle. This API can return a null pointer as the output, even when the return value is S_OK.

## See also

[IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate)