# IMDSPDevice::GetStatus

## Description

The **GetStatus** method retrieves all the device status information that the device can provide.

## Parameters

### `pdwStatus` [out]

Pointer to a **DWORD** that receives the current device status. These status values are defined in the following table.

| Status | Description |
| --- | --- |
| WMDM_STATUS_READY | Windows Media Device Manager and its subcomponents are in a ready state. |
| WMDM_STATUS_BUSY | An operation is ongoing. Check other status values to determine which operation it is. |
| WMDM_STATUS_DEVICE_NOTPRESENT | The device is not connected to the computer. |
| WMDM_STATUS_STORAGE_NOTPRESENT | The medium is not present. For devices that support more than one medium, this value is reported only from the [IWMDMStorageGlobals](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorageglobals) interface. |
| WMDM_STATUS_STORAGE_INITIALIZING | The device is currently busy formatting media on the device. |
| WMDM_STATUS_STORAGE_BROKEN | The medium is not working. For devices that support more than one medium, this value is reported only from the **IWMDMStorageGlobals** interface. |
| WMDM_STATUS_STORAGE_NOTSUPPORTED | The medium is not supported by the device. For devices that support more than one medium, this value is returned only from the **IWMDMStorageGlobals** interface. |
| WMDM_STATUS_STORAGE_UNFORMATTED | The medium is not formatted. For devices that support more than one medium, this value is returned only from the **IWMDMStorageGlobals** interface. |
| WMDM_STATUS_STORAGECONTROL_INSERTING | The [IWMDMStorageControl::Insert](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstoragecontrol-insert) method is currently running. |
| WMDM_STATUS_STORAGECONTROL_DELETING | The [IWMDMStorageControl::Delete](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstoragecontrol-delete) method is currently running. |
| WMDM_STATUS_STORAGECONTROL_MOVING | The [IWMDMStorageControl::Move](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstoragecontrol-move) method is currently running. |
| WMDM_STATUS_STORAGECONTROL_READING | The [IWMDMStorageControl::Read](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstoragecontrol-read) method is currently running. |

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

One or more status values can be returned from this call. All the status values of all the interfaces of the media device are reported through this call. For example, if a storage operation, such as writing a file to a media device is ongoing, a call to this method reports the busy status of that operation. For any ongoing operation, the status value WMDM_STATUS_BUSY is always present.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevice)

[IWMDMStorageControl Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstoragecontrol)

[IWMDMStorageGlobals Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorageglobals)