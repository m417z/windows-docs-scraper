# IMbnPinEvents::OnUnblockComplete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method called by the Mobile Broadband service to indicate that a PIN unblock operation has completed

## Parameters

### `Pin` [in]

An [IMbnPin](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpin) interface that represents the PIN type.

### `pinInfo` [in]

A pointer to a [MBN_PIN_INFO](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_pin_info) structure that contains information on remaining attempts, in case of failure operations. The contents of *pinInfo* are meaningful only when *status* is **E_MBN_FAILURE**.

### `requestID` [in]

A request ID set by the Mobile Broadband service to identify the PIN unblock request.

### `status` [in]

A status code that indicates the outcome of the operation.

A calling application can expect one of the following values.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The device does not support this operation. |
| **E_FAIL** | The operation could not be completed. |
| **E_MBN_PIN_REQUIRED** | A PIN is required for the operation to complete. The calling application can call the [GetPinState](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpinmanager-getpinstate) method of [IMbnPinManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanager) to discover the type of expected PIN. |
| **E_MBN_SIM_NOT_INSERTED** | There is no SIM in the device. |
| **E_MBN_BAD_SIM** | There is a bad SIM in the device. |

## Return value

This method must return **S_OK**.

## Remarks

The **OnUnblockComplete** method is called by the Mobile Broadband service to report the completion status of a PIN unblock operation initialized by a call to the [Unblock](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpin-unblock) method of [IMbnPin](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpin).

The contents of *pinInfo* are meaningful only when *status* is **E_MBN_FAILURE**. The **pinState** member should be ignored and **pinType** field is set to the PIN type of the current [IMbnPin](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpin) interface. This structure contains the attempts remaining to enter a valid PIN.

For example, if the PIN passed to change a PIN type is incorrect then the operation will fail with a status code of **E_MBN_FAILURE**. In this case, **pinInfo.attemptsRemaining** specifies the number of attempts remaining to retry this operation.
If repeated attempts with the wrong PIN causes **attemptsRemaining** to become 0 then the application can call the [GetPinState](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpinmanager-getpinstate) method of [IMbnPinManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanager) to get the type of PIN required.

If the device fails to unblock, and if the PUK blocking is of a **MBN_PIN_TYPE_PIN1** pin, then it will also result in the ready state of the device changing to **MBN_READY_STATE_BAD_SIM**. The calling application will be notified about the ReadyState change through the [OnReadyStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterfaceevents-onreadystatechange) member of [IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents).

## See also

[IMbnPinEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinevents)