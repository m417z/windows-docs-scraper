# IWMDMOperation::TransferObjectData

## Description

The **TransferObjectData** method is called to allow the application to transfer a block of data to or from the computer.

## Parameters

### `pData`

Pointer to a buffer containing the data. This buffer is always allocated and freed by Windows Media Device Manager. Your application should never allocate or free this buffer.

**BeginRead**[in] During a read from device, incoming data that must be decrypted using the [CSecureChannelClient::DecryptParam](https://learn.microsoft.com/previous-versions/bb231586(v=vs.85)) method. The application does not need to deallocate the buffer.

**BeginWrite**[in, out] During a write to device, on input is a memory buffer *pdwSize* bytes long, allocated by Windows Media Device Manager. The application should fill this buffer with data that has been encrypted using the [CSecureChannelClient::EncryptParam](https://learn.microsoft.com/previous-versions/bb231587(v=vs.85)) method.

### `pdwSize`

Pointer to a **DWORD** that specifies the transfer buffer size.

**BeginRead**[in, out] On input, the size of the incoming data in *pData*. On output, the amount of data the application has actually read.

**BeginWriteOn** input, the size of the *pData* buffer. On output, the actual size of the data sent out.

### `abMac`

Array of bytes specifying the message authentication code for the parameter data of this method.

**BeginRead**[in] A MAC generated from *pData* and *pdwSize* that the application should check after *pData* is decrypted, to verify that the data has not been modified.

**BeginWrite**[out] A MAC generated from *pData* and *pdwSize* before *pData* is encrypted.

## Return value

The application should return one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The read operation should continue. |
| **WMDM_E_USER_CANCELLED** | The read operation should be cancelled without finishing. |
| **E_FAIL** | An unspecified error occurred, and the read operation should be cancelled without finishing. |

## Remarks

The application can determine whether data is being read from or written to the device by monitoring whether [BeginRead](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-beginread) or [BeginWrite](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-beginwrite) was called just before this method was called.

#### Examples

The following C++ code demonstrates how an application might implement **TransferObjectData** to handle file transfer itself. The code shown handles both reading data from and writing data to the device. The direction of data flow is indicated by a member variable **m_OperationStatus**, set in a prior call to **BeginRead** or **BeginWrite**.

```cpp

HRESULT TransferObjectData(BYTE* pData, DWORD* pdwSize, BYTE* pMac)
{
    HRESULT hr = S_OK;

    // Verify parameters.
    if (pData == NULL || pdwSize == NULL || pMac == NULL || m_File == INVALID_HANDLE_VALUE)
    {
        // TODO: Display the message: "Invalid argument in SetObjectTotalSize."
        return E_INVALIDARG;
    }
    if ((m_OperationStatus != OPERATION_READ) && (m_OperationStatus != OPERATION_WRITE))
    {
        // TODO: Display the message: "Unable to determine direction of data transfer."
        return E_FAIL;
    }

    //////////////////////////////////////////////////////////////////////////
// Sending data to the device.
//////////////////////////////////////////////////////////////////////////
    if (m_OperationStatus == OPERATION_WRITE)
    {
        DWORD   dwReadLen;
        // The SAC is used to encrypt the data sent to the device.
        if (m_pSAC == NULL)
        {
               // TODO: Display the message: "SAC not initialized in TransferObjectData."
            return E_FAIL;
        }

        // Read pdwSize bytes from the file into pData.
        dwReadLen = *pdwSize;
        if (ReadFile(m_File, pData, dwReadLen, pdwSize, NULL) == FALSE)
        {
               // TODO: Display the message: "Couldn't read the file in TransferObjectData."
            return E_FAIL;
        }

        // If there is no more data, terminate the transfer.
        if (*pdwSize == 0)
        {
            return S_FALSE;
        }

        // Create the MAC to return to Windows Media Device Manager.
        HMAC hMAC;
        hr = m_pSAC->MACInit(&hMAC);
        hr = m_pSAC->MACUpdate(hMAC, (BYTE*)(pData), *pdwSize);
        hr = m_pSAC->MACUpdate(hMAC, (BYTE*)(pdwSize), sizeof(DWORD));
        hr = m_pSAC->MACFinal(hMAC, (BYTE*)pMac);
        if (hr != S_OK) return E_FAIL;

        // Encrypt the data to send to the service provider/device.
        hr = m_pSAC->EncryptParam((BYTE*)(pData), *pdwSize);
        if (hr != S_OK)
        {
            return E_FAIL;
        }
    }
    //////////////////////////////////////////////////////////////////////////
// Receiving data from the device.
//////////////////////////////////////////////////////////////////////////
    else
    {
        // Copy the data to a temporary file for decryption.
        BYTE *pTmpData = new BYTE [*pdwSize];
        if (pTmpData == NULL)
        {
            return E_OUTOFMEMORY;
        }
        memcpy(pTmpData, pData, *pdwSize);

        // Decrypt the pData Parameter
        hr = m_pSAC->DecryptParam(pTmpData, *pdwSize);

        // Verify the MAC of the decrypted data.
        HMAC hMAC;
        BYTE pTestMac[WMDM_MAC_LENGTH];
        hr = m_pSAC->MACInit(&hMAC);
        hr = m_pSAC->MACUpdate(hMAC, (BYTE*)(pTmpData), *pdwSize);
        hr = m_pSAC->MACUpdate(hMAC, (BYTE*)(pdwSize), sizeof(*pdwSize));
        hr = m_pSAC->MACFinal(hMAC, pTestMac);
        if ((memcmp(pMac, pTestMac, WMDM_MAC_LENGTH) != 0) || (hr != S_OK))
        {
            delete [] pTmpData;
            return WMDM_E_MAC_CHECK_FAILED;
        }

        // Write the data to file, and record the amount of data written.
        DWORD dwWritten = 0;
        if (WriteFile(m_File,pTmpData,*pdwSize,&dwWritten,NULL))
        {
            hr = S_OK;
            *pdwSize = dwWritten;
        }
        else
        {
            hr = HRESULT_FROM_WIN32(GetLastError());
        }
        if (pTmpData)
        {
            delete [] pTmpData;
        }
    }
    return hr;
}

```

## See also

[Encryption and Decryption](https://learn.microsoft.com/windows/desktop/WMDM/encryption-and-decryption)

[Handling File Transfers Manually](https://learn.microsoft.com/windows/desktop/WMDM/handling-file-transfers-manually)

[IWMDMOperation Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation)

[Using Secure Authenticated Channels](https://learn.microsoft.com/windows/desktop/WMDM/using-secure-authenticated-channels)