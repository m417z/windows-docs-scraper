# WriteProfileStringA function

## Description

Copies a string into the specified section of the Win.ini file. If Win.ini uses Unicode characters, the function writes Unicode characters to the file. Otherwise, the function writes ANSI characters.

**Note** This function is provided only for compatibility with 16-bit versions of Windows. Applications should store initialization information in the registry.

## Parameters

### `lpAppName` [in]

The section to which the string is to be copied. If the section does not exist, it is created. The name of the section is not case-sensitive; the string can be any combination of uppercase and lowercase letters.

### `lpKeyName` [in]

The key to be associated with the string. If the key does not exist in the specified section, it is created. If this parameter is **NULL**, the entire section, including all entries in the section, is deleted.

### `lpString` [in]

A **null**-terminated string to be written to the file. If this parameter is **NULL**, the key pointed to by the *lpKeyName* parameter is deleted.

## Return value

If the function successfully copies the string to the Win.ini file, the return value is nonzero.

If the function fails, or if it flushes the cached version of Win.ini, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A section in the Win.ini file must have the following form: *key*=*string*.

The system keeps a cached version of the most recent registry file mapping to improve performance. If all parameters are **NULL**, the function flushes the cache. While the system is editing the cached version of the file, processes that edit the file itself will use the original file until the cache has been cleared.

The system maps most .ini file references to the registry, using the mapping defined under the following registry key:

```
HKEY_LOCAL_MACHINE
   SOFTWARE
      Microsoft
         Windows NT
            CurrentVersion
               IniFileMapping
```

When the operation has been mapped, the
**WriteProfileString** function writes information to the registry, not to the initialization file; the change in the storage location has no effect on the function's behavior.

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
> The winbase.h header defines WriteProfileString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetProfileString](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprofilestringa)

[WritePrivateProfileString](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeprivateprofilestringa)