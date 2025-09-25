# IMDSPDirectTransfer::TransferToDevice

## Description

The **TransferToDevice** method is called by Windows Media Device Manager to delegate content transfer content to the service provider. The source can be specified either as a file or as an operation interface.

## Parameters

### `pwszSourceFilePath` [in]

Source file name. The value contained in this parameter should be ignored if WMDM_CONTENT_OPERATIONINTERFACE is specified.

### `pSourceOperation` [in]

Operation interface pointer that serves as the source. The value contained in this parameter should be ignored unless WMDM_CONTENT_OPERATIONINTERFACE is specified.

### `fuFlags` [in]

Flags that affect behavior of this method. The *fuFlags* parameter must be one of the following values.

| Value | Description |
| --- | --- |
| WMDM_CONTENT_FILE | The source is a file. |
| WMDM_CONTENT_FOLDER | The source is a folder. |
| WMDM_FILE_CREATE_OVERWRITE | Overwrite the destination file if it already exists. |

### `pwszDestinationName` [in]

Content should be transferred to the device with this name. This parameter is required.

### `pSourceMetaData` [in]

Metadata interface pointer. The metadata object contains the source properties. This parameter is optional.

### `pTransferProgress` [in]

Progress callback interface. The service provider should update the information during the progress of the transfer. This parameter is optional.

### `ppNewObject` [out]

Newly created storage object. This parameter is optional. This can be **NULL** if the caller does not need to have the new object returned.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | One of the following is true:<br><br>1) Both *pwszSourceFileName* and *pSourceOperation* are specified;<br><br>2) *pwszDestinationName* is not specified;<br><br>3) *fuFlags* is invalid. |
| **HRESULT_FROM_WIN32(ERROR_DISK_FULL)** | There is not enough space on the disk. |
| **HRESULT_FROM_WIN32(ERROR_FILE_EXISTS)** | The file already exists and WMDM_FILE_CREATE_OVERWRITE was not specified. If the device allows duplicate file names, this could be acceptable and this error does not need to be returned. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | Transfer of the specified content is not supported on the device. |

## Remarks

Windows Media Device Manager queries for **IMDSPDirectTransfer** interface during every transfer.

If the service provider supports the **IMDSPDirectTransfer** interface, Windows Media Device Manager simply delegates content transfer to the service provider. In this case, Windows Media Device Manager does not do any processing of the content before sending it to the service provider. The service provider gets full control of the source.

If the service provider does not support the **IMDSPDirectTransfer** interface, Windows Media Device Manager processes the source files and sends byte packets to the service provider. In addition, for protected content, Windows Media Device Manager calls the secure content provider to process the content before sending it to the service provider.

If **IMDSPDirectTransfer** is supported, Windows Media Device Manager delegates handling of the content to the service provider. This provides flexibility to the service provider for handling the content. In this case, the service provider is responsible for handling the protected content.

## See also

[IMDSPDirectTransfer Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdirecttransfer)

[IMDSPObject::Close](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-close)

[IMDSPObject::Open](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-open)

[IMDSPObject::Write](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-write)

[IWMDMMetaData Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmmetadata)

[IWMDMOperation Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation)

[IWMDMProgress Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress)

[IWMDMStorageControl Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstoragecontrol)