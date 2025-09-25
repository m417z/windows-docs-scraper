# ICEnroll::acceptPKCS7

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **acceptPKCS7** method accepts and processes a PKCS #7 message that contains a certificate. The PKCS #7 is input as a parameter. This method was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

## Parameters

### `PKCS7` [in]

Represents the base64-encoded PKCS #7 that contains the certificate and the chain of certificates that identifies the issuer.

## Return value

### VB

The return value is an **HRESULT**. A value of S_OK indicates success. Upon successful completion of this function, the PKCS #7 will be accepted.

## Remarks

The PKCS #7 input as a parameter for **acceptPKCS7** contains the request certificate and the chain of certificates identifying the issuer of the certificate. Typically, but not always, the chain of certificates does not include the root. The PKCS #7 can be in base64-encoded, binary, or [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) certificate format (with or without the begin cert / end cert tags). The certificate and the associated keys generated for it are put in the MY store. A [root certificate](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) is placed in the ROOT store and the rest of the chain of certificates are placed in the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) store. If any ROOT certificates found in the PKCS #7 are accepted, Crypt32 will notify the user that a ROOT certificate is being added to his store. The user has the option of declining the ROOT certificate. This option is provided so that the user can decline to place an untrusted root in the ROOT store. Declining to place the ROOT in the ROOT store will not cause Certificate Enrollment Control to fail acceptance.

By default, the system stores MY, CA, ROOT, and REQUEST are used to store the certificates. However, you can specify other stores by assigning the following properties before calling this method:

* [MyStoreName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_mystorename)
* [CAStoreName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_castorename)
* [RootStoreName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_rootstorename)
* [RequestStoreName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_requeststorename)

When this method is called from script, the method displays a user interface that asks whether the user will allow installation of a certificate.

## See also

[CAStoreName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_castorename)

[CEnroll](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376007(v=vs.85))

[ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll)

[ICEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll2)

[ICEnroll3](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll3)

[ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4)

[MyStoreName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_mystorename)

[RequestStoreName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_requeststorename)

[RootStoreName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_rootstorename)

[acceptFilePKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptfilepkcs7)