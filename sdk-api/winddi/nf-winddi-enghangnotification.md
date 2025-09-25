# EngHangNotification function

## Description

The **EngHangNotification** function notifies the system that a specified device is inoperable or unresponsive.

## Parameters

### `hdev`

Handle to the physical device that has stopped. This parameter is the GDI handle received by the driver's [DrvCompletePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcompletepdev) entry point.

### `Reserved`

Is reserved and must be set to **NULL**.

## Return value

**EngHangNotification** returns one of the following values:

| Return code | Description |
| --- | --- |
| **EHN_ERROR** | The device did not recover from the error. |
| **EHN_RESTORED** | The device was restored to working order. |

## Remarks

A driver should make this call any time it detects that the hardware is inoperable or unresponsive. If **EngHangNotification** returns EHN_RESTORED, the driver should retry the operation that detected the inoperable state; otherwise the driver should fail the current call as soon as possible. Any subsequent driver operations that detect a problem should again call **EngHangNotification**.

## See also

[DrvCompletePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcompletepdev)

[DrvResetDevice](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvresetdevice)