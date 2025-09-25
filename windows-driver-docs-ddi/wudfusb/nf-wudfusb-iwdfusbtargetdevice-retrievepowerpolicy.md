# IWDFUsbTargetDevice::RetrievePowerPolicy

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **RetrievePowerPolicy** method retrieves a WinUsb power policy.

## Parameters

### `PolicyType` [in]

The type of WinUsb power policy that the UMDF driver requests.

### `ValueLength` [in, out]

A pointer to a variable that, on input, contains the size, in bytes, of the buffer that **RetrievePowerPolicy** supplies in *Value*. On output, this parameter contains the size that **RetrievePowerPolicy** requires for *Value*.

### `Value` [out]

A pointer that receives the buffer that contains the WinUsb power policy.

## Return value

**RetrievePowerPolicy** returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | [RetrievePowerPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetdevice-retrievepowerpolicy) successfully retrieved the WinUsb power policy. |
| **E_OUTOFMEMORY** | [RetrievePowerPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetdevice-retrievepowerpolicy) encountered an allocation failure. |
| **An error code that is defined in Winerror.h** | This value corresponds to the error code that the WinUsb API returned. |

## Remarks

Power policy controls the power management that WinUsb for the device performs.

For information about valid policy types that a UMDF driver can pass for the *PolicyType* parameter and values that the framework returns, see the [WinUsb_GetPowerPolicy](https://learn.microsoft.com/windows/win32/api/winusb/nf-winusb-winusb_getpowerpolicy) function.

For more information about the power behavior of WinUSB, see [WinUSB Power Management](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

The **RetrievePowerPolicy** method generates a UMDF request and synchronously sends the request to the I/O target.

## See also

[IWDFUsbTargetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetdevice)

[IWDFUsbTargetDevice::SetPowerPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetdevice-setpowerpolicy)

[WinUsb_GetPowerPolicy](https://learn.microsoft.com/windows/win32/api/winusb/nf-winusb-winusb_getpowerpolicy)