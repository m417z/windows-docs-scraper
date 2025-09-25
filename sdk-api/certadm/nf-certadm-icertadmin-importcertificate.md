# ICertAdmin::ImportCertificate

## Description

The **ImportCertificate** method takes a previously issued certificate and imports it to the [certification authority's](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) database. This method was first defined in the [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin) interface.

 For the requirements that the certificate must meet to be successfully imported, see Remarks.

## Parameters

### `strConfig` [in]

Represents a valid configuration string for the certification authority in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the Certificate Services server's network name, and CANAME is the common name of the certification authority, as entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

**Important** **ImportCertificate** does not clear the internal cache when the configuration string is changed. When you change the configuration string for the CA, you must instantiate a new [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2) object and call this method again with the new configuration string.

### `strCertificate` [in]

The binary representation of the certificate being imported.

### `Flags` [in]

Specifies the format of the certificate. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CR_IN_BASE64HEADER** | BASE64 format with begin/end. |
| **CR_IN_BASE64** | BASE64 format without begin/end. |
| **CR_IN_BINARY** | Binary format. |

### `pRequestId` [out]

A pointer to a **LONG** value that receives the database-assigned request ID for the imported certificate.

## Return value

### C++

If the method succeeds, and the *pRequestID* parameter is set to the value of the database-assigned request ID for the imported certificate, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the database-assigned request ID for the imported certificate.

## Remarks

The **ImportCertificate** method is useful in the case of a certification authority that has been partially restored from backup: If a certificate is not on the backup tapes used to restore the certification authority but exists in a file, the certificate can be imported by means of this method.

For this method to succeed, the certificate being imported must have been previously issued by the certification authority specified in *strConfig*. The restored certification authority will validate the certificate's signature, and if the signature is not valid, the method call will fail.

Furthermore, you cannot import a certificate if it already exists in the database. Each certificate in the database must be unique. The database ensures uniqueness by checking the certificate's serial number.

#### Examples

```cpp
// This code imports a binary certificate file.
BSTR   bstrCert = NULL;  // Variable for certificate.
HANDLE hFile;
DWORD  cchFile, cbRead;
LONG   nID;  // Variable for request ID.

// Open the file that contains the certificate.
hFile = CreateFile((LPCSTR) "d:\\cert1.cer",
                  GENERIC_READ,
                  FILE_SHARE_READ,
                  NULL,
                  OPEN_EXISTING,
                  0,
                  NULL);
if (INVALID_HANDLE_VALUE == hFile)
{
    printf("Unable to open file\n");
    // Take error action as needed.
}
// Determine the file size.
cchFile = GetFileSize(hFile, NULL);
if ( (DWORD)-1 == cchFile )
{
    printf("Failed GetFileSize\n");
    CloseHandle(hFile);
    // Take error action as needed.
}
// Allocate the memory for the certificate.
bstrCert = SysAllocStringByteLen(NULL, cchFile);
if (NULL == bstrCert)
{
    printf("Failed SysAllocStringByteLen\n");
    CloseHandle(hFile);
    // Take error action as needed.
}
// Read in the certificate.
if (!ReadFile(hFile,
             (char *)bstrCert,
             cchFile,
             &cbRead,
             NULL) || (cbRead != cchFile))
{
    printf("Failed to successfully read file\n");
    CloseHandle(hFile);
    SysFreeString(bstrCert);
    // Take error action as needed.
}
// Close the file.
CloseHandle(hFile);

// Import the certificate.
bstrCA = SysAllocString(L"<COMPUTERNAMEHERE>\\<CANAMEHERE>");
if (FAILED(hr))
{
    printf("Failed to allocate memory for bstrCA\n");
    SysFreeString(bstrCert);
    // Take error action as needed.
}

hr = pCertAdmin->ImportCertificate(bstrCA,
                                   bstrCert,
                                   CR_IN_BINARY,
                                   &nID);
if (FAILED(hr))
    printf("Failed ImportCertificate [%x]\n", hr);
else
    printf("Imported certificated has Request ID: %d\n", nID);

SysFreeString(bstrCert);
SysFreeString(bstrCA);
```

## See also

[CCertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)

[ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin)

[ICertAdmin2](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)

[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig)