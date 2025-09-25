# IWMDMStorageControl::Insert

## Description

The **Insert** method puts content into the storage on the device.

## Parameters

### `fuMode` [in]

A bitwise **OR** of the following values. The following table lists the processing modes that can be specified in the *fuMode* parameter. You must specify exactly one of the first two modes, exactly one of the STORAGECONTROL modes, and exactly one of the CONTENT modes. If both WMDM_MODE_BLOCK and WMDM_MODE_THREAD are specified, block mode is used.

| Combinations | Mode | Description |
| --- | --- | --- |
| Exactly one of: | WMDM_MODE_BLOCK | The operation is performed using block mode processing. The call will not return until the operation is finished. |
|  | WMDM_MODE_THREAD | The operation is performed using thread mode processing. The call will return immediately, and the operation is performed in a background thread. |
| Exactly one of: | WMDM_STORAGECONTROL_INSERTBEFORE | The object is inserted before the current object. |
|  | WMDM_STORAGECONTROL_INSERTAFTER | The object is inserted after the current object. |
|  | WMDM_STORAGECONTROL_INSERTINTO | The object is inserted into the current object. This will only work if the current object is a folder. |
| Exactly one of: | WMDM_CONTENT_FILE | The content being inserted is a file. |
|  | WMDM_CONTENT_FOLDER | The content being inserted is a folder. This will not transfer the contents of the folder. |
|  | WMDM_CONTENT_OPERATIONINTERFACE | The content being inserted is an operation interface. The data for the content should be written to the application-implemented **IWMDMOperation** interface. |
| Zero or more of: | WMDM_FILE_CREATE_OVERWRITE | The object will replace the current object. |
|  | WMDM_MODE_QUERY | A test is performed to determine whether the insert operation could succeed, but the insert will not be performed. |
|  | WMDM_MODE_PROGRESS | The method should return progress notifications through *pProgress*. |
| Zero or one of: | WMDM_MODE_TRANSFER_PROTECTED | The insertion is in protected transfer mode. |
|  | WMDM_MODE_TRANSFER_UNPROTECTED | The insertion is in unprotected transfer mode. |

### `pwszFile` [in]

Pointer to a wide-character **null**-terminated string indicating where to find the content for the insert operation. This parameter must be **NULL** if WMDM_CONTENT_OPERATIONINTERFACE is specified in *fuMode*.

### `pOperation` [in]

Optional pointer to an [IWMDMOperation](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation) interface, to control the transfer of content to a media device. If specified, *fuMode* must include the WMDM_CONTENT_OPERATIONINTERFACE flag. This parameter must be **NULL** if WMDM_CONTENT_FILE or WMDM_CONTENT_FOLDER is specified in *fuMode*.

### `pProgress` [in]

Optional pointer to an [IWMDMProgress](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress) interface to be used by Windows Media Device Manager to report progress back to the application. If this is used, *fuMode* should include WMDM_MODE_PROGRESS.

### `ppNewObject` [out]

Pointer to an [IWMDMStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage) interface that will contain the new content. The caller must release this interface when finished with it.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

If the device supports [IWMDMStorageControl3::Insert3](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstoragecontrol3-insert3), that is the preferred method to use.

The name and extension of the object saved on the device will be the same as the name and extension of the source file (if *pOperation* is **NULL**).

If the WMDM_MODE_THREAD flag is specified, you should obtain completion status by calling either [IWMDMProgress2::End2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress2-end2) or [IWMDMProgress3::End3](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress3-end3). These methods will ensure that the operation is complete and will also return an HRESULT with success or failure information.

The **Insert** method does not guarantee that the device supports ordered file insertion, but it provides the flags WMDM_STORAGECONTROL_INSERTBEFORE and WMDM_STORAGECONTROL_INSERTAFTER in case it does. If the file system does not support ordering (for instance, FAT32), WMDM_STORAGECONTROL_INSERTBEFORE and WMDM_STORAGECONTROL_INSERTAFTER will simply insert the new storage object at the same level as the current object in the file system hierarchy.

If an application uses WMDM_MODE_THREAD and passes a non-**null***pProgress* parameter, the application must ensure that the object to which *pProgress* belongs is not destroyed until the insert operation completes, because Windows Media Device Manager will send progress notifications to this object. This object can be destroyed only after it receives an End notification. Failure to do this will result in access violations.

## See also

[IWMDMStorageControl Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstoragecontrol)

[IWMDMStorageControl2::Insert2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstoragecontrol2-insert2)

[IWMDMStorageControl3::Insert3](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstoragecontrol3-insert3)

[IWMDMStorageControl::Read](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstoragecontrol-read)

[Writing Files to the Device](https://learn.microsoft.com/windows/desktop/WMDM/writing-files-to-the-device)