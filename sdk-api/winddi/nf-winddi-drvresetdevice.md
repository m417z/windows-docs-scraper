# DrvResetDevice function

## Description

The **DrvResetDevice** function resets a device that is inoperable or unresponsive.

## Parameters

### `dhpdev`

Handle to the physical device's PDEV that describes the physical device that has stopped. This is the value returned by [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev).

### `Reserved`

Is reserved and must be set to **NULL**.

## Return value

**DrvResetDevice** should return one of the following values:

| Return code | Description |
| --- | --- |
| **DRD_ERROR** | The device did not recover from the error. |
| **DRD_SUCCESS** | The device is currently in working order. |

## Remarks

This function is available in Windows XP and later.

**DrvResetDevice** is usually called in response to [EngHangNotification](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enghangnotification). A driver should take any steps necessary to restore the device to working order, and should do so with no data loss or as little as possible.

## See also

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[EngHangNotification](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enghangnotification)