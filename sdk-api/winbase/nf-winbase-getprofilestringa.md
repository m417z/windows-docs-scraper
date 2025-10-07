# GetProfileStringA function

## Description

Retrieves the string associated with a key in the specified section of the Win.ini file.

**Note** This function is provided only for compatibility with 16-bit Windows-based applications, therefore this function should not be called from server code. Applications should store initialization information in the registry.

## Parameters

### `lpAppName` [in]

The name of the section containing the key. If this parameter is **NULL**, the function copies all section names in the file to the supplied buffer.

### `lpKeyName` [in]

The name of the key whose associated string is to be retrieved. If this parameter is **NULL**, the function copies all keys in the given section to the supplied buffer. Each string is followed by a **null** character, and the final string is followed by a second **null** character.

### `lpDefault` [in]

A default string. If the *lpKeyName* key cannot be found in the initialization file,
**GetProfileString** copies the default string to the *lpReturnedString* buffer. If this parameter is **NULL**, the default is an empty string, "".

Avoid specifying a default string with trailing blank characters. The function inserts a **null** character in the *lpReturnedString* buffer to strip any trailing blanks.

### `lpReturnedString` [out]

A pointer to a buffer that receives the character string.

### `nSize` [in]

The size of the buffer pointed to by the *lpReturnedString* parameter, in characters.

## Return value

The return value is the number of characters copied to the buffer, not including the **null**-terminating character.

If neither *lpAppName* nor *lpKeyName* is **NULL** and the supplied destination buffer is too small to hold the requested string, the string is truncated and followed by a **null** character, and the return value is equal to *nSize* minus one.

If either *lpAppName* or *lpKeyName* is **NULL** and the supplied destination buffer is too small to hold all the strings, the last string is truncated and followed by two **null** characters. In this case, the return value is equal to *nSize* minus two.

## Remarks

If the string associated with the *lpKeyName* parameter is enclosed in single or double quotation marks, the marks are discarded when the
**GetProfileString** function returns the string.

The
**GetProfileString** function is not case-sensitive; the strings can contain a combination of uppercase and lowercase letters.

A section in the Win.ini file must have the following form:

``` syntax
[section]
key=string
      .
      .
      .
```

An application can use the
[GetPrivateProfileString](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprivateprofilestring) function to retrieve a string from a specified initialization file.

The *lpDefault* parameter must point to a valid string, even if the string is empty (that is, even if its first character is a **null** character).

**Windows Server 2003 and Windows XP/2000:** Calls to profile functions may be mapped to the registry instead of to the initialization files. This mapping occurs when the initialization file and section are specified in the registry under the following keys:

**HKEY_LOCAL_MACHINE**\**Software**\**Microsoft**\**Windows NT**\**CurrentVersion**\**IniFileMapping**

When the operation has been mapped, the
**GetProfileString** function retrieves information from the registry, not from the initialization file; the change in the storage location has no effect on the function's behavior.

The profile functions use the following steps to locate initialization information:

1. Look in the registry for the name of the initialization file under the **IniFileMapping** key.
2. Look for the section name specified by *lpAppName*. This will be a named value under the key that has the name of the initialization file, or a subkey with this name, or the name will not exist as either a value or subkey.
3. If the section name specified by *lpAppName* is a named value, then that value specifies where in the registry you will find the keys for the section.
4. If the section name specified by *lpAppName* is a subkey, then named values under that subkey specify where in the registry you will find the keys for the section. If the key you are looking for does not exist as a named value, then there will be an unnamed value (shown as **\<No Name>**) that specifies the default location in the registry where you will find the key.
5. If the section name specified by *lpAppName* does not exist as a named value or as a subkey, then there will be an unnamed value (shown as **\<No Name>**) that specifies the default location in the registry where you will find the keys for the section.
6. If there is no subkey or entry for the section name, then look for the actual initialization file on the disk and read its contents.

When looking at values in the registry that specify other registry locations, there are several prefixes that change the behavior of the .ini file mapping:

* ! - this character forces all writes to go both to the registry and to the .ini file on disk.
* # - this character causes the registry value to be set to the value in the Windows 3.1 .ini file when a new user logs in for the first time after setup.
* @ - this character prevents any reads from going to the .ini file on disk if the requested data is not found in the registry.
* USR: - this prefix stands for **HKEY_CURRENT_USER**, and the text after the prefix is relative to that key.
* SYS: - this prefix stands for **HKEY_LOCAL_MACHINE\SOFTWARE**, and the text after the prefix is relative to that key.

> [!NOTE]
> The winbase.h header defines GetProfileString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetPrivateProfileString](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprivateprofilestring)

[WriteProfileString](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeprofilestringa)