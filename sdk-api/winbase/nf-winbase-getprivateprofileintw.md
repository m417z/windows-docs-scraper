# GetPrivateProfileIntW function

## Description

Retrieves an integer associated with a key in the specified section of an initialization file.

**Note** This function is provided only for compatibility with 16-bit Windows-based applications. Applications should store initialization information in the registry.

## Parameters

### `lpAppName` [in]

The name of the section in the initialization file.

### `lpKeyName` [in]

The name of the key whose value is to be retrieved. This value is in the form of a string; the
**GetPrivateProfileInt** function converts the string into an integer and returns the integer.

### `nDefault` [in]

The default value to return if the key name cannot be found in the initialization file.

### `lpFileName` [in]

The name of the initialization file. If this parameter does not contain a full path to the file, the system searches for the file in the Windows directory.

## Return value

The return value is the integer equivalent of the string following the specified key name in the specified initialization file. If the key is not found, the return value is the specified default value.

## Remarks

The function searches the file for a key that matches the name specified by the *lpKeyName* parameter under the section name specified by the *lpAppName* parameter. A section in the initialization file must have the following form:

``` syntax
[section]
key=value
      .
      .
      .
```

The
**GetPrivateProfileInt** function is not case-sensitive; the strings in *lpAppName* and *lpKeyName* can be a combination of uppercase and lowercase letters.

An application can use the
[GetProfileInt](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprofileinta) function to retrieve an integer value from the Win.ini file.

The system maps most .ini file references to the registry, using the mapping defined under the following registry key:**HKEY_LOCAL_MACHINE**\**SOFTWARE**\**Microsoft**\**Windows NT**\**CurrentVersion**\**IniFileMapping**

This mapping is likely if an application modifies system-component initialization files, such as Control.ini, System.ini, and Winfile.ini. In these cases, the
function retrieves information from the registry, not from the initialization file; the change in the storage location has no effect on the function's behavior.

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
> The winbase.h header defines GetPrivateProfileInt as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetProfileInt](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprofileinta)

[WritePrivateProfileString](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeprivateprofilestringa)