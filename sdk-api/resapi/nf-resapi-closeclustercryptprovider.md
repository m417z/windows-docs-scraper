# CloseClusterCryptProvider function

## Description

Closes a handle to a Cryptographic Service Provider (CSP). The **PCLOSE_CLUSTER_CRYPT_PROVIDER** type defines a pointer to this function.

## Parameters

### `hClusCryptProvider` [in]

A [HCLUSCRYPTPROVIDER](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn823545(v=vs.85)) structure that contains a handle to a CSP.

## Return value

If the operation completes successfully, this function returns **ERROR_SUCCESS**; otherwise, it returns a system error code.

## See also

[Cryptography Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cryptography-functions)

[OpenClusterCryptProvider](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-openclustercryptprovider)