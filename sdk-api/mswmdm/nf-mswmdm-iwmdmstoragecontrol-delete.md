# IWMDMStorageControl::Delete

## Description

The **Delete** method permanently deletes this storage.

## Parameters

### `fuMode` [in]

One or two of the following flags, combined with a bitwise **OR**. Specify exactly one of the first two modes; the third mode is optional.

| Mode | Description |
| --- | --- |
| WMDM_MODE_BLOCK | The operation is performed using block mode (synchronous) processing. The call will not return until the operation is finished. |
| WMDM_MODE_THREAD | The operation is performed using thread mode (asynchronous) processing. The call will return immediately, and the operation is performed in a background thread. |
| WMDM_MODE_RECURSIVE | If the storage object is a folder, it and its contents, and all subfolders and their contents are deleted. |

4

### `pProgress` [in]

Optional pointer to an [IWMDMProgress](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress) interface to be used by Windows Media Device Manager to report progress back to the application.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

If the WMDM_MODE_THREAD flag is specified, you should obtain completion status by calling either [IWMDMProgress2::End2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress2-end2) or [IWMDMProgress3::End3](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress3-end3). These methods will ensure that the operation is complete and will also return an HRESULT with success or failure information.

When the **Delete** operation is finished, all references to the deleted object become invalid. The application must release these interfaces and any other interfaces or resources associated with the object.

If an application uses WMDM_MODE_THREAD and passes a non-null *pProgress* parameter, the application must ensure that the object to which *pProgress* belongs is not destroyed until the delete operation completes, because Windows Media Device Manager will send progress notifications to this object. This object can be destroyed only after it receives an End notification. Failure to do this will result in access violations.

## See also

[IWMDMDevice::GetStatus](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice-getstatus)

[IWMDMStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage)

[IWMDMStorageControl Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstoragecontrol)

[IWMDMStorageGlobals::GetStatus](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorageglobals-getstatus)