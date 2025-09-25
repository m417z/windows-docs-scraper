# IMbnPinEvents::OnChangeComplete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method called by the Mobile Broadband service to indicate that a PIN change operation has completed.

## Parameters

### `Pin` [in]

An [IMbnPin](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpin) interface that represents the PIN type.

### `pinInfo` [in]

A pointer to an [MBN_PIN_INFO](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_pin_info) structure that contains information on remaining attempts, in case of failure operations. The contents of *pinInfo* are meaningful only when *status* is **E_MBN_FAILURE**.

### `requestID` [in]

A request ID set by the Mobile Broadband service to identify the PIN change request.

### `status` [in]

A status code that indicates the outcome of the PIN change operation.

A calling application can expect one of the following values.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The device does not support this operation. |
| **E_FAIL** | The operation could not be completed. |
| **E_MBN_PIN_REQUIRED** | A PIN is required for the operation to complete. The calling application can call the [GetPinState](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpinmanager-getpinstate) method of [IMbnPinManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanager) to discover the type of expected PIN. |
| **E_MBN_SIM_NOT_INSERTED** | There is no SIM in the device. |
| **E_MBN_BAD_SIM** | There is a bad SIM in the device. |
| **E_MBN_PIN_DISABLED** | The PIN change operation is not supported for the disabled PIN. |

## Return value

This method must return **S_OK**.

## Remarks

The **OnChangeComplete** method is called by the Mobile Broadband service to report the completion status of a PIN change operation initialized by a call to the [Change](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpin-change) method of [IMbnPin](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpin).

The contents of *pinInfo* are meaningful only when *status* is **E_MBN_FAILURE**. The **pinState** member should be ignored and **pinType** field is set to the PIN type of the current [IMbnPin](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpin) interface. This structure contains the attempts remaining to enter a valid PIN.

For example, if the PIN passed to change a PIN type is incorrect then the operation will fail with a status code of **E_MBN_FAILURE**. In this case, **pinInfo.attemptsRemaining** specifies the number of attempts remaining to retry this operation.
If repeated attempts with the wrong PIN causes **attemptsRemaining** to become 0 then the application can call the [GetPinState](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpinmanager-getpinstate) method of [IMbnPinManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanager) to get the type of PIN required.

## See also

[IMbnPinEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinevents)