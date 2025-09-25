# GetProfileSectionA function

## Description

Retrieves all the keys and values for the specified section of the Win.ini file.

**Note** This function is provided only for compatibility with 16-bit Windows-based applications. Applications should store initialization information in the registry.

## Parameters

### `lpAppName` [in]

The name of the section in the Win.ini file.

### `lpReturnedString` [out]

A pointer to a buffer that receives the keys and values associated with the named section. The buffer is filled with one or more null-terminated strings; the last string is followed by a second null character.

### `nSize` [in]

The size of the buffer pointed to by the *lpReturnedString* parameter, in characters.

The maximum profile section size is 32,767 characters.

## Return value

The return value specifies the number of characters copied to the specified buffer, not including the terminating null character. If the buffer is not large enough to contain all the keys and values associated with the named section, the return value is equal to the size specified by *nSize* minus two.

## Remarks

The format of the returned keys and values is one or more null-terminated strings, followed by a final null character. Each string has the following form: *key*=*string*

The
**GetProfileSection** function is not case-sensitive; the strings can be a combination of uppercase and lowercase letters.

This operation is atomic; no updates to the Win.ini file are allowed while the keys and values for the section are being copied to the buffer.

**Windows Server 2003 and Windows XP/2000:** Calls to profile functions may be mapped to the registry instead of to the initialization files. This mapping occurs when the initialization file and section are specified in the registry under the following key: **HKEY_LOCAL_MACHINE\Software\Microsoft\Windows NT\CurrentVersion\IniFileMapping**.

When the operation has been mapped, the
**GetProfileSection** function retrieves information from the registry, not from the initialization file; the change in the storage location has no effect on the function's behavior.

The profile functions use the following steps to locate initialization information:

1. Look in the registry for the name of the initialization file under the **IniFileMapping** key.
2. Look for the section name specified by *lpAppName*. This will be a named value under the key that has the name of the initialization file, or a subkey with this name, or the name will not exist as either a value or subkey.
3. If the section name specified by *lpAppName* is a named value, then that value specifies where in the registry you will find the keys for the section.
4. If the section name specified by *lpAppName* is a subkey, then named values under that subkey specify where in the registry you will find the keys for the section. If the key you are looking for does not exist as a named value, then there will be an unnamed value (shown as **<No Name>**) that specifies the default location in the registry where you will find the key.
5. If the section name specified by *lpAppName* does not exist as a named value or as a subkey, then there will be an unnamed value (shown as **<No Name>**) that specifies the default location in the registry where you will find the keys for the section.
6. If there is no subkey or entry for the section name, then look for the actual initialization file on the disk and read its contents.

When looking at values in the registry that specify other registry locations, there are several prefixes that change the behavior of the .ini file mapping:

* ! - this character forces all writes to go both to the registry and to the .ini file on disk.
* # - this character causes the registry value to be set to the value in the Windows 3.1 .ini file when a new user logs in for the first time after setup.
* @ - this character prevents any reads from going to the .ini file on disk if the requested data is not found in the registry.
* USR: - this prefix stands for **HKEY_CURRENT_USER**, and the text after the prefix is relative to that key.
* SYS: - this prefix stands for **HKEY_LOCAL_MACHINE\SOFTWARE**, and the text after the prefix is relative to that key.

> [!NOTE]
> The winbase.h header defines GetProfileSection as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetPrivateProfileSection](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprivateprofilesection)

[WriteProfileSection](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeprofilesectiona)