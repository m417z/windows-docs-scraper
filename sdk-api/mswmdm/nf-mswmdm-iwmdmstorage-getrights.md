# IWMDMStorage::GetRights

## Description

The **GetRights** method retrieves rights information for a licensed storage.

## Parameters

### `ppRights` [out]

Pointer to an array of [WMDMRIGHTS](https://learn.microsoft.com/windows/desktop/WMDM/wmdmrights) structures that contain the storage rights. This parameter is included in the message authentication code. Windows Media Device Manager allocates this memory, and the application must release it with **CoTaskMemFree**.

### `pnRightsCount` [out]

Pointer to the number of **WMDMRIGHTS** structures in the *ppRights* array. This parameter is included in the message authentication code.

### `abMac` [in, out]

Array of bytes containing the message authentication code (MAC) for the parameter data of this method.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Object rights describe the usage permissions for digital media content. For example, the **WMDMRIGHTS** structure can contain information concerning how many times a file can be played and who can play it. This method will fail if this is not a licensed file.

The *ppRights* array is allocated by this method, and must be freed by the application using **CoTaskMemFree**, a standard Win32 function.

To receive progress events for this call, use [IWMDMStorage4::GetRightsWithProgress](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage4-getrightswithprogress).

After calling this method, an application can calculate the message authentication code (MAC) values of parameters and compare them with output MAC values to ensure that the parameters have not been tampered with. The following example code shows one way to do this.

#### Examples

```cpp

CSecureChannelClient  *pSCClient;
IWMDMStorage  *pStorgae;

HMAC  hMAC;
BYTE  abMAC[WMDM_MAC_LENGTH];
BYTE  abMACVerify[WMDM_MAC_LENGTH];

hr = pStorage->GetRights(&pRights, &nRightsCount, abMAC);
if (SUCCEEDED(hr))
{
    //
    // First verify the integrity of the retrieved rights.
    //
    pSCClient->MACInit(&hMAC);
    pSCClient->MACUpdate(hMAC, (BYTE*)(pRights),
                    sizeof(WMDMRIGHTS) * nRightsCount);
    pSCClient->MACUpdate(hMAC, (BYTE*)(&nRightsCount),
                                 sizeof(nRightsCount));
    pSCClient->MACFinal(hMAC, (BYTE*)abMACVerify);
    if (memcmp(abMACVerify, abMAC, sizeof(abMAC)) != 0)
    {
        hr = WMDM_E_MAC_CHECK_FAILED;
    }
}

```

## See also

[IWMDMStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage)

[Using Secure Authenticated Channels](https://learn.microsoft.com/windows/desktop/WMDM/using-secure-authenticated-channels)

[WMDMRIGHTS](https://learn.microsoft.com/windows/desktop/WMDM/wmdmrights)