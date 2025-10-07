# GetPrivateProfileString function

## Description

Retrieves a string from the specified section in an initialization file.

**Note** This function is provided only for compatibility with 16-bit Windows-based applications. Applications should store initialization information in the registry.

## Parameters

### `lpAppName` [in]

The name of the section containing the key name. If this parameter is **NULL**, the
**GetPrivateProfileString** function copies all section names in the file to the supplied buffer.

### `lpKeyName` [in]

The name of the key whose associated string is to be retrieved. If this parameter is **NULL**, all key names in the section specified by the *lpAppName* parameter are copied to the buffer specified by the *lpReturnedString* parameter.

### `lpDefault` [in]

A default string. If the *lpKeyName* key cannot be found in the initialization file,
**GetPrivateProfileString** copies the default string to the *lpReturnedString* buffer.

If this parameter is **NULL**, the default is an empty string, "".

Avoid specifying a default string with trailing blank characters. The function inserts a **null** character in the *lpReturnedString* buffer to strip any trailing blanks.

### `lpReturnedString` [out]

A pointer to the buffer that receives the retrieved string.

### `nSize` [in]

The size of the buffer pointed to by the *lpReturnedString* parameter, in characters.

### `lpFileName` [in]

The name of the initialization file. If this parameter does not contain a full path to the file, the system searches for the file in the Windows directory.

## Return value

The return value is the number of characters copied to the buffer, not including the terminating **null** character.

If neither *lpAppName* nor *lpKeyName* is **NULL** and the supplied destination buffer is too small to hold the requested string, the string is truncated and followed by a **null** character, and the return value is equal to *nSize* minus one.

If either *lpAppName* or *lpKeyName* is **NULL** and the supplied destination buffer is too small to hold all the strings, the last string is truncated and followed by two **null** characters. In this case, the return value is equal to *nSize* minus two.

In the event the initialization file specified by *lpFileName* is not found, or contains invalid values, calling **GetLastError** will return '0x2' (File Not Found). To retrieve extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**GetPrivateProfileString** function searches the specified initialization file for a key that matches the name specified by the *lpKeyName* parameter under the section heading specified by the *lpAppName* parameter. If it finds the key, the function copies the corresponding string to the buffer. If the key does not exist, the function copies the default character string specified by the *lpDefault* parameter. A section in the initialization file must have the following form:

``` syntax
[section]
key=string
      .
      .
      .
```

If *lpAppName* is **NULL**,
**GetPrivateProfileString** copies all section names in the specified file to the supplied buffer. If *lpKeyName* is **NULL**, the function copies all key names in the specified section to the supplied buffer. An application can use this method to enumerate all of the sections and keys in a file. In either case, each string is followed by a **null** character and the final string is followed by a second **null** character. If the supplied destination buffer is too small to hold all the strings, the last string is truncated and followed by two **null** characters.

If the string associated with *lpKeyName* is enclosed in single or double quotation marks, the marks are discarded when the
**GetPrivateProfileString** function retrieves the string.

The
**GetPrivateProfileString** function is not case-sensitive; the strings can be a combination of uppercase and lowercase letters.

To retrieve a string from the Win.ini file, use the
[GetProfileString](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprofilestringa) function.

The system maps most .ini file references to the registry, using the mapping defined under the following registry key:**HKEY_LOCAL_MACHINE**\**SOFTWARE**\**Microsoft**\**Windows NT**\**CurrentVersion**\**IniFileMapping**

This mapping is likely if an application modifies system-component initialization files, such as Control.ini, System.ini, and Winfile.ini. In these cases, the
function retrieves information from the registry, not from the initialization file; the change in the storage location has no effect on the function's behavior.

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

## Example

The following example demonstrates the use of **GetPrivateProfileString**.

```cpp
// Gets a profile string called "Preferred line" and converts it to an int.
GetPrivateProfileString (
      "Preference",
      "Preferred Line",
      gszNULL,
      szBuffer,
      MAXBUFSIZE,
      gszINIfilename
);

// if szBuffer is not empty.
if ( lstrcmp ( gszNULL, szBuffer ) )
{
      dwPreferredPLID = (DWORD) atoi( szBuffer );	
}
else	
{
      dwPreferredPLID = (DWORD) -1;
}
```

## See also

[GetProfileString](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprofilestringa)

[WritePrivateProfileString](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeprivateprofilestringa)