# IMbnPin::Unblock

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Unblocks a blocked PIN.

## Parameters

### `puk` [in]

The password unblock key (PUK) value for this PIN type.

### `newPin` [in]

A new PIN to be set for this PIN type.

### `requestID` [out]

A request ID set by the Mobile Broadband service to identify this asynchronous request.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **HRESULT_FROM_WIN32(ERROR_SERVICE_NOT_ACTIVE)** | The Mobile Broadband service is not running on this system. |
| **E_HANDLE** | Invalid interface. The Mobile Broadband device has probably been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | Invalid interface. Most likely the Mobile Broadband device has been removed from the system. |
| **E_ACCESSDENIED** | This method is not allowed for calling process privileges. |

## Remarks

The **Unblock** method unblocks the PIN for the pin type by entering the PUK and sets a new PIN. The [PinType](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpin-get_pintype) property of this [IMbnPin](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpin) represents the type of PIN which is being changed.

This is an asynchronous operation. If the method returns with success, then upon completion of the operation, the Mobile Broadband service will call the [OnUnblockComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpinevents-onunblockcomplete) method of [IMbnPinEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinevents).

Whenever the [GetPinState](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpinmanager-getpinstate) method of [IMbnPinManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanager) results with the current PIN state set to **MBN_PIN_STATE_UNBLOCK**, then the application should use **Unblock** on the PIN type which is returned in **PinInfo.pinType** passed by the [OnGetPinStateComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpinmanagerevents-ongetpinstatecomplete) method of [IMbnPinManagerEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanagerevents).

Invoking this method requires administrator privileges.

## See also

[IMbnPin](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpin)