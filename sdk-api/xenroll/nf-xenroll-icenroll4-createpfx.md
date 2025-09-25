# ICEnroll4::createPFX

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **createPFX** method saves the accepted certificate chain and private key in a Personal Information Exchange (PFX) format string. The PFX format is also known as PKCS #12.
This method was first defined in the [ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4) interface.

## Parameters

### `strPassword` [in]

A password for the PFX-format message. This value can be empty or **NULL** to indicate that no password is used. When you have finished using the password, clear it from memory by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function. For more information about protecting the password, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `pstrPFX` [out]

A pointer to a **BSTR** that receives the base64-encoded PFX format certificate information. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see
[Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a **String** that contains the PFX format certificate information.

## Remarks

This method is disabled when the Certificate Enrollment Control is executed as a scripted control.