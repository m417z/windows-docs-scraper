# ISCPSecureExchange2::TransferContainerData2

## Description

The **TransferContainerData2** method transfers container file data to the secure content provider. The secure content provider breaks down the container internally and reports which parts of the content are available as they are extracted from the container. This method extends [ISCPSecureExchange::TransferContainerData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecureexchange-transfercontainerdata) by accepting a progress callback on which the secure content provider can send progress notifications for any of the steps it needs to carry out.

## Parameters

### `pData` [in]

Pointer to a buffer holding the current data being transferred from the container file. This parameter must be included in the input message authentication code and must be encrypted.

### `dwSize` [in]

**DWORD** that contains the number of bytes in the buffer. This parameter must be included in the input message authentication code.

### `pProgressCallback` [in]

Progress callback on which the secure content provider can report progress of any steps that it might need to carry out. The step will be identified by the *EventId* parameter of [IWMDMProgress3](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress3) methods.

### `pfuReadyFlags` [out]

Flag indicating which parts of the container file are ready to be read. This parameter is included in the output message authentication code. The following flags indicate what is ready.

| Flag | Description |
| --- | --- |
| WMDM_SCP_TRANSFER_OBJECTDATA | Data of the object is available by calling the [ObjectData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecureexchange-objectdata) method. |
| WMDM_SCP_NO_MORE_CHANGES | The secure content provider has determined that it requires no further processing and/or modification of the file being transferred. Windows Media Device Manager can directly transfer the remainder of the file to the device. |

### `abMac` [in, out]

Array of eight bytes containing the message authentication code for the parameter data of this method. (WMDM_MAC_LENGTH is defined as 8.)

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **WMDM_E_NOT_CERTIFIED** | The caller is not authorized to use this interface. |
| **WMDM_E_NORIGHTS** | The caller does not have the rights required to perform the requested operation. |
| **WMDM_E_MAC_CHECK_FAILED** | The message authentication code is not valid. |
| **S_FALSE** | The method failed. Terminate interaction with the secure content provider. |
| **E_INVALIDARG** | A parameter is invalid or is a **NULL** pointer. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

Windows Media Device Manager calls this method repeatedly, transferring data from the container file to the secure content provider. Windows Media Device Manager eventually calls this method with *dwSize* set to zero to indicate that it has no more data to transfer. As the secure content provider collects the data and extracts the various objects from it, it reports back to Windows Media Device Manager which objects, if any, are available after each call. If no objects are available, the secure content provider returns S_OK with the *pfuReadyFlags* parameter set to zero. When the secure content provider has determined that it requires no further processing and/or modification of the file being transferred, the flag WMDM_SCP_NO_MORE_CHANGES is returned. Windows Media Device Manager can then directly transfer the remainder of the file to the device.

Object data is transferred from the secure content provider by calling the **ObjectData** method. Windows Media Device Manager calls **ObjectData** repeatedly until it returns zero in the second parameter, *dwBytesWrite*.

The [TransferComplete](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecureexchange-transfercomplete) method is called by Windows Media Device Manager to signal the end of a secure transfer of data.

Windows Media Device Manager passes the application-provided progress callback to the secure content provider in the *pProgressCallback* parameter. The secure content provider can use this parameter to provide progress notification for any steps that it needs to carry out. The step itself is identified by *EventId*, which is the first parameter of the methods of **IWMDMProgress3**. A specific secure content provider implementation will define *EventId* values for applications to use.

## See also

[ISCPSecureExchange Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsecureexchange)

[ISCPSecureExchange2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsecureexchange2)

[ISCPSecureExchange::ObjectData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecureexchange-objectdata)

[IWMDMProgress3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress3)