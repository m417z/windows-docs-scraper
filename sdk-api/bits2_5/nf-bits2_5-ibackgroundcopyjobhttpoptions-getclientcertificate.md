# IBackgroundCopyJobHttpOptions::GetClientCertificate

## Description

Retrieves the client certificate from the job.

## Parameters

### `pStoreLocation` [out]

Identifies the location of a system store to use for looking up the certificate. For possible values, see the [BG_CERT_STORE_LOCATION](https://learn.microsoft.com/windows/win32/api/bits2_5/ne-bits2_5-bg_cert_store_location) enumeration.

### `pStoreName` [out]

Null-terminated string that contains the name of the certificate store. To free the string when done, call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

### `ppCertHashBlob` [out]

SHA1 hash that identifies the certificate. To free the blob when done, call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

### `pSubjectName` [out]

Null-terminated string that contains the simple subject name of the certificate. The RDNs in the subject name are in the reverse order from what the certificate displays. Subject name can be empty if the certificate does not contain a subject name. To free the string when done, call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

The following table lists some of the possible return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully retrieved the certificate. |
| **RPC_X_BAD_STUB_DATA** | The job does not specify a certificate or the user does not have permissions to the certificate. |
| **RPC_X_NULL_REF_POINTER** | One of the parameters is **NULL**. |

## Remarks

You use the [IBackgroundCopyJobHttpOptions::SetClientCertificateByID](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-setclientcertificatebyid) or [IBackgroundCopyJobHttpOptions::SetClientCertificateByName](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-setclientcertificatebyname) method to specify the certificate.

#### Examples

The following example shows how to retrieve information about the client certificate. The example assumes pJob points to a valid job.

```cpp
#define THUMBPRINT_SIZE 20

  HRESULT hr = S_OK;
  IBackgroundCopyJob* pJob = NULL;
  IBackgroundCopyJobHttpOptions* pHttpOptions = NULL;
  GUID JobId;

  BG_CERT_STORE_LOCATION StoreLocation;
  LPWSTR pStoreName = NULL;
  BYTE* pThumbprint = NULL;
  LPWSTR pSubjectName = NULL;

  // Retrieve a pointer to the IBackgroundCopyJobHttpOptions interface.
  hr = pJob->QueryInterface(__uuidof(IBackgroundCopyJobHttpOptions), (void**)&pHttpOptions);
  pJob->Release();
  if (FAILED(hr))
  {
    wprintf(L"pJob->QueryInterface failed with 0x%x.\n", hr);
    goto cleanup;
  }

  // Retrieve information about the client certificate set on the job.
  hr = pHttpOptions->GetClientCertificate(&StoreLocation, &pStoreName,
         &pThumbprint, &pSubjectName);
  if (S_OK == hr)
  {
    wprintf(L"\nLocation: %d\nStore name: %s\nSubject: %s\n",
        StoreLocation, pStoreName, pSubjectName);

    wprintf(L"Thumbprint: ");
    for (DWORD i = 0; i < THUMBPRINT_SIZE; i++)
    {
      wprintf(L"%x ", pThumbprint[i]);
    }
    wprintf(L"\n");

    CoTaskMemFree(pStoreName);
    CoTaskMemFree(pThumbprint);
    CoTaskMemFree(pSubjectName);
  }
  else if (RPC_X_BAD_STUB_DATA == hr)
  {
    wprintf(L"The job does not specify a client certificate or\n"
            L"the user does not have permission to access the certificate.\n");
  }
  else
  {
    wprintf(L"pHttpOptions->GetClientCertificate failed with 0x%x.\n", hr);
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

[IBackgroundCopyJobHttpOptions::RemoveClientCertificate](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-removeclientcertificate)

[IBackgroundCopyJobHttpOptions::SetClientCertificateByID](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-setclientcertificatebyid)

[IBackgroundCopyJobHttpOptions::SetClientCertificateByName](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-setclientcertificatebyname)