# IAutomaticUpdatesSettings2::CheckPermission

## Description

[**IAutomaticUpdatesSettings2::CheckPermission** is no longer supported. Starting with
Windows 10 calls to **CheckPermission** always return **S_OK**, and a return value of **VARIANT_TRUE** (users have permissions). However, **IAutomaticUpdatesSettings::Save** is a no-op, so no changes can be made.]

Determines whether a specific user or type of user has permission to perform a selected action.

## Parameters

### `userType` [in]

An enumeration that indicates the type of user to verify permissions.

### `permissionType` [in]

An enumeration that indicates the user's permission level.

### `userHasPermission`

True if the user has the specified permission type; otherwise, false.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

## Remarks

This method can be used to determine whether User Access Control (UAC) must be used to perform an action in the agent, which may obviate the need for prompting if the user type does not have permission to perform the action. For example, unless the agent has elevated permission, the [ReadOnly](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings-get_readonly) property of the [IAutomaticUpdatesSettings](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdatessettings) interface will always be **VARIANT_TRUE**. However, even after a user has been elevated, the [NotificationLevel](https://learn.microsoft.com/windows/desktop/api/wuapi/ne-wuapi-automaticupdatesnotificationlevel) (for example) may still be read-only due to Group Policy settings. The **CheckPermission** method can determine this before elevation is done to prevent prompting in cases where the setting cannot be changed.

## See also

[IAutomaticUpdatesSettings2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdatessettings2)