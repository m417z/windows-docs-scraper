# IEnroll4::createPFXWStr

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **createPFXWStr** method saves the accepted certificate chain and private key in a Personal Information Exchange (PFX) format string. The PFX format is also known as PKCS #12. This method was first defined in the [IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4) interface.

## Parameters

### `pwszPassword` [in]

A pointer to a null-terminated Unicode string that represents the password for the PFX-format message. This value may be empty or **NULL** to indicate that no password is used. When you have finished using the password, remove the sensitive information from memory by calling [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)). For more information about protecting the password, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `pblobPFX` [out]

A pointer to the [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that receives the base64-encoded PFX format certificate information.

When you have finished using this memory, free it by passing the **pbData** member of this structure to the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

 If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)