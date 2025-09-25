# IMDSPStorageGlobals::GetStatus

## Description

The **GetStatus** method retrieves the current status of the storage medium.

## Parameters

### `pdwStatus` [out]

Pointer to a **DWORD** containing the status information. The following status values can be returned by the *pdwStatus* parameter.

| Status | Description |
| --- | --- |
| WMDM_STATUS_READY | The medium is in an idle ready state. |
| WMDM_STATUS_BUSY | An operation is ongoing. Evaluate status values to determine the ongoing operation. |
| WMDM_STATUS_STORAGE_NOTPRESENT | The medium is not present. For devices that support more than one medium, this value is only reported from the **IMDSPStorageGlobals** interface. |
| WMDM_STATUS_STORAGE_INITIALIZING | The device is currently busy formatting media on a device. |
| WMDM_STATUS_STORAGE_BROKEN | The medium is broken. For devices that support more than one medium, this value is only reported from the **IMDSPStorageGlobals** interface. |
| WMDM_STATUS_STORAGE_NOTSUPPORTED | The medium is not supported by the device. For devices that support more than one medium, this value is only returned from the **IMDSPStorageGlobals** interface. |
| WMDM_STATUS_STORAGE_UNFORMATTED | The medium is not formatted. For devices that support more than one medium, this value is only reported from the **IMDSPStorageGlobals** interface. |

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

You must always call this method before attempting to interact with a storage medium. The status value returned is WMDM_STATUS_BUSY if some other interface has invoked an ongoing operation. You can evaluate the value returned from this call to determine whether an ongoing operation has been invoked from the **IMDSPStorageGlobals** interface.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPStorageGlobals Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorageglobals)