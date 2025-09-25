# IWMDMStorageGlobals::GetStatus

## Description

The **GetStatus** method retrieves the current status of a storage medium.

## Parameters

### `pdwStatus` [out]

Pointer to a **DWORD** to receive the status information when the method returns. The following values can be returned in the *pdwStatus* parameter.

| Status | Description |
| --- | --- |
| WMDM_STATUS_READY | The medium is in an idle or ready state. |
| WMDM_STATUS_BUSY | An operation is ongoing. Evaluate status values to determine the ongoing operation. |
| WMDM_STATUS_STORAGE_NOTPRESENT | The storage medium is not present. For devices with more than one medium supported, this value is only reported from the **IWMDMStorageGlobals** interface. |
| WMDM_STATUS_STORAGE_INITIALIZING | The device is currently busy formatting a storage medium on a device. |
| WMDM_STATUS_STORAGE_BROKEN | The storage medium is broken. For devices with more than one medium supported, this value is only reported from the **IWMDMStorageGlobals** interface. |
| WMDM_STATUS_STORAGE_NOTSUPPORTED | The storage medium is not supported by the device. For devices with more than one medium supported, this value is only returned from the **IWMDMStorageGlobals** interface. |
| WMDM_STATUS_STORAGE_UNFORMATTED | The storage medium is not formatted. For devices with more than one medium supported, this value is only reported from the **IWMDMStorageGlobals** interface. |

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method must always be called before the caller attempts to interact with a storage medium. The status value retrieved is WMDM_STATUS_BUSY if some other interface has invoked an ongoing operation. You can evaluate the value retrieved from this call to determine whether an ongoing operation has been invoked from the **IWMDMStorageGlobals** interface.

## See also

[IWMDMStorageGlobals Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorageglobals)