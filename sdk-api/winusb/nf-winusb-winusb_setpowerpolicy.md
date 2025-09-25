# WinUsb_SetPowerPolicy function

## Description

The **WinUsb_SetPowerPolicy** function sets the power policy for a device.

## Parameters

### `InterfaceHandle` [in]

An opaque handle to the first (default) interface on the device, which is returned by [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize).

### `PolicyType` [in]

A value that specifies the power policy to set. The following table describes symbolic constants that are defined in winusbio.h.

| Policy parameter | Description |
| --- | --- |
| AUTO_SUSPEND<br><br>(0x81) | Specifies the auto-suspend policy type; the power policy parameter must be specified by the caller in the *Value* parameter.<br><br>For auto-suspend, the *Value* parameter must point to a UCHAR variable. <br><br>If *Value* is **TRUE** (nonzero), the USB stack suspends the device if the device is idle. A device is idle if there are no transfers pending, or if the only pending transfers are IN transfers to interrupt or bulk endpoints. <br><br>The default value is determined by the value set in the **DefaultIdleState** registry setting. By default, this value is **TRUE**. |
| SUSPEND_DELAY<br><br>(0x83) | Specifies the suspend-delay policy type; the power policy parameter must be specified by the caller in the *Value* parameter.<br><br>For suspend-delay, *Value* must point to a ULONG variable. <br><br>*Value* specifies the minimum amount of time, in milliseconds, that the WinUSB driver must wait post transfer before it can suspend the device. <br><br>The default value is determined by the value set in the **DefaultIdleTimeout** registry setting. By default, this value is five seconds. |

### `ValueLength` [in]

The size, in bytes, of the buffer at *Value*.

### `Value` [in]

The new value for the power policy parameter. Datatype and value for *Value* depends on the type of power policy passed in *PolicyType*. For more information, see *PolicyType*.

## Return value

**WinUsb_SetPowerPolicy** returns **TRUE** if the operation succeeds. Otherwise, this function returns **FALSE**, and the caller can retrieve the logged error by calling **GetLastError**.

**GetLastError** can return the following error code.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The caller passed **NULL** in the *InterfaceHandle* parameter. |
| **ERROR_INVALID_PARAMETER** | The caller passed an invalid size for the policy parameter buffer in the *ValueLength* parameter. |
| **ERROR_NOT_ENOUGH_MEMORY** | Indicates that there is insufficient memory to perform the operation. |

## Remarks

The following list summarizes the effects of changes to power management states:

* All pipe handles, interface handles, locks, and alternate settings are preserved across power management events.
* Any transfers that are in progress are suspended when a device transfers to a low power state, and they are resumed when the device is restored to a working state.
* The device and system must be in a working state before the client can restore a device-specific configuration. Clients can determine whether the device and system are in a working state from the WM_POWERBROADCAST message.
* The client can indicate that an interface is idle by calling **WinUsb_SetPowerPolicy**.

## See also

[WinUSB](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUSB Power Management](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize)