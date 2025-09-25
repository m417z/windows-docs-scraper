# DRMGetUserInfo function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetUserInfo** function obtains information about a user.

## Parameters

### `hUser` [in]

The handle of the user to obtain information for.

### `puUserNameLength` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszUserName* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszUserName* buffer.

### `wszUserName` [out]

A pointer to a null-terminated Unicode string that receives the user name as a fully qualified SMTP email address. This is not enforced or used to check identities; it is only included to provide a human-readable identification. The size of this buffer is specified by the *puUserNameLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puUserNameLength* value.

### `puUserIdLength` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszUserId* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszUserId* buffer.

### `wszUserId` [out]

A pointer to a null-terminated Unicode string that receives the user's ID. The size of this buffer is specified by the *puUserIdLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puUserIdLength* value.

### `puUserIdTypeLength` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszUserIdType* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszUserIdType* buffer.

### `wszUserIdType` [out]

A pointer to a null-terminated Unicode string that receives the type of ID used to identify the user (such as Passport, Windows, or other). The size of this buffer is specified by the *puUserIdTypeLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puUserIdTypeLength* value.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

For more information about user IDs and ID types, see [DRMCreateUser](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateuser).

When you obtain the output values, you can first call this function with *wszUserName*, *wszUserId*, and *wszUserIdType* set to **NULL** to obtain the needed buffer sizes through *puUserNameLength*, *puUserIdLength*, and *puUserIdTypeLength*. It is the application's responsibility to allocate and free buffer space.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMCreateUser](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateuser)

[DRMGetUsers](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetusers)