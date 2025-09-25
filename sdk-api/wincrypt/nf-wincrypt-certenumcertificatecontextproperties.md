# CertEnumCertificateContextProperties function

## Description

The **CertEnumCertificateContextProperties** function retrieves the first or next extended property associated with a [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). Used in a loop, this function can retrieve in sequence all of the extended properties associated with a *certificate context*.

## Parameters

### `pCertContext` [in]

A pointer to the
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure of the certificate containing the properties to be enumerated.

### `dwPropId` [in]

Property number of the last property enumerated. To get the first property, *dwPropId* is zero. To retrieve subsequent properties, *dwPropId* is set to the property number returned by the last call to the function. To enumerate all the properties, function calls continue until the function returns zero.

Applications can call
[CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty) with the *dwPropId* returned by this function to retrieve that property's data.

## Return value

The return value is a **DWORD** value that identifies a [certificate context's](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) property. The **DWORD** value returned by one call of the function can be supplied as the *dwPropId* in a subsequent call to the function. If there are no more properties to be enumerated or if the function fails, zero is returned.

## Remarks

CERT_KEY_PROV_HANDLE_PROP_ID and CERT_KEY_SPEC_PROP_ID properties are stored as members of the CERT_KEY_CONTEXT_PROP_ID property. They are not enumerated individually.

#### Examples

See
[Example C Program: Listing the Certificates in a Store](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-listing-the-certificates-in-a-store).

## See also

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty)

[Extended Property Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)