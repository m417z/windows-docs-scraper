# SIP_DISPATCH_INFO structure

## Description

The **SIP_DISPATCH_INFO** structure contains a set of function pointers assigned by the [CryptSIPLoad](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipload) function that your application uses to perform [subject interface package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIP) operations.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `hSIP`

This member is reserved and must be set to **NULL**.

### `pfGet`

A pointer to the function that retrieves the signed data for the subject. The signature for this function pointer is described in [CryptSIPGetSignedDataMsg](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipgetsigneddatamsg).

### `pfPut`

A pointer to the function that stores the signed data for the subject. The signature for this function pointer is described in [CryptSIPPutSignedDataMsg](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipputsigneddatamsg).

### `pfCreate`

A pointer to the function that returns a [SIP_INDIRECT_DATA](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_indirect_data) structure that contains the subject data. This structure contains the hash of the target. The signature for this function pointer is described in [CryptSIPCreateIndirectData](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipcreateindirectdata).

### `pfVerify`

A pointer to the function that verifies the [SIP_INDIRECT_DATA](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_indirect_data) structure that contains the subject data. This structure contains the hash of the target. The signature for this function pointer is described in [CryptSIPVerifyIndirectData](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipverifyindirectdata).

### `pfRemove`

A pointer to the function that removes the signed data for the subject. The signature for this function pointer is described in [CryptSIPRemoveSignedDataMsg](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipremovesigneddatamsg).

## Remarks

Your application must initialize this structure to binary zeros and set **cbSize** to `sizeof(SIP_DISPATCH_INFO)` by calling the [memset](https://learn.microsoft.com/cpp/c-runtime-library/reference/memset-wmemset) function before calling the [CryptSIPLoad](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipload) function. Your application can use the function pointers in the returned **SIP_DISPATCH_INFO** structure to perform the necessary SIP operations. The function pointers can point to functions exported by third party SIPs.

## See also

[CryptSIPCreateIndirectData](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipcreateindirectdata)

[CryptSIPGetSignedDataMsg](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipgetsigneddatamsg)

[CryptSIPPutSignedDataMsg](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipputsigneddatamsg)

[CryptSIPRemoveSignedDataMsg](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipremovesigneddatamsg)

[CryptSIPVerifyIndirectData](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipverifyindirectdata)