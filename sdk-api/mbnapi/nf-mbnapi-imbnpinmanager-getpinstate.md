# IMbnPinManager::GetPinState

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the current PIN state of the device.

## Parameters

### `requestID` [out]

A pointer to the request ID set by the Mobile Broadband service for this asynchronous request. The response will contain the same request ID.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **HRESULT_FROM_WIN32(ERROR_SERVICE_NOT_ACTIVE)** | The Mobile Broadband service is not running on this system. |
| **E_HANDLE** | The interface is invalid, most likely because the Mobile Broadband device has been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The interface is invalid. Most likely the Mobile Broadband device has been removed from the system. |

## Remarks

The **GetPinState** method initiates an asynchronous request for the PIN state of the device. The PIN state indicates if a PIN needs to be entered for a requested operation to complete. It also contains information about which type of PIN is expected by a device and optionally it provides the number of attempts remaining for entering a valid PIN.

This method always returns the current PIN state of the device. It does not cache the PIN state at the time when this object is created. Instead it always contacts the device and returns the current PIN state of the device.

Since this is an asynchronous operation, **GetPinState** will return immediately. On completion of the operation, the Mobile Broadband service will call the [OnGetPinStateComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpinmanagerevents-ongetpinstatecomplete) method of [IMbnPinManagerEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanagerevents).

Whenever an operation returns **E_MBN_PIN_REQUIRED** or the ready state reported by the device is **MBN_READY_STATE_DEVICE_LOCKED**, an application should use this method to query the type of PIN required to unlock the device or SIM.

While this operation is in progress, if the Mobile Broadband device gets removed from the system then a call to the [OnGetPinStateComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpinmanagerevents-ongetpinstatecomplete) method of [IMbnPinManagerEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanagerevents) is not guaranteed.

## See also

[IMbnPinManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanager)