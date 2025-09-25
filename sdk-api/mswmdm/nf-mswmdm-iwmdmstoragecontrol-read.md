# IWMDMStorageControl::Read

## Description

The **Read** method copies the current storage to the computer.

## Parameters

### `fuMode` [in]

Processing mode used for the **Read** operation. The following table lists the processing modes that can be specified in the *fuMode* parameter. You must specify exactly one of the first two modes, and exactly one of the last three (WMDM_CONTENT) modes. If both WMDM_MODE_BLOCK and WMDM_MODE_THREAD are specified, block mode is used.

| Mode | Description |
| --- | --- |
| WMDM_MODE_BLOCK | The operation is performed using block mode processing. The call will not return until the operation is finished. |
| WMDM_MODE_THREAD | The operation is performed using thread mode processing. The call will return immediately, and the operation is performed in a background thread. |
| WMDM_CONTENT_FILE | The caller requests that Windows Media Device Manager read the file from the portable device into a file on the hard disk. The caller should indicate, in the *pwszFileName* parameter, the full path and name of the file. |
| WMDM_CONTENT_FOLDER | The caller requests that Windows Media Device Manager read the specified folder, the contents, of the folder and the contents of any subfolders from the portable device onto the hard disk. The caller should indicate the full path of the target directory on the hard disk in the *pwszFileName* parameter.This is not currently supported by any Microsoft-provided service providers. |
| WMDM_CONTENT_OPERATIONINTERFACE | The application-implemented **IWMDMOperation** interface is being used to read data, instead of passing in a file name. |

### `pwszFile` [in]

Pointer to a fully qualified file name on the computer to which the content from the portable device is copied. The file name should include an extension; the extension from the current storage on the device will not be used. If WMDM_CONTENT_OPERATIONINTERFACE is specified in *fuMode*, this parameter is ignored.

### `pProgress` [in]

Optional pointer to a [IWMDMProgress](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress) interface that has been implemented by the application to track the progress of ongoing operations.

### `pOperation` [in]

Optional pointer to an [IWMDMOperation](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation) interface, an optional set of methods used to enhance the transfer of content from a media device. This parameter must be **NULL** if WMDM_CONTENT_FILE or WMDM_CONTENT_FOLDER is specified in *fuMode*.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method will automatically overwrite existing files specified by *pwszFilename*. It can succeed even if

If the WMDM_MODE_THREAD flag is specified, you should obtain completion status by calling either [IWMDMProgress2::End2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress2-end2) or [IWMDMProgress3::End3](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress3-end3). These methods will ensure that the operation is complete and will also return an HRESULT with success or failure information.

If an application uses WMDM_MODE_THREAD and passes a non-**null***pProgress* parameter, the application must ensure that the object to which *pProgress* belongs is not destroyed until the read operation completes, because Windows Media Device Manager will send progress notifications to this object. This object can be destroyed only after it receives an End notification. Failure to do this will result in access violations.

## See also

[IWMDMDevice::GetStatus](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice-getstatus)

[IWMDMOperation Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation)

[IWMDMProgress Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress)

[IWMDMStorageControl Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstoragecontrol)

[IWMDMStorageControl::Insert](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstoragecontrol-insert)