# ISCPSecureExchange3::TransferCompleteForDevice

## Description

The **TransferCompleteForDevice** method is called by Windows Media Device Manager to signal the end of a data transfer for a specific device.

## Parameters

### `pDevice`

Pointer to a device object.

## Return value

If the method succeeds, it returns S_OK. If the method fails, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **WMDM_E_NOT_CERTIFIED** | The caller is not authorized to use this interface. |
| **WMDM_E_NORIGHTS** | The caller does not have the rights required to perform the requested operation. |
| **WMDM_E_MAC_CHECK_FAILED** | The message authentication code is not valid. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

This method is identical to [ISCPSecureExchange::TransferComplete](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecureexchange-transfercomplete) except that this method is called when transfer is completed within a transfer session.

In that case, the secure content provider needs to know which device the transfer was completed for, so this method accepts a *pDevice* parameter.

## See also

[ISCPSecureExchange3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsecureexchange3)

[ISCPSecureExchange::TransferComplete](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecureexchange-transfercomplete)