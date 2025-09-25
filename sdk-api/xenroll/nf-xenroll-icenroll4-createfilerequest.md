# ICEnroll4::createFileRequest

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **createFileRequest** method creates a PKCS #10 certificate request, a PKCS #7 request, or a full [Certificate Management over CMS](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CMC) request and stores it in a file.
This method was first defined in the [ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4) interface.

## Parameters

### `Flags` [in]

A value that specifies the type of certificate to create. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **XECR_CMC** | Full CMC |
| **XECR_PKCS10_V1_5** | PKCS 10 |
| **XECR_PKCS10_V2_0** | PKCS 10 version 2 |
| **XECR_PKCS7** | PKCS 7 |

### `strDNName` [in]

This parameter can be **NULL**; otherwise, this parameter specifies the distinguished name (DN) of the entity for which the request is being made. The DN name must follow the [X.500](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) naming convention, for example "CN=User, O=Microsoft". If a two-letter prefix does not exist, an OID can be provided instead.

### `strUsage` [in]

An [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) that describes the purpose of the request being generated, for example, individual or commercial Authenticode certificate, or client authentication. You can also specify multiple OIDs separated by a comma.

### `strRequestFileName` [in]

The name of the file that will receive the request.

## Return value

### VB

If the method succeeds, the method returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see
[Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

When this method is called from script, the method displays a user interface that asks whether the user will allow creation of a certificate request and whether the user will allow a write operation to the file system.