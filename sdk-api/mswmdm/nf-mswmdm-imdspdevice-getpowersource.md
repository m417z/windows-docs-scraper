# IMDSPDevice::GetPowerSource

## Description

The **GetPowerSource** method reports whether the device is capable of running on batteries, external power, or both, and on which type of power source it is currently running. If the device is running on batteries, this method also reports the percentage of total power remaining in the batteries.

## Parameters

### `pdwPowerSource` [out]

Pointer to a **DWORD** that receives a value indicating the current power source for the device. The value is one of the following flags.

| Flag | Description |
| --- | --- |
| WMDM_POWER_CAP_BATTERY | The media device can run on batteries. |
| WMDM_POWER_CAP_EXTERNAL | The media device can run on external power. |
| WMDM_POWER_IS_BATTERY | The media device is currently running on batteries. |
| WMDM_POWER_IS_EXTERNAL | The media device is currently running on external power. |
| WMDM_POWER_PERCENT_AVAILABLE | The percentage of power remaining was returned in *pdwPercentRemaining*. |

### `pdwPercentRemaining` [out]

If the device is running on batteries, *pdwPercentRemaining* specifies a pointer to a **DWORD** containing the percentage of total battery power remaining.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Only physical devices report power source capabilities and current power source. Software implementations of devices report no power capabilities or current power source.

This method is optional. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevice)