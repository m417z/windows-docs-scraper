# IWDFUsbTargetPipe::RetrievePipePolicy

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **RetrievePipePolicy** method retrieves a WinUsb pipe policy.

## Parameters

### `PolicyType` [in]

The type of WinUsb pipe policy that the UMDF driver requests.

### `ValueLength` [in, out]

A pointer to a variable that, on input, contains the size, in bytes, of the buffer that **RetrievePipePolicy** supplies for *Value*. On output, this parameter contains the size that **RetrievePipePolicy** requires for *Value*.

### `Value` [out]

A pointer that receives the buffer that contains the WinUsb pipe policy.

## Return value

**RetrievePipePolicy** returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | [RetrievePipePolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetpipe-retrievepipepolicy) successfully retrieved the WinUsb pipe policy. |
| **E_OUTOFMEMORY** | [RetrievePipePolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetpipe-retrievepipepolicy) encountered an allocation failure. |
| **An error code that is defined in Winerror.h** | This value corresponds to the error code that the WinUsb API returned. |

## Remarks

Pipe policy controls the behavior of the USB pipe (for example, time-outs, handling short packets, and so on).

For more information about valid policy types that a UMDF driver can pass for the *PolicyType* parameter and values that the framework returns, see the [WinUsb_GetPipePolicy](https://learn.microsoft.com/windows/win32/api/winusb/nf-winusb-winusb_getpipepolicy) function.

For information about the behavior of the pipe policies, see [WinUSB Functions for Pipe Policy Modification](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

The **RetrievePipePolicy** method generates a UMDF request and synchronously sends the request to the I/O target.

## See also

[IWDFUsbTargetPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetpipe)

[IWDFUsbTargetPipe::SetPipePolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetpipe-setpipepolicy)

[WinUsb_GetPipePolicy](https://learn.microsoft.com/windows/win32/api/winusb/nf-winusb-winusb_getpipepolicy)