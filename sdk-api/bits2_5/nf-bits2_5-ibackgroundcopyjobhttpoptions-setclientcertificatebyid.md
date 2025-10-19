# IBackgroundCopyJobHttpOptions::SetClientCertificateByID

## Description

Specifies the identifier of the client certificate to use for client authentication in an HTTPS (SSL) request.

## Parameters

### `StoreLocation` [in]

Identifies the location of a system store to use for looking up the certificate. For possible values, see the [BG_CERT_STORE_LOCATION](https://learn.microsoft.com/windows/win32/api/bits2_5/ne-bits2_5-bg_cert_store_location) enumeration.

### `StoreName` [in]

Null-terminated string that contains the name of the certificate store. The string is limited to 256 characters, including the null terminator. You can specify one of the following system stores or an application-defined store. The store can be a local or remote store.

| Value | Meaning |
| --- | --- |
| **CA** | Certification authority certificates |
| **MY** | Personal certificates |
| **ROOT** | Root certificates |
| **SPC** | Software Publisher Certificate |

### `pCertHashBlob` [in]

SHA1 hash that identifies the certificate. Use a 20 byte buffer for the hash. For more information, see Remarks.

## Return value

The following table lists some of the possible return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_ACCESSDENIED** | The user does not have permission to access the store location. |
| **E_NOTIMPL** | The value for the *StoreLocation* parameter is not defined in the [BG_CERT_STORE_LOCATION](https://learn.microsoft.com/windows/win32/api/bits2_5/ne-bits2_5-bg_cert_store_location) enumeration. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | Could not find a store matching the *StoreName* parameter. |
| **CRYPT_E_NOT_FOUND** | A certificate matching the hash was not found. |
| **RPC_X_NULL_REF_POINTER** | The *StoreName* or *pCertHashBlob* parameter cannot be **NULL**. |
| **RPC_X_BAD_STUB_DATA** | The *pCertHashBlob* buffer size is not 20 bytes. |
| **BG_E_STRING_TOO_LONG** | The *StoreName* parameter is more than 256 characters. |
| **BG_E_INVALID_STATE** | The state of the job cannot be BG_JOB_STATE_CANCELLED or BG_JOB_STATE_ACKNOWLEDGED. |

## Remarks

Only the job owner can specify the client certificate. If the job changes ownership, BITS removes the certificate from the job.

The client certificate is applicable only for remote files that use the HTTP or HTTPS protocol. You can specify a certificate for all job types.

When a website accepts but does not require an SSL client certificate, and the BITS job does not specify a client certificate, the job will fail with ERROR_WINHTTP_CLIENT_AUTH_CERT_NEEDED (0x80072f0c).

If you create a certificate for the job or application, you could store the certificate identifier (thumbprint) in the registry or database and use it when a job requires a certificate. You could also enumerate the certificates in the store and let the user choose the certificate. Another alternative is to call the [CertFindCertificateInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindcertificateinstore) function to retrieve the certificate context based on some criteria. Using the context, call the [CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty) function to retrieve the hash (specify CERT_HASH_PROP_ID for *dwPropId*).

SmartCard thumbprints are not supported.

#### Examples

The following example shows how to specify a client certificate for a job using the thumbprint of the certificate. The example hard codes the thumbprint of the certificate and assumes pJob points to a valid job.

```cpp

  HRESULT hr = S_OK;
  IBackgroundCopyJob* pJob = NULL;
  IBackgroundCopyJobHttpOptions* pHttpOptions = NULL;
  BYTE Thumbprint[] = {0xa1, 0x06, 0x6e, 0x13, 0xf2, 0x34, 0x49, 0x0a, 0x22, 0xd7, 0x6f, 0xb2, 0x80, 0xab, 0x68, 0x7d, 0x16, 0x55, 0xb3, 0x14};

  // Retrieve a pointer to the IBackgroundCopyJob4 interface.
  hr = pJob->QueryInterface(__uuidof(IBackgroundCopyJobHttpOptions), (void**)&pHttpOptions);
  pJob->Release();
  if (FAILED(hr))
  {
    wprintf(L"QueryInterface for HttpOptions failed with 0x%x.\n", hr);
    goto cleanup;
  }

  // Use the client certificate in the current user's personal (MY) store.
  hr = pHttpOptions->SetClientCertificateByID(BG_CERT_STORE_LOCATION_CURRENT_USER,
      L"MY", Thumbprint);
  if (FAILED(hr))
  {
    wprintf(L"pHttpOptions->SetClientCertificateByID failed with 0x%x.\n", hr);
    goto cleanup;
  }

cleanup:

  if (pHttpOptions)
  {
    hr = pHttpOptions->Release();
  }

```

## See also

[IBackgroundCopyJobHttpOptions](https://learn.microsoft.com/windows/desktop/api/bits2_5/nn-bits2_5-ibackgroundcopyjobhttpoptions)

[IBackgroundCopyJobHttpOptions::GetClientCertificate](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-getclientcertificate)

[IBackgroundCopyJobHttpOptions::RemoveClientCertificate](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-removeclientcertificate)

[IBackgroundCopyJobHttpOptions::SetClientCertificateByName](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-setclientcertificatebyname)