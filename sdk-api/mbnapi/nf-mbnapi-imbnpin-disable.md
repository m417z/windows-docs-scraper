# IMbnPin::Disable

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Disables a PIN.

## Parameters

### `pin` [in]

The PIN value for the PIN type to be disabled.

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

## Remarks

The **Disable** method disables the PIN type for a Mobile Broadband device. The [PinType](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpin-get_pintype) property of this [IMbnPin](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpin) represents the type of PIN to be deactivated for the device. *pin* contains the current value of PIN for the PIN type.

This is an asynchronous operation. If the method returns with success, then upon completion of the operation, the Mobile Broadband service will call the [OnDisableComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpinevents-ondisablecomplete) method of [IMbnPinEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinevents).

## See also

[IMbnPin](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpin)