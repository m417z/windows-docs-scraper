# CSecureChannelClient::MACFinal

## Description

The **MACFinal** method releases the message authentication code (MAC) channel and retrieves a final MAC value.

## Parameters

### `hMAC` [in]

Handle for the MAC for the current parameter data. This handle is created by calling the **MACInit** method. This datatype is declared in the SDK file ...\inc\Sac.h. After this method is called, the handle passed in is no longer valid.

### `abData` [out]

Array of bytes to receive the final MAC value for the current parameter data.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| S_OK | The method succeeded. |
| E_INVALIDARG | A parameter is invalid. |
| E_FAIL | An unspecified error occurred. |

## Remarks

This method completes creating a MAC key. For information about MAC creation, see [Message Authentication](https://learn.microsoft.com/windows/desktop/WMDM/message-authentication).

#### Examples

The following example code checks the MAC received by a call to [IWMDMStorage::GetRights](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-getrights) to verify that the data has not been tampered with.

```cpp

HRESULT hr;
CSecureChannelClient *pSPClient = NULL;
hr = m_pStorage->GetRights(ppRights, pnRightsCount, abTempMAC);
if (SUCCEEDED(hr))
{
    // Verify MAC returned by GetRights on the service provider.
    pSPClient->MACInit(&hMAC);
    pSPClient->MACUpdate(hMAC, (BYTE*)(*ppRights),
                       sizeof(WMDMRIGHTS) * (*pnRightsCount));
    pSPClient->MACUpdate(hMAC, (BYTE*)(pnRightsCount),
                        sizeof(*pnRightsCount));
    pSPClient->MACFinal(hMAC, abMACVerify);
    if (memcmp(abMACVerify, abTempMAC, WMDM_MAC_LENGTH) != 0)
    {
        hr = WMDM_E_MAC_CHECK_FAILED;
        goto exit;
    }
}

```

## See also

[CSecureChannelClient Class](https://learn.microsoft.com/windows/desktop/WMDM/csecurechannelclient-class)

[CSecureChannelClient::MACUpdate](https://learn.microsoft.com/previous-versions/bb231593(v=vs.85))

[Message Authentication](https://learn.microsoft.com/windows/desktop/WMDM/message-authentication)