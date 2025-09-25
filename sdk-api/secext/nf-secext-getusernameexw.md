# GetUserNameExW function

## Description

Retrieves the name of the user or other security principal associated with the calling thread. You can specify the format of the returned name.

If the thread is impersonating a client,
**GetUserNameEx** returns the name of the client.

## Parameters

### `NameFormat` [in]

The format of the name. This parameter is a value from the
[EXTENDED_NAME_FORMAT](https://learn.microsoft.com/windows/desktop/api/secext/ne-secext-extended_name_format) enumeration type. It cannot be **NameUnknown**. If the user account is not in a domain, only **NameSamCompatible** is supported.

### `lpNameBuffer` [out]

A pointer to a buffer that receives the name in the specified format. The buffer must include space for the terminating null character.

### `nSize` [in, out]

On input, this variable specifies the size of the *lpNameBuffer* buffer, in **TCHARs**. If the function is successful, the variable receives the number of **TCHARs** copied to the buffer, not including the terminating null character.

If *lpNameBuffer* is too small, the function fails and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_MORE_DATA. This parameter receives the required buffer size, in Unicode characters (whether or not Unicode is being used), including the terminating null character.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible values include the following.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | The *lpNameBuffer* buffer is too small. The *lpnSize* parameter contains the number of bytes required to receive the name. |
| **ERROR_NO_SUCH_DOMAIN** | The domain controller is not available to perform the lookup |
| **ERROR_NONE_MAPPED** | The user name is not available in the specified format. |

## See also

[EXTENDED_NAME_FORMAT](https://learn.microsoft.com/windows/desktop/api/secext/ne-secext-extended_name_format)

[LookupAccountName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountnamea)

[System Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)

## Remarks

> [!NOTE]
> The secext.h header defines GetUserNameEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).