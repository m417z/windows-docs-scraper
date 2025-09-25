# IGetAppTrackerData::GetSuggestedPollingInterval

## Description

Retrieves the minimum interval for polling suggested by the Tracker Server.

## Parameters

### `PollingIntervalInSeconds` [out]

The Tracker Server's suggested polling interval, in seconds.

## Return value

This method can return the standard return values E_INVALIDARG and S_OK.

## Remarks

Applications that use tracker data will usually need to poll the Tracker Server periodically to ensure that this data is up-to-date. For example, an administrative application that displays tracking data to the user would typically want this data to be near as possible to real-time. However, polling too frequently can degrade overall system performance. Also keep in mind that the COM+ applications updating the data do not send updates to the Tracker Server immediately, so even in the best case there will be some delay (typically only a few seconds).

Polling frequency is a global policy that administrators can adjust, if necessary, to balance between freshness of data and performance impact for the particular set of tools in use on the systems they manage. The value returned in *PollingIntervalInSeconds* is the minimum amount of time that an application should wait after retrieving tracking data before making another call to retrieve the same data. Any application that polls the Tracker Server should call this method and adjust their polling behavior accordingly.

The polling interval is by default equal to the tracking event frequency (three seconds). This value can be adjusted by writing the following REG_DWORD registry value:

**HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\COM3**\**TrackingInfoPollingFrequency** = *minimum polling interval*

## See also

[IGetAppTrackerData](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-igetapptrackerdata)