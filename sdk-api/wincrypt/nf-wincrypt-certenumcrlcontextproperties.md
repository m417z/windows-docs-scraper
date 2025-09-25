# CertEnumCRLContextProperties function

## Description

The **CertEnumCRLContextProperties** function retrieves the first or next extended property associated with a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) context. Used in a loop, this function can retrieve in sequence all extended properties associated with a CRL context.

## Parameters

### `pCrlContext` [in]

A pointer to a
[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) structure.

### `dwPropId` [in]

Property number of the last property enumerated. To get the first property, *dwPropId* is zero. To retrieve subsequent properties, *dwPropId* is set to the property number returned by the last call to the function. To enumerate all the properties, function calls continue until the function returns zero.

Applications can call
[CertGetCRLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcrlcontextproperty) with the *dwPropId* returned by this function to retrieve that property's data.

## Return value

The return value is a **DWORD** value that identifies a CRL context's property. The **DWORD** value returned by one call of the function can be supplied as the *dwPropId* in a subsequent call to the function. If there are no more properties to be enumerated or if the function fails, zero is returned.

## See also

[CertGetCRLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcrlcontextproperty)

[Extended Property Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)