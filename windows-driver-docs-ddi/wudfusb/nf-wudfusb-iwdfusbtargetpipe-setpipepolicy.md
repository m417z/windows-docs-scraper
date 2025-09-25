# IWDFUsbTargetPipe::SetPipePolicy

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **SetPipePolicy** method sets the WinUsb pipe policy.

## Parameters

### `PolicyType` [in]

The type of WinUsb pipe policy that the UMDF driver sets.

### `ValueLength` [in]

The size, in bytes, of the buffer that **SetPipePolicy** supplies for *Value*.

### `Value` [in]

A pointer to the buffer that contains the WinUsb pipe policy.

## Return value

**SetPipePolicy** returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | [SetPipePolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetpipe-setpipepolicy) successfully set the WinUsb pipe policy. |
| **E_OUTOFMEMORY** | [SetPipePolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetpipe-setpipepolicy) encountered an allocation failure. |
| **An error code that is defined in Winerror.h** | This value corresponds to the error code that the WinUsb API returned. |

## Remarks

Pipe policy controls the behavior of the USB pipe (for example, time-outs, handling short packets, and so on).

For more information about valid policy types and values that a UMDF driver can pass for the *PolicyType* and *Value* parameters, see the [WinUsb_SetPipePolicy](https://learn.microsoft.com/windows/win32/api/winusb/nf-winusb-winusb_setpipepolicy) function.

For information about the behavior of the pipe policies, see [WinUSB Functions for Pipe Policy Modification](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

The **SetPipePolicy** method generates a UMDF request and synchronously sends the request to the I/O target.

#### Examples

The following code example sets policy for input and output pipes.

```
HRESULT
CMyDevice::ConfigureUsbIoTargets(
    )
{
    HRESULT                 hr;
    USB_INTERFACE_DESCRIPTOR pInterface;
    WINUSB_PIPE_INFORMATION pipe;
    BOOL                    policy;
    DWORD                   err;
    BOOL                    result;
    LONG                    i;
    LONG                    timeout;
    ULONG                   length;

    length = sizeof(UCHAR);
    hr = m_pIUsbTargetDevice->RetrieveDeviceInformation(DEVICE_SPEED,
                                                        &length,
                                                        &m_Speed);
    if (FAILED(hr)) {
        // Print out error.
    }
    if (SUCCEEDED(hr)) {
        // Print out device speed.
    }
    //
    // Set timeout policies for input and output pipes.
    //
    if (SUCCEEDED(hr))  {
       timeout = ENDPOINT_TIMEOUT;
       hr = m_pIUsbInputPipe->SetPipePolicy(PIPE_TRANSFER_TIMEOUT,
                                            sizeof(timeout),
                                            &timeout);
       if (FAILED(hr)) {
            // Print out cannot set timeout policy for input pipe.
       }
    }
    if (SUCCEEDED(hr))  {
       timeout = ENDPOINT_TIMEOUT;
       hr = m_pIUsbOutputPipe->SetPipePolicy(PIPE_TRANSFER_TIMEOUT,
                                             sizeof(timeout),
                                             &timeout);
       if (FAILED(hr))  {
            // Print out cannot set timeout policy for output pipe.
       }
    }
 return hr;
}
```

## See also

[IWDFUsbTargetPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetpipe)

[IWDFUsbTargetPipe::RetrievePipePolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetpipe-retrievepipepolicy)

[WinUsb_SetPipePolicy](https://learn.microsoft.com/windows/win32/api/winusb/nf-winusb-winusb_setpipepolicy)