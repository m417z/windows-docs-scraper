# IEnroll::acceptPKCS7Blob

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **acceptPKCS7Blob** method accepts and processes a PKCS #7 message containing a certificate. The PKCS #7 is input as a parameter. This method was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

## Parameters

### `pBlobPKCS7` [in]

Represents the base64-encoded PKCS #7 containing the certificate and the chain of certificates identifying the issuer.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. Upon successful completion of this function, the PKCS #7 will be accepted.

## Remarks

The PKCS #7 input as a parameter for **acceptPKCS7Blob** contains the request certificate and the chain of certificates identifying the issuer of the certificate. Typically, but not always, the chain of certificates does not include the root. The PKCS #7 can be in base64-encoded, binary, or [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) certificate format (with or without the "begin cert" and "end cert" tags). The certificate and the associated keys generated for it are put in the MY store. A [root certificate](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) is placed in the ROOT store, and the rest of the chain of certificates is placed in the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) store. If any ROOT certificates found in the PKCS #7 are accepted, Crypt32 will notify the user that a ROOT certificate is being added to the user's store. The user has the option of declining the ROOT certificate. This option is provided so that the user can decline to place an untrusted root in the ROOT store. Declining to place the ROOT in the ROOT store will not cause Certificate Enrollment Control to fail acceptance.

By default, the MY, CA, ROOT, and REQUEST system stores are used to store the certificates. However, you can specify other stores by assigning the following properties before calling this method:

* [MyStoreNameWStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-get_mystorenamewstr)
* [CAStoreNameWStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-get_castorenamewstr)
* [RootStoreNameWStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-get_rootstorenamewstr)
* [RequestStoreNameWStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-get_requeststorenamewstr)

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)