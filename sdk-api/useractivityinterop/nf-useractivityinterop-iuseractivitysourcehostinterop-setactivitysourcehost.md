## Description

Associates host information with either a [UserActivityChannel](https://learn.microsoft.com/uwp/api/windows.applicationmodel.useractivities.useractivitychannel) or the [UserActivity](https://learn.microsoft.com/uwp/api/windows.applicationmodel.useractivities.useractivity) object.

## Parameters

### `activitySourceHost`

An **HSTRING** containing the host to be associated with the user activity.

## Return value

If this function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

The host information for a **UserActivity** object only needs to set with this method if the **UserActivity** object was constructed from a source other than a **UserActivityChannel**, such as by using the **UserActivity** constructor.

## See also