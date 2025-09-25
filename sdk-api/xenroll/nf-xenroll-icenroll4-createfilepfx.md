# ICEnroll4::createFilePFX

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **createFilePFX** method saves the accepted certificate chain and [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) in a file in Personal Information Exchange (PFX) format. This method was first defined in the [ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4) interface.

## Parameters

### `strPassword` [in]

A password for the PFX; this value can be empty (or **NULL**) to indicate that no password is used. When you have finished using the password, clear it from memory by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function. For more information about handling passwords, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `strPFXFileName` [in]

The name of the file that will receive the base64-encoded PFX data.

## Return value

### VB

If the method succeeds, the method returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see
[Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

When this method is called from script, the method displays a user interface that asks whether the user will allow a write operation to the file system.