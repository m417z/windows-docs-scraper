# SHCopyKeyA function

## Description

Recursively copies the subkeys and values of the source subkey to the destination key. **SHCopyKey** does not copy the security attributes of the keys.

## Parameters

### `hkeySrc` [in]

Type: **HKEY**

A handle to the source key (for example, **HKEY_CURRENT_USER**).

### `pszSrcSubKey` [in, optional]

Type: **LPCTSTR**

The subkey whose subkeys and values are to be copied.

### `hkeyDest` [in]

Type: **HKEY**

The destination key.

### `fReserved`

Type: **DWORD**

Reserved. Must be 0.

## Return value

Type: **LSTATUS**

Returns ERROR_SUCCESS if successful, or one of the nonzero error codes defined in Winerror.h otherwise. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) with the FORMAT_MESSAGE_FROM_SYSTEM flag to retrieve a generic description of the error.

## Remarks

**Important** This function does not duplicate the security attributes of the keys and values that it copies. Rather, all security attributes in the destination key are the default attributes.

> [!NOTE]
> The shlwapi.h header defines SHCopyKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).