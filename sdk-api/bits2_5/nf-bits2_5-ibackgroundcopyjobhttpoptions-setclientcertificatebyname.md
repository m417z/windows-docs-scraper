# IBackgroundCopyJobHttpOptions::SetClientCertificateByName

## Description

Specifies the subject name of the client certificate to use for client authentication in an HTTPS (SSL) request.

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

### `SubjectName` [in]

Null-terminated string that contains the simple subject name of the certificate. If the subject name contains multiple relative distinguished names (RDNs), you can specify one or more adjacent RDNs. If you specify more than one RDN, the list is comma-delimited. The string is limited to 256 characters, including the null terminator. You cannot specify an empty subject name.

Do not include the object identifier in the name. You must specify the RDNs in the reverse order from what the certificate displays. For example, if the subject name in the certificate is "CN=name1, OU=name2, O=name3", specify the subject name as "name3, name2, name1".

## Return value

The following table lists some of the possible return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_ACCESSDENIED** | The user does not have permission to access the store location. |
| **E_NOTIMPL** | The value for *StoreLocation* is not defined in the [BG_CERT_STORE_LOCATION](https://learn.microsoft.com/windows/win32/api/bits2_5/ne-bits2_5-bg_cert_store_location) enumeration. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | Could not find a store matching the value of the *StoreName* parameter. |
| **CRYPT_E_NOT_FOUND** | A certificate matching the subject name was not found. |
| **RPC_X_NULL_REF_POINTER** | The *StoreName* or *SubjectName* parameter cannot be **NULL**. |
| **BG_E_STRING_TOO_LONG** | The *StoreName* or *SubjectName* parameter is more than 256 characters. |
| **BG_E_INVALID_STATE** | The state of the job cannot be BG_JOB_STATE_CANCELLED or BG_JOB_STATE_ACKNOWLEDGED. |

## Remarks

Only the job owner can specify the client certificate. If the job changes ownership, BITS removes the certificate from the job.

The client certificate is applicable only for remote files that use the HTTP or HTTPS protocol. You can specify a certificate for all job types.

When a website accepts but does not require an SSL client certificate, and the BITS job does not specify a client certificate, the job will fail with ERROR_WINHTTP_CLIENT_AUTH_CERT_NEEDED (0x80072f0c).

The method uses the subject name string to perform a substring search for the certificate. Since subject names are not necessarily unique, this method searches the store for the first certificate that uses the given subject name and is a client authentication certificate. You should provide the complete subject name for a better chance of finding a single match. If the certificate is not correct (not trusted), the job will fail with BG_E_HTTP_ERROR_403 when BITS tries to transfer the file and the job will move to the error state. If you cannot guarantee a unique subject name, consider using the [IBackgroundCopyJobHttpOptions::SetClientCertificateByID](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-setclientcertificatebyid) method instead.

SmartCard certificate identifiers (thumbprints) are not supported.

#### Examples

The following example shows how to specify a client certificate for a job by using the subject name of the certificate. The example assumes that pJob points to a valid job.

```cpp

  HRESULT hr = S_OK;
  IBackgroundCopyJob* pJob = NULL;
  IBackgroundCopyJobHttpOptions* pHttpOptions = NULL;

  // Change list of names to actual list of names.
  LPWSTR pSubjectName = L"name3, name2, name1";

  hr = pJob->QueryInterface(__uuidof(IBackgroundCopyJobHttpOptions), (void**)&pHttpOptions);
  pJob->Release();
  if (FAILED(hr))
  {
    wprintf(L"pJob->QueryInterface failed with 0x%x.\n", hr);
    goto cleanup;
  }

  // Use the client certificate in the current user's personal (MY) store.
  hr = pHttpOptions->SetClientCertificateByName(BG_CERT_STORE_LOCATION_CURRENT_USER,
                                      L"MY", pSubjectName));
  if (FAILED(hr))
  {
    wprintf(L"pHttpOptions->SetClientCertificateByName failed with 0x%x.\n", hr);
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

[IBackgroundCopyJobHttpOptions::SetClientCertificateByID](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-setclientcertificatebyid)