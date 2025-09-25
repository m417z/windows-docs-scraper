# IWMDMStorageControl2::Insert2

## Description

The **Insert2** method puts content into/next to the storage. This method extends **IWMDMStorageControl::Insert** by allowing the application to specify a new destination name, and provide a pointer to a custom COM object.

## Parameters

### `fuMode` [in]

Processing mode used for the **Insert2** operation. The following table lists the processing modes that can be specified in the **fuMode** parameter. You must specify exactly one of the first two modes, exactly one of the STORAGECONTROL modes, and exactly one of the CONTENT modes. If both WMDM_MODE_BLOCK and WMDM_MODE_THREAD are specified, block mode is used.

| Combinations | Mode | Description |
| --- | --- | --- |
| Exactly one of: | WMDM_MODE_BLOCK | The operation is performed using block mode processing. The call will not return until the operation is finished. |
| - | WMDM_MODE_THREAD | The operation is performed using thread mode processing. The call will return immediately, and the operation is performed in a background thread. |
| Optional | WMDM_MODE_QUERY | A test is performed to determine whether the insert operation could succeed, but the insert will not be performed. |
| Exactly one of: | WMDM_STORAGECONTROL_INSERTBEFORE | The object is inserted before the target object. |
| - | WMDM_STORAGECONTROL_INSERTAFTER | The object is inserted after the target object. |
| - | WMDM_STORAGECONTROL_INSERTINTO | The object is inserted into the current object. This will only work if the current object is a folder. |
| Optional | WMDM_FILE_CREATE_OVERWRITE | The object will replace the target object. |
| Exactly one of: | WMDM_CONTENT_FILE | The content being inserted is a file. |
| - | WMDM_CONTENT_FOLDER | The content being inserted is a folder. This will not transfer the contents of the folder. |
| Optional | WMDM_CONTENT_OPERATIONINTERFACE | The content being inserted is an operation interface. The data for the content should be written to the application-implemented **IWMDMOperation** interface. |
| Optional | WMDM_MODE_PROGRESS | Progress notifications should be sent through the *pProgress* parameter. |
| Optional one of: | WMDM_MODE_TRANSFER_PROTECTED | The insertion is in protected transfer mode. |
| - | WMDM_MODE_TRANSFER_UNPROTECTED | The insertion is in unprotected transfer mode. |

### `pwszFileSource` [in]

Pointer to a wide-character, **null**-terminated string indicating the full name and path of the object to send to the device. This parameter must be **NULL** if WMDM_CONTENT_OPERATIONINTERFACE is specified in *fuMode*.

### `pwszFileDest` [in]

Optional name of file on the device. If not specified and the application passes an **IWMDMOperation** pointer to *pOperation*, Windows Media Device Manager will request a destination name by calling [IWMDMOperation::GetObjectName](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-getobjectname). If not specified and the application does not use *pOperation*, the original file name and extension are used (without the path).

### `pOperation` [in]

Optional pointer to an [IWMDMOperation](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation) interface, to control the transfer of content to a media device. If specified, *fuMode* must include the WMDM_CONTENT_OPERATIONINTERFACE flag. This parameter must be **NULL** if WMDM_CONTENT_FILE or WMDM_CONTENT_FOLDER is specified in *fuMode*.

### `pProgress` [in]

Optional pointer to an [IWMDMProgress](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress) interface to report action progress back to the application. If specified, *fuMode* should include WMDM_MODE_PROGRESS.

### `pUnknown` [in]

Optional **IUnknown** pointer of any custom COM object to be passed to the secure content provider. This makes it possible to pass custom information to a secure content provider if the application has sufficient information about the secure content provider.

### `ppNewObject` [out]

Pointer to an **IWMDMStorage** interface that will contain the new content. The caller must release this interface when finished with it.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

If the device supports [IWMDMStorageControl3::Insert3](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstoragecontrol3-insert3), that is the preferred method to use.

If the WMDM_MODE_THREAD flag is specified, you should obtain completion status by calling either [IWMDMProgress2::End2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress2-end2) or [IWMDMProgress3::End3](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress3-end3). These methods will ensure that the operation is complete and will also return an HRESULT with success or failure information.

If an application uses WMDM_MODE_THREAD and passes a non-**null***pProgress* parameter, the application must ensure that the object to which *pProgress* belongs is not destroyed until the insert operation completes, because Windows Media Device Manager will send progress notifications to this object. This object can be destroyed only after it receives an End notification. Failure to do this will result in access violations.

## See also

[IWMDMDevice::GetStatus](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice-getstatus)

[IWMDMOperation Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation)

[IWMDMProgress Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress)

[IWMDMStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage)

[IWMDMStorageControl2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstoragecontrol2)

[IWMDMStorageControl3::Insert3](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstoragecontrol3-insert3)