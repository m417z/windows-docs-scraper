# EcClose function

## Description

The **EcClose** function closes a handle received from other Event Collector functions. Any handle returned by an event collector management API call must be closed using this call when the user is finished with the handle. The handle becomes invalid when this function is successfully called.

## Parameters

### `Object` [in]

A valid open handle returned from an event collector management API call.

## Return value

This function returns BOOL.

## See also

[Windows Event Collector Functions](https://learn.microsoft.com/windows/desktop/WEC/windows-event-collector-functions)