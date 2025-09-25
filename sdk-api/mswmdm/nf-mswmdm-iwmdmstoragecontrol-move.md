# IWMDMStorageControl::Move

## Description

The **Move** method moves the current storage to a new location on the device.

## Parameters

### `fuMode` [in]

Processing mode by which to invoke the **Move** operation and the type of move to make. Specify exactly one of the following two modes. If both modes are specified, block mode is used.

| Mode | Description |
| --- | --- |
| WMDM_MODE_BLOCK | The operation is performed using block mode processing. The call will not return until the operation is finished. |
| WMDM_MODE_THREAD | The operation is performed using thread mode processing. The call will return immediately, and the operation is performed in a background thread. |

The following table lists flags that indicate where the object is moved to. One value from this table is combined with one value from the preceding Mode table using a bitwise **OR**.

| Flag | Description |
| --- | --- |
| WMDM_STORAGECONTROL_INSERTBEFORE | The object is inserted before the target object. |
| WMDM_STORAGECONTROL_INSERTINTO | The object is inserted into the target object. |
| WMDM_STORAGECONTROL_INSERTAFTER | The object is inserted after the target object. |

### `pTargetObject` [in]

Pointer to the object before or after which you want to put the current object.

### `pProgress` [in]

Optional pointer to an [IWMDMProgress](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress) interface that has been implemented by the application to track the progress of an ongoing operation.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

A file or directory can be moved only within the same root storage.

If the WMDM_MODE_THREAD flag is specified, you should obtain completion status by calling either [IWMDMProgress2::End2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress2-end2) or [IWMDMProgress3::End3](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress3-end3). These methods will ensure that the operation is complete and will also return an HRESULT with success or failure information.

If an application uses WMDM_MODE_THREAD and passes a non-null *pProgress* parameter, the application must ensure that the object to which *pProgress* belongs is not destroyed until the move operation completes, because Windows Media Device Manager will send progress notifications to this object. This object can be destroyed only after it receives an End notification. Failure to do this will result in access violations.

## See also

[IWMDMDevice::GetStatus](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice-getstatus)

[IWMDMProgress Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress)

[IWMDMStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage)

[IWMDMStorageControl Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstoragecontrol)