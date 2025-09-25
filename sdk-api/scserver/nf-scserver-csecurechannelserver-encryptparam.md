# CSecureChannelServer::EncryptParam

## Description

The **EncryptParam** method uses the session key of the secure authenticated channel to encrypt the data contained in a parameter.

## Parameters

### `pbData`

Pointer to the first byte of a data buffer containing the parameter that is to be encrypted.

### `dwDataLen`

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

Certain parameters, listed in the tables under [Using Secure Authenticated Channels](https://learn.microsoft.com/windows/desktop/WMDM/using-secure-authenticated-channels), must be included in the message authentication code (MAC) and must be encrypted before the call for data transfer in both directions. Call **EncryptParam** to encrypt the specified parameters. Do not encrypt any parameters that do not require it.

#### Examples

The following code demonstrates a service provider's implementation of [IMDSPObject::Read](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-read). This method creates the MAC key using the data to encrypt and the size of the data, and sends them both to the application.

```cpp

HRESULT CMyStorage::Read(
    BYTE  *pData,
    DWORD *pdwSize,
    BYTE   abMac[WMDM_MAC_LENGTH])
{
    HRESULT  hr;
    DWORD    dwToRead;         // Bytes to read.
    DWORD    dwRead   = NULL;  // Bytes read.
    BYTE    *pTmpData = NULL;  // Temporary buffer to hold data before it
                               // is copied out to pData.

    // Use a global CSecureChannelServer member to verify that the client
    // is authenticated.
    if (!(g_pAppSCServer->fIsAuthenticated()))
    {
        return WMDM_E_NOTCERTIFIED;
    }

    // Verify that the handle to the file to read is valid.
    if(m_hFile == INVALID_HANDLE_VALUE)
    {
        return E_FAIL;
    }

    // Create a buffer to hold the data read.
    dwToRead = *pdwSize;
    pTmpData = new BYTE [dwToRead] ;
    if(!pTmpData)
        return E_OUTOFMEMORY;

    // Read data into the temporary buffer.
    if(ReadFile(m_hFile,(LPVOID)pTmpData,dwToRead,&dwRead,NULL))
    {
        *pdwSize = dwRead;

        if( dwRead )
        {
            // Create a MAC from all the parameters.
            // CORg is a macro that goes to Error label on failure.
            // MAC consists of data and size of data.
            HMAC hMAC;

            CORg(g_pAppSCServer->MACInit(&hMAC));
            CORg(g_pAppSCServer->MACUpdate(hMAC, (BYTE*)(pTmpData), dwRead));
            CORg(g_pAppSCServer->MACUpdate(hMAC, (BYTE*)(pdwSize), sizeof(DWORD)));
            CORg(g_pAppSCServer->MACFinal(hMAC, abMac));

            // Encrypt the data.
            CORg(g_pAppSCServer->EncryptParam(pTmpData, dwRead));

            // Copy the data from the temporary buffer into the out param.
            memcpy(pData, pTmpData, dwRead);
        }

        hr = S_OK;
    }
    else
    {
        *pdwSize = 0;

        hr = E_FAIL;
    }

Error:

    if(pTmpData)
    {
        delete [] pTmpData;
    }

    return hr;
}

```

## See also

[CSecureChannelServer Class](https://learn.microsoft.com/windows/desktop/WMDM/csecurechannelserver-class)

[CSecureChannelServer::DecryptParam](https://learn.microsoft.com/previous-versions/bb231598(v=vs.85))