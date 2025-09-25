# ISCPSecureExchange3::TransferContainerDataOnClearChannel

## Description

The **TransferContainerDataOnClearChannel** method transfers container file data to the content provider through the clear channel. The content provider breaks down the container internally and reports which parts of the content are available as they are extracted from the container.

This method is identical to [ISCPSecureExchange::TransferContainerData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecureexchange-transfercontainerdata) except that the parameters passed to this method are not encrypted. Consequently this method is more efficient.

## Parameters

### `pDevice`

Pointer to a device object.

### `pData`

Pointer to a buffer holding the current data being transferred from the container file.

### `dwSize`

Contains the number of bytes in the buffer.

### `pProgressCallback`

Progress callback on which the content provider can report progress of any steps that it might need to carry out. The step will be identified by the *EventId* parameter of [IWMDMProgress3](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress3) methods.

### `pfuReadyFlags`

Flag indicating which parts of the container file are ready to be read. This parameter is included in the output message authentication code. The following flags indicate what is ready.

| Value | Meaning |
| --- | --- |
| **WMDM_SCP_TRANSFER_OBJECTDATA** | Data of the object is available by calling the [GetObjectDataOnClearChannel](https://learn.microsoft.com/windows/desktop/WMDM/iscpsecureexchange3--getobjectdataonclearchannel) method. |
| **WMDM_SCP_NO_MORE_CHANGES** | The content provider has determined that it requires no further processing and/or modification of the file being transferred. Windows Media Device Manager can directly transfer the remainder of the file to the device. |

## Return value

If the method succeeds, it returns S_OK. If the method fails, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **WMDM_E_NOT_CERTIFIED** | The caller is not authorized to use this interface. |
| **WMDM_E_NORIGHTS** | The caller does not have the rights required to perform the requested operation. |
| **WMDM_E_MAC_CHECK_FAILED** | The message authentication code is not valid. |
| **S_FALSE** | The method failed. Terminate interaction with the content provider. |
| **E_INVALIDARG** | A parameter is invalid or is a **NULL** pointer. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

Windows Media Device Manager calls this method repeatedly, transferring data from the container file to the content provider. Windows Media Device Manager eventually calls this method with *dwSize* set to zero to indicate that it has no more data to transfer. As the content provider collects the data and extracts the various objects from it, it reports back to Windows Media Device Manager which objects, if any, are available after each call. If no objects are available, the content provider returns S_OK with the *pfuReadyFlags* parameter set to zero. When the content provider has determined that it requires no further processing and/or modification of the file being transferred, the flag WMDM_SCP_NO_MORE_CHANGES is returned. Windows Media Device Manager can then directly transfer the remainder of the file to the device.

Object data is transferred from the content provider by calling the **GetObjectDataOnClearChannel** method. Windows Media Device Manager calls **GetObjectDataOnClearChannel** repeatedly until it returns zero in the third parameter, *pdwsize*.

The [ISCPSecureExchange::TransferComplete](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecureexchange-transfercomplete) (or [TransferCompleteForDevice](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecureexchange3-transfercompletefordevice) if a session is active) method is called by Windows Media Device Manager to signal the end of a data transfer.

Windows Media Device Manager passes the application-provided progress callback to the content provider in the *pProgressCallback* parameter. The content provider can use this parameter to provide progress notification for any steps that it needs to carry out. The step itself is identified by *EventId*, which is the first parameter of the methods of **IWMDMProgress3**. A specific content provider implementation will define *EventId* values for applications to use.

This method is identical to [ISCPSecureExchange::TransferContainerData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecureexchange-transfercontainerdata) except that the parameters passed to this method are not encrypted. Consequently this method is more efficient.

## See also

[ISCPSecureExchange3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsecureexchange3)

[ISCPSecureExchange::TransferContainerData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecureexchange-transfercontainerdata)