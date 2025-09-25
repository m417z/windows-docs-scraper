# CreateMD5SSOHash function

## Description

The **CreateMD5SSOHash** function obtains the default Microsoft Passport password for a specified account or realm, creates an MD5 hash from it using a specified wide-character challenge string, and returns the result as a string of hexadecimal digit bytes.

## Parameters

### `pszChallengeInfo` [in]

Pointer to the wide-character challenge string to use for the MD5 hash.

### `pwszRealm` [in]

Pointer to a string that names a realm for which to obtain the password. This parameter is ignored unless *pwszTarget* is **NULL**. If both *pwszTarget* and *pwszRealm* are **NULL**, the default realm is used.

### `pwszTarget` [in]

Pointer to a string that names an account for which to obtain the password. If *pwszTarget* is **NULL**, the realm indicated by *pwszRealm* is used.

### `pbHexHash` [out]

Pointer to an output buffer into which the MD5 hash is returned in hex string format. This buffer must be at least 33 bytes long.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise.

## Remarks

Once the **CreateMD5SSOHash** function successfully obtains the Microsoft Passport password for the specified account or realm, it converts both the challenge string and the password from wide characters to multi-byte (generally 8-bit) characters, concatenates them, and uses the RSA library to generate an MD5 hash from the resulting key. It then converts the hash into a **null**-terminated string of 8-bit hexadecimal digits (using lowercase letters) which it places in the buffer pointed to by the *pbHexHash* parameter.

The output buffer pointed to by *pbHexHash* must therefore be long enough to accept two bytes for each of the 16 bytes of the hash, plus a terminating **null** character, for a total of 33 bytes.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Handling Authentication](https://learn.microsoft.com/windows/desktop/WinInet/handling-authentication)

 [WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)