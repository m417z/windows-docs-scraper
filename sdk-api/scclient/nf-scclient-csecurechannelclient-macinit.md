# CSecureChannelClient::MACInit

## Description

The **MACInit** method acquires a message authentication code (MAC) channel.

## Parameters

### `phMAC` [out]

Pointer to the MAC handle for the parameter data. The handle is acquired by **MACInit** to be used for subsequent [MACUpdate](https://learn.microsoft.com/previous-versions/bb231593(v=vs.85)) and [MACFinal](https://learn.microsoft.com/previous-versions/bb231591(v=vs.85)) calls. This datatype is declared in Sac.h installed with the Windows Media Format SDK.

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
| E_INVALIDARG | The phMAC parameter is invalid or is a **NULL** pointer. |
| E_FAIL | An unspecified error occurred. |

## Remarks

**MACInit** begins a message authentication code (MAC) session. For example, **MACInit** should be called before content is transferred when writing to a storage device to verify the MAC returned by the [IMDSPStorage::GetRights](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage-getrights) call on the service provider.

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

[CSecureChannelClient::MACFinal](https://learn.microsoft.com/previous-versions/bb231591(v=vs.85))

[CSecureChannelClient::MACUpdate](https://learn.microsoft.com/previous-versions/bb231593(v=vs.85))

[Message Authentication](https://learn.microsoft.com/windows/desktop/WMDM/message-authentication)