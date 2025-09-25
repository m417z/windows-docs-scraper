# IWMDMDevice::GetPowerSource

## Description

The **GetPowerSource** method retrieves information about the power source and the percentage of power remaining for the device.

## Parameters

### `pdwPowerSource` [out]

Pointer to a **DWORD** specifying information about the power source of the device.

The possible returned values are a bitwise **OR** of one or more of the following values.

| Flag | Description |
| --- | --- |
| WMDM_POWER_CAP_BATTERY | The media device can run on batteries. |
| WMDM_POWER_CAP_EXTERNAL | The media device can run on external power. |
| WMDM_POWER_IS_BATTERY | The media device is currently running on batteries. |
| WMDM_POWER_IS_EXTERNAL | The media device is currently running on external power. |
| WMDM_POWER_PERCENT_AVAILABLE | The percentage of power remaining was returned in *pdwPercentRemaining*. |

### `pdwPercentRemaining` [out]

If *pdwPowerSource* contains WMDM_POWER_PERCENT_AVAILABLE, a pointer to a **DWORD** specifying the percentage of power remaining in the device.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## See also

[IWMDMDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice)