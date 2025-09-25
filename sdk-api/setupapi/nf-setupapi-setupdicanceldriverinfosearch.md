# SetupDiCancelDriverInfoSearch function

## Description

The **SetupDiCancelDriverInfoSearch** function cancels a driver list search that is currently in progress in a different thread.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) for which a driver list is being built.

## Return value

If a driver list search is underway for the specified device information set when this function is called, the search is terminated. **SetupDiCancelDriverInfoSearch** returns **TRUE** when the termination is confirmed. Otherwise, it returns **FALSE** and a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INVALID_HANDLE.

## Remarks

**SetupDiCancelDriverInfoSearch** is a synchronous call. Therefore, it does not return until the driver search thread responds to the termination request.

## See also

[SetupDiBuildDriverInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdibuilddriverinfolist)