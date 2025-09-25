# IMDSPObject::Delete

## Description

The **Delete** method removes an object or objects from a storage medium on a media device.

## Parameters

### `fuMode` [in]

Flag that must always be set to WMDM_MODE_RECURSIVE by the client. If the object is a folder, it and its contents, and all subfolders and their contents are deleted. If the object is a file, this parameter is ignored.

### `pProgress` [in]

Pointer to an application-implemented [IWMDMProgress](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress) interface that enables the application to receive progress notifications for lengthy **Delete** operations.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method permanently removes the object(s) from the storage medium.

When using a CompactFlash card reader/writer with Windows Media Device Manager service provider, calling **IMDSPObject::Delete** immediately after **IMDSPObject::Write** sometimes fails. This happens because data written to a CompactFlash reader/writer is buffered by the driver of the card reader/writer. The service provider responds as if the write operations are finished, but the driver writes them out to the device according to its own schedule. **IMDSPObject::Delete** fails if the driver has not finished its writing operation.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPObject Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspobject)

[IWMDMProgress Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress)