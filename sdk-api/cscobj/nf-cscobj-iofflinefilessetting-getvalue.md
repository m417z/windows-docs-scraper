# IOfflineFilesSetting::GetValue

## Description

Retrieves the value of a particular Offline Files setting.

## Parameters

### `pvarValue` [out]

Receives the value associated with the setting. This value is determined based on system policy, preferences and system defaults.

The method initializes the [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) prior to storing the setting value in it.

### `pbSetByPolicy` [out]

Receives **TRUE** if the value was set by policy, **FALSE** if the value was determined by preference or default.

## Return value

**S_OK** if the value query is successful or an error value otherwise.

## Remarks

The value returned in the *pvarValue* parameter is determined as follows:

1. If machine policy exists, use it.
2. Otherwise, if user policy exists, use it.
3. Otherwise, if machine preference exists, use it.
4. Otherwise, if user preference exists, use it.
5. Otherwise, use the system default value.

The primary intent of the *pbSetByPolicy* parameter is to allow the caller to disable UI associated with a setting when the setting has been configured through Group Policy.

It is important to note that policy cannot be set through the Offline Files API. Policy can be set only through the Group Policy mechanism. The Offline Files API only supports querying policy values.

## See also

[IOfflineFilesSetting](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessetting)