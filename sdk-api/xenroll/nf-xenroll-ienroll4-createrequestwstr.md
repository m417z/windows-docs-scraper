# IEnroll4::createRequestWStr

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **createRequestWStr** method creates a PKCS #10, PKCS #7, or full [Certificate Management over CMS](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CMC) format [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) and stores it in a BLOB. This method was first defined in the [IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4) interface.

## Parameters

### `Flags` [in]

Value specifying the type of certificate request to create. Specify one of the following values.

| Value | Meaning |
| --- | --- |
| **XECR_CMC** | Full CMC |
| **XECR_PKCS10_V1_5** | PKCS #10 |
| **XECR_PKCS10_V2_0** | PKCS #10 version 2 |
| **XECR_PKCS7** | PKCS #7 |

### `pwszDNName` [in]

A pointer to a **null**-terminated Unicode string that contains the distinguished name (DN) of the entity for which the request is being made. The DN name must follow the [X.500](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) naming convention, for example "CN=User, O=Microsoft". If a two-letter prefix does not exist, an object identifier (OID) may be provided instead. This parameter may be **NULL**.

### `pwszUsage` [in]

A pointer to a **null**-terminated Unicode string that contains the OID that describes the purpose of the certificate being generated, for example, individual or commercial Authenticode certificate, or client authentication. You can also specify multiple OIDs separated by a comma.

### `pblobRequest` [out]

A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that receives the request.

When you have finished using this memory, free it by passing the **pbData** member of this structure to the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

 If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)