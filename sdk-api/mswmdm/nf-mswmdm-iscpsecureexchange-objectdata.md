# ISCPSecureExchange::ObjectData

## Description

The **ObjectData** method transfers a block of object data back to Windows Media Device Manager.

## Parameters

### `pData` [out]

Pointer to a buffer to receive data. This parameter is included in the output message authentication code and is encrypted.

### `pdwSize` [in, out]

Pointer to a **DWORD** containing the transfer size. This parameter must be included in both the input and output message authentication codes.

### `abMac` [in, out]

Array of eight bytes containing the message authentication code for the parameter data of this method. (WMDM_MAC_LENGTH is defined as 8.)

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **WMDM_E_MAC_CHECK_FAILED** | The message authentication code is not valid. |
| **WMDM_E_NORIGHTS** | The caller does not have the rights required to perform the requested operation. |
| **S_FALSE** | The method failed. Terminate interaction with the secure content provider. |
| **E_INVALIDARG** | A parameter is an invalid or **NULL** pointer. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

To transfer data, Windows Media Device Manager calls the [TransferContainerData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecureexchange-transfercontainerdata) method to obtain the container data. **ObjectData** is then called to transfer blocks of object data from the secure content provider to Windows Media Device Manager. If S_OK is returned with *pdwSize* set to zero, Windows Media Device Manager will request no further data.

## See also

[ISCPSecureExchange Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsecureexchange)