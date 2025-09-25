# IMbnPinManagerEvents::OnGetPinStateComplete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method called by the Mobile Broadband service to indicate the completion of an asynchronous operation triggered by a call to the [GetPinState](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpinmanager-getpinstate) method of [IMbnPinManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanager).

## Parameters

### `pinManager` [in]

Pointer to an [IMbnPinManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanager) interface that represents the Mobile Broadband device for which the operation was performed.

### `pinInfo` [in]

A [MBN_PIN_INFO](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_pin_info) structure that contains the device PIN information.

If **pinInfo.pinState** is set to **MBN_PIN_STATE_NONE** then no PIN is expected to be entered by device.

If **pinInfo.pinState** is set to **MBN_PIN_STATE_ENTER** then the device is expecting a PIN to be entered and **pinInfo.pinType** represents the type of PIN expected by device.

If **pinInfo.pinState** is set to **MBN_PIN_STATE_UNBLOCK** then the device is PIN blocked and a PIN unblock operation should be tried to unblock the device. In this case, **pinInfo.pinType** represents the PIN type on which the unblock operation should be performed.

If **pinInfo.pinState** is set to **MBN_PIN_STATE_ENTER** or **MBN_PIN_STATE_UNBLOCK**, then **pinInfo.attemptsRemaining** contains the number of attempts remaining to enter a valid PIN or PIN unblock key (PUK). If the number of attempts remaining is unknown then **pinInfo.attemptsRemaining** is set to **MBN_ATTEMPTS_REMAINING_UNKNOWN**.

### `requestID` [in]

The request ID assigned by the Mobile Broadband service to identify this operation.

### `status` [in]

The operation completion status.

A calling application can expect one of the following values.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The device does not support PIN operations. |
| **E_MBN_SIM_NOT_INSERTED** | The operation could not complete because a SIM is not in the device. |
| **E_MBN_BAD_SIM** | The operation could not complete because a bad SIM was detected in the device. |

## Return value

This method must return **S_OK**.

## Remarks

This method is called by the Mobile Broadband service to notify an application of the completion of an asynchronous operation triggered by a call to the [GetPinState](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpinmanager-getpinstate) method of [IMbnPinManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanager).
On successful completion, *pinInfo* contains information about PIN next expected by the device.

## See also

[IMbnPinManagerEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanagerevents)