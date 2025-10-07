# WriteProfileSectionA function

## Description

Replaces the contents of the specified section in the Win.ini file with specified keys and values. If Win.ini uses Unicode characters, the function writes Unicode characters to the file. Otherwise, the function writes ANSI characters.

**Note** This function is provided only for compatibility with 16-bit versions of Windows. Applications should store initialization information in the registry.

## Parameters

### `lpAppName` [in]

The name of the section. This section name is typically the name of the calling application.

### `lpString` [in]

The new key names and associated values that are to be written to the named section. This string is limited to 65,535 bytes.

If the file exists and was created using Unicode characters, the function writes Unicode characters to the file. Otherwise, the function creates a file using ANSI characters.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Keys and values in the *lpString* buffer consist of one or more **null**-terminated strings, followed by a final **null** character. Each string has the following form: *key*=*string*.

The
**WriteProfileSection** function is not case-sensitive; the strings can be a combination of uppercase and lowercase letters.

**WriteProfileSection** deletes the existing keys and values for the named section and inserts the key names and values in the buffer pointed to by *lpString*. The function does not attempt to correlate old and new key names; if the new names appear in a different order from the old names, any comments associated with preexisting keys and values in the initialization file will probably be associated with incorrect keys and values.

This operation is atomic; no other operations that read from or write to the initialization file are allowed while the information is being written.

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
**WriteProfileSection** function writes information to the registry, not to the initialization file; the change in the storage location has no effect on the function's behavior.

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
> The winbase.h header defines WriteProfileSection as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetProfileSection](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprofilesectiona)

[WritePrivateProfileSection](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeprivateprofilesectiona)