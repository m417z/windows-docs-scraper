# CSecureChannelServer::DecryptParam

## Description

**DecryptParam** uses the session key of the secure authenticated channel to decrypt the data contained in a parameter.

## Parameters

### `pbData` [in, out]

Pointer to the first byte of a data buffer containing the encrypted parameter that is to be decrypted.

### `dwDataLen` [in]

Pointer to a **DWORD** specifying the length of the buffer to which *pbData* points.

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

Components should copy the data to a temporary buffer before calling **DecryptParam** and then decrypt the temporary buffer. This method only needs to be called for encrypted parameters. See [Using Secure Authenticated Channels](https://learn.microsoft.com/windows/desktop/WMDM/using-secure-authenticated-channels) for a table of methods that must use the message authentication code algorithm and encrypted parameters.

#### Examples

The following code shows a service provider's implementation of the [IMDSPObject::Write](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-write) method, which requires a service provider to decrypt data sent to it.

```cpp

HRESULT CMyStorage::Write(BYTE *pData, DWORD *pdwSize,
                                 BYTE abMac[WMDM_MAC_LENGTH])
{
    HRESULT  hr;
    DWORD    dwWritten = 0;
    BYTE    *pTmpData  = NULL;          // Temporary buffer to hold the
                                        // data during decryption.
    BYTE     pTempMac[WMDM_MAC_LENGTH]; // Temporary MAC that will be
                                        // copied into the abMac
                                        // out parameter.

    if( m_hFile == INVALID_HANDLE_VALUE )
    {
        return E_FAIL;
    }

    // Allocate the temporary buffer and copy the encrypted data into it.
    pTmpData = new BYTE [*pdwSize];
    if(!pTmpData)
        return E_OUTOFMEMORY;
    memcpy(pTmpData, pData, *pdwSize);

    // Decrypt the data.
    CHRg(g_pAppSCServer->DecryptParam(pTmpData, *pdwSize));

    // Check the MAC passed to the method. The MAC is built from
    // the data and data size parameters.
    // CORg is a macro that goes to the Error label on failure.
    HMAC hMAC;
    CORg(g_pAppSCServer->MACInit(&hMAC));
    CORg(g_pAppSCServer->MACUpdate(hMAC, (BYTE*)(pTmpData), *pdwSize));
    CORg(g_pAppSCServer->MACUpdate(hMAC, (BYTE*)(pdwSize), sizeof(*pdwSize)));
    CORg(g_pAppSCServer->MACFinal(hMAC, pTempMac));

    // If the MAC values don't match, return an error.
    if (memcmp(abMac, pTempMac, WMDM_MAC_LENGTH) != 0)
    {
        hr = WMDM_E_MAC_CHECK_FAILED;
        goto Error;
    }

    // The MAC values matched, so write the decrypted data to a local file.
    if( WriteFile(m_hFile,pTmpData,*pdwSize,&dwWritten,NULL) )
    {
        hr = S_OK;
    }
    else
    {
        hr = HRESULT_FROM_WIN32(GetLastError());
    }

    *pdwSize = dwWritten;

Error:

    if( pTmpData )
    {
        delete [] pTmpData;
    }

    return hr;
}

```

## See also

[CSecureChannelClient::DecryptParam](https://learn.microsoft.com/previous-versions/bb231586(v=vs.85))

[CSecureChannelClient::EncryptParam](https://learn.microsoft.com/previous-versions/bb231587(v=vs.85))

[CSecureChannelServer Class](https://learn.microsoft.com/windows/desktop/WMDM/csecurechannelserver-class)

[CSecureChannelServer::EncryptParam](https://learn.microsoft.com/previous-versions/ms868509(v=msdn.10))