# IEnroll4::createFilePFXWStr

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **createFilePFXWStr** method saves the accepted certificate chain and [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) in a file in Personal Information Exchange (PFX) format. This method was first defined in the [IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4) interface.

## Parameters

### `pwszPassword` [in]

A pointer to a **null**-terminated wide character string that represents the password for the PFX-format message. This value may be empty or **NULL** to indicate that no password is used. When you have finished using the password, remove the sensitive information from memory by calling [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)). For more information about protecting the password, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `pwszPFXFileName` [in]

A pointer to a **null**-terminated wide character string that contains the name of the file that will receive the base64-encoded PFX data.

## See also

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)