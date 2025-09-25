# CertCreateCTLEntryFromCertificateContextProperties function

## Description

The **CertCreateCTLEntryFromCertificateContextProperties** function creates a [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) entry whose attributes are the properties of the certificate context. The SubjectIdentifier in the CTL entry is the SHA1 hash of the certificate.

The certificate properties are added as attributes. The property attribute OID is the decimal PROP_ID preceded by szOID_CERT_PROP_ID_PREFIX. Each property value is copied as a single attribute value.

Additional attributes can be included in the CTL entry by using the *cOptAttr* and *rgOptAttr* parameters.

## Parameters

### `pCertContext` [in]

A pointer to the [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) used to create the CTL.

### `cOptAttr` [in]

A **DWORD** that specifies the number of additional attributes to be added.

### `rgOptAttr` [in]

A pointer to any array of [CRYPT_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute) attributes to be added to the CTL.

### `dwFlags` [in]

A **DWORD**. Can be set to CTL_ENTRY_FROM_PROP_CHAIN_FLAG to force the inclusion of the chain building hash properties as attributes.

### `pvReserved` [in]

A pointer to a **VOID**. Reserved for future use.

### `pCtlEntry` [out]

Address of a pointer to a [CTL_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_entry) structure. Call this function twice to retrieve a CTL entry. Set this parameter to **NULL** on the first call. When the function returns, use the number of bytes retrieved from the *pcbCtlEntry* parameter to allocate memory. Call the function again, setting this parameter to the address of the allocated memory.

### `pcbCtlEntry` [in, out]

 Pointer to a **DWORD** that contains the number of bytes that must be allocated for the [CTL_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_entry) structure. Call this function twice to retrieve the number of bytes. For the first call, set this parameter to the address of a **DWORD** value that contains zero and set the *pCtlEntry* parameter to **NULL**. If the first call succeeds, the **DWORD** value will contain the number of bytes that you must allocate for the **CTL_ENTRY** structure. Allocate the required memory and call the function again, supplying the address of the memory in the *pCtlEntry* parameter.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).