# WinUsb_GetPowerPolicy function

## Description

The **WinUsb_GetPowerPolicy** function retrieves the power policy for a device. This is a synchronous operation.

## Parameters

### `InterfaceHandle` [in]

An opaque handle to the first interface on the device, which is returned by [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize).

### `PolicyType` [in]

A value that specifies the power policy parameter to retrieve in *Value*. The following table describes symbolic constants that are defined in *Winusbio.h*.

| Policy type | Description |
| --- | --- |
| AUTO_SUSPEND<br><br>(0x81) | If the caller specifies a power policy of AUTO_SUSPEND, **WinUsb_GetPowerPolicy** returns the value of the auto suspend policy parameter in the *Value* parameter.<br><br>If *Value* is **TRUE** (that is, nonzero), the USB stack suspends the device when no transfers are pending or the only transfers pending are IN transfers on an interrupt or bulk endpoint. <br><br>The value of the **DefaultIdleState** registry value determines the default value of the auto suspend policy parameter.<br><br>The *Value* parameter must point to a UCHAR variable. |
| SUSPEND_DELAY<br><br>(0x83) | If the caller specifies a power policy of SUSPEND_DELAY, **WinUsb_GetPowerPolicy** returns the value of the suspend delay policy parameter in *Value*.<br><br>The suspend delay policy parameter specifies the minimum amount of time, in milliseconds, that the WinUSB driver must wait after any transfer before it can suspend the device. <br><br>*Value* must point to a ULONG variable. |

### `ValueLength` [in, out]

A pointer to the size of the buffer that *Value*. On output, *ValueLength* receives the size of the data that was copied into the *Value*  buffer.

### `Value` [out]

A buffer that receives the specified power policy parameter. For more information, see *PolicyType*.

## Return value

**WinUsb_GetPowerPolicy** returns **TRUE** if the operation succeeds. Otherwise, this routine returns **FALSE**, and the caller can retrieve the logged error by calling **GetLastError**.

**GetLastError** can return the following error code.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The caller passed **NULL** in the *InterfaceHandle* parameter. |

## See also

[WinUSB](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUSB Power Management](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize)