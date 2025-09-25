# CSecureChannelClient::MACUpdate

## Description

The **MACUpdate** method adds a value to a message authentication code (MAC).

## Parameters

### `hMAC` [in]

Handle to the array specifying the MAC for the current parameter data. This handle is returned from the [MACInit](https://learn.microsoft.com/previous-versions/bb231592(v=vs.85)) method. This datatype is declared in Sac.h installed with the Windows Media Format SDK.

### `pbData` [in]

Pointer to the parameter data to add to the MAC value.

### `dwDataLen`

**DWORD** specifying the length of the data to which *pbData* points.

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
| E_INVALIDARG | A parameter is invalid or is a **NULL** pointer. |
| E_FAIL | An unspecified error occurred. |

## Remarks

An application calls **MACUpdate** repeatedly with each piece of data to add to the MAC. **MACInit** must always be called before **MACUpdate**, and [MACFinal](https://learn.microsoft.com/previous-versions/bb231591(v=vs.85)) must always be called after **MACUpdate**. **MACInit** acquires the MAC handle, **phMAC**, to be used by the **MACUpdate** and **MACFinal** methods.

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

[Message Authentication](https://learn.microsoft.com/windows/desktop/WMDM/message-authentication)