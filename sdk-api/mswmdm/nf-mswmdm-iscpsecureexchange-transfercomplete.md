# ISCPSecureExchange::TransferComplete

## Description

The **TransferComplete** method is called by Windows Media Device Manager to signal the end of a secure transfer of data. In this method, the secure content provider can perform any additional processing required to enable the content on the target device.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **WMDM_E_NOT_CERTIFIED** | The caller is not authorized to use this interface. |
| **WMDM_E_NORIGHTS** | The caller does not have the rights required to perform the requested operation. |
| **WMDM_E_MAC_CHECK_FAILED** | The message authentication code is not valid. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ISCPSecureExchange Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsecureexchange)