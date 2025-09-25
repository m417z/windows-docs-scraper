# WritePrivateProfileStructA function

## Description

Copies data into a key in the specified section of an initialization file. As it copies the data, the function calculates a checksum and appends it to the end of the data. The
[GetPrivateProfileStruct](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprivateprofilestruct) function uses the checksum to ensure the integrity of the data.

**Note** This function is provided only for compatibility with 16-bit versions of Windows. Applications should store initialization information in the registry.

## Parameters

### `lpszSection` [in]

The name of the section to which the string will be copied. If the section does not exist, it is created. The name of the section is case independent, the string can be any combination of uppercase and lowercase letters.

### `lpszKey` [in]

The name of the key to be associated with a string. If the key does not exist in the specified section, it is created. If this parameter is **NULL**, the entire section, including all keys and entries within the section, is deleted.

### `lpStruct` [in]

The data to be copied. If this parameter is **NULL**, the key is deleted.

### `uSizeStruct` [in]

The size of the buffer pointed to by the *lpStruct* parameter, in bytes.

### `szFile` [in]

The name of the initialization file. If this parameter is **NULL**, the information is copied into the Win.ini file.

If the file was created using Unicode characters, the function writes Unicode characters to the file. Otherwise, the function writes ANSI characters.

## Return value

If the function successfully copies the string to the initialization file, the return value is nonzero.

If the function fails, or if it flushes the cached version of the most recently accessed initialization file, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A section in the initialization file must have the following form:

``` syntax
[section]
key=string
      .
      .
      .
```

If the *szFile* parameter does not contain a full path and file name for the file,
[WritePrivateProfileString](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeprivateprofilestringa) searches the Windows directory for the file. If the file does not exist, this function creates the file in the Windows directory.

If *szFile* contains a full path and file name and the file does not exist,
[WriteProfileString](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeprofilestringa) creates the file. The specified directory must already exist.

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

This mapping is likely if an application modifies system-component initialization files, such as Control.ini, System.ini, and Winfile.ini. In this case, the
function writes information to the registry, not to the initialization file; the change in the storage location has no effect on the function's behavior.

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
> The winbase.h header defines WritePrivateProfileStruct as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetPrivateProfileString](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprivateprofilestring)

[WriteProfileString](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeprofilestringa)