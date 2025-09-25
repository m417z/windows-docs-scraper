# IEnroll::createFilePKCS10WStr

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **createFilePKCS10WStr** method creates a base64-encoded PKCS #10 [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) and saves it in a file. This method was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

This method differs from
the [createPKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createpkcs10wstr) method only in saving the base64-encoded PKCS #10 certificate request to the file specified by the *wszPKCS10FileName* parameter.

## Parameters

### `DNName` [in]

The distinguished name (DN) of the entity for which the request is being made. *DNName* must follow the [X.500](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) naming convention. For example, "CN=User, O=Microsoft". If a two-letter prefix does not exist, an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) may be provided instead.

### `Usage` [in]

An [OID](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) that describes the purpose of the certificate being generated, for example, individual or commercial Authenticode certificate, or client authentication. You can also specify multiple OIDs separated by a comma.

The OID is passed through to the PKCS #10 request. The control does not examine the OID.

### `wszPKCS10FileName` [in]

The name of the file in which the base64-encoded PKCS #10 is saved. The contents of this file may be submitted to a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) for processing.

## Remarks

By default, the Microsoft Base Cryptographic Provider is used, and a unique signature key is created.

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)