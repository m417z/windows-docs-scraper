# IOCSPAdmin::GetHashAlgorithms

## Description

The **GetHashAlgorithms** method gets a list of hash-algorithm names. The Online Certificate Status Protocol (OCSP) responder server uses these names to sign OCSP responses for a given [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) configuration.

## Parameters

### `bstrServerName` [in]

A string that contains the responder-server name.

### `bstrCAId` [in]

A string that contains an **OCSPCAConfiguration** [Identifier](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-iocspcaconfiguration-get_identifier).

### `pVal` [out]

The list of hash algorithms with which a responder server can sign responses.

## Return value

### C++

If the method succeeds, it returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

A list of hash algorithms with which a responder server can sign responses.

## See also

[IOCSPAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspadmin)