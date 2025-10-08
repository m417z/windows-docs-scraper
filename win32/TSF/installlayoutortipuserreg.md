# InstallLayoutOrTipUserReg function

Enables the specified keyboard layouts or text services for the specified user.

## Parameters

*pszUserReg* \[in, optional\]

The registry path of the user. If this parameter is **NULL**, HKEY\_CURRENT\_USER is used.

*pszSystemReg* \[in, optional\]

The registry path of the system. If this parameter is **NULL**, HKEY\_LOCAL\_MACHINE\\System is used.

*pszSoftwareReg* \[in, optional\]

The registry path of the software. If this parameter is **NULL**, HKEY\_LOCAL\_MACHINE\\Software is used.

*psz* \[in\]

A string that represents the keyboard layout list or text services profile list.

*dwFlags* \[in\]

A bitfield that specifies the following flags.

> [!Note]
> The following identifiers are not defined in a public header file. You must either use the hexadecimal value or \#define the identifiers. For example, to use **ILOT\_UNINSTALL** you must include `#define ILOT_UNINSTALL 0x00000001` in your code.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------|
| **ILOT\_UNINSTALL**<br>0x00000001 | Same as **ILOT\_DISABLED**.<br> |
| **ILOT\_DEFPROFILE**<br>0x00000002 | Sets the specified layout or tip as a default item.<br> |
| **ILOT\_NOAPPLYTOCURRENTSESSION**<br>0x00000020 | The setting is saved but is not applied to the current session.<br> |
| **ILOT\_CLEANINSTALL**<br>0x00000040 | Disables all of the current keyboard layouts and text services.<br> |
| **ILOT\_DISABLED**<br>0x00000080 | Disables the specified keyboard layout and text service.<br> |

## Return value

| Return code | Description |
|-------------------------------------------------------------------------------------|-------------------------------------------|
| **TRUE** | The function was successful.<br> |
| **FASE** | An unspecified error occurred.<br> |

## Remarks

The string format of the layout list is:

\<LangID 1\>:\<KLID 1\>;\[...\<LangID N\>:\<KLID N\>

The string format of the text service profile list is:

\<LangID 1\>:{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx};

The following is an example of a value for the *psz* parameter:

```C++
"0x0407:0x00000407"
"0x0407:0x00000407;0x040C:0x0000040C"
"0x0407:0x00000407;0x0412:{A028AE76-01B1-46C2-99C4-ACD9858AE02F}{B5FE1F02-D5F2-4445-9C03-C568F23C99A1};0x040C:0x0000040C"
```

## Examples

There is no import library available that defines this function, so it is necessary to obtain a pointer to this function using [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress). The following example demonstrates how to obtain a pointer to this function.

> [!Note]
> Using [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) incorrectly can compromise the security of your application by loading the wrong DLL. Refer to [Dynamic-Link Library Search Order](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-search-order) for information on how to correctly load DLLs with different versions of Microsoft Windows.

```C++
typedef HRESULT (
  WINAPI *PTF_ INSTALLLAYOUTORTIPUSERREG)(LPCWSTR pszUserReg,
  LPCWSTR pszSystemReg,
  LPCWSTR pszSoftwareReg,
  LPCWSTR psz,
  DWORD dwFlasg);

HMODULE hInputDLL = LoadLibrary(TEXT("input.dll"));
BOOL bRet = FALSE;

if(hInputDLL == NULL)
{
    // Error loading module; fail as securely as possible.
}
else
{
    PTF_ INSTALLLAYOUTORTIPUSERREG pfnInputLayoutOrTipUserReg;

    pfnInputLayoutOrTipUserReg = (PTF_ INSTALLLAYOUTORTIPUSERREG)GetProcAddress(hInputDLL, "InputLayoutOrTipUserReg");

    if(pfnInputLayoutOrTipUserReg)
    {
        bRet = (*pfnInputLayoutOrTipUserReg)(pszUserReg, pszSystemReg, pszSoftwareReg, psz, dwFlags);
    }

    FreeLibrary(hInputDLL);
}

```

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Input.dll |

