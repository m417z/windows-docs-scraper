# IEnroll2::get_HashAlgID

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **HashAlgID** property sets or retrieves the [hash algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) used when signing a PKCS #10 [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

This property was first introduced in the [IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll2) interface.

This property is read/write.

## Parameters

## Remarks

The values for this property are [hash algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) IDs, such as those returned by the
[EnumAlgs](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll2-enumalgs) method. If both the **HashAlgID** and
[HashAlgorithmWStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-get_hashalgorithmwstr) properties are set, whichever has been updated most recently determines the hash algorithm used to sign the PKCS #10 request.

## See also

[ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id)

[IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll2)

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)