# IMbnPinManager::GetPin

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets a specific type of PIN.

## Parameters

### `pinType` [in]

An [MBN_PIN_TYPE](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_pin_type) value that represents the requested PIN type.

### `pin` [out, retval]

Pointer to the address of the [IMbnPin](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpin) for the requested PIN type. If this method returns any value other than **S_OK**, this parameter is **NULL**. Otherwise, the calling application must release this interface when it is done using it.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_PENDING** | The PIN type is not available. The Mobile Broadband service is currently probing the device to retrieve this information. When the PIN type is available, the Mobile Broadband service will call the [OnPinListAvailable](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpinmanagerevents-onpinlistavailable) method of [IMbnPinManagerEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanagerevents). |
| **E_MBN_PIN_REQUIRED** | A PIN is required for the operation to complete. The calling Application can retry this operation when device is PIN unlocked |
| **E_MBN_SIM_NOT_INSERTED** | There is no SIM in the device. |
| **E_MBN_BAD_SIM** | There is a bad SIM in the device. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The requested PIN type is not supported by the device. |

## See also

[IMbnPinManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanager)