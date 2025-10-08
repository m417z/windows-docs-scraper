# SetDefaultLayoutOrTipUserReg function

Sets the specified keyboard layout or a text service as a default input item of the user registry.

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

A bitfield that specifies the following flags:

> [!Note]
> The following identifiers are not defined in a public header file. You must either use the hexadecimal value or \#define the identifiers. For example, to use SDLOT\_NOAPPLYTOCURRENTSESSION you must include \#define SDLOT\_NOAPPLYTOCURRENTSESSION 0x00000001 in your code.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **SDLOT\_NOAPPLYTOCURRENTSESSION**<br>0x00000001 | Stores the setting in the registry but does not update the runtime keyboard setting of the current session. If the alternative registry path is set in **SetDefaultLayoutOrTipUserReg**, this flag should be set.<br> |
| **SDLOT\_APPLYTOCURRENTTHREAD**<br>0x00000002 | Applies the setting immediately on the current thread.<br> |

## Return value

| Return code | Description |
|--------------------------------------------------------------------------------------|-------------------------------------------|
| **TRUE** | The function was successful.<br> |
| **FALSE** | An unspecified error occurred.<br> |

## Remarks

The string format of the layout list is:

\<LangID 1\>:\<KLID 1\>;\[...\<LangID N\>:\<KLID N\>

The string format of the text service profile list is:

\<LangID 1\>:{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx};

The following is an example of a value for the *psz* parameter:

```
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
    WINAPI *PTF_ SETDEFAULTLAYOUTORTIPUSERREG)( LPCWSTR pszUserReg,
    LPCWSTR pszSystemReg,
    LPCWSTR pszSoftwareReg,
    LPCWSTR psz);

HMODULE hInputDLL = LoadLibrary(TEXT("input.dll"));
BOOL bRet = FALSE;

if(hInputDLL == NULL)
{
    //Error loading module -- fail as securely as possible
}
else
{
    PTF_ SETDEFAULTLAYOUTORTIPUSERREG pfnSetDefaultLayoutOrTipUserReg;

    pfnSetDefaultLayoutOrTipUserReg = (PTF_ SETDEFAULTLAYOUTORTIPUSERREG)GetProcAddress(hInputDLL, "SetDefaultLayoutOrTipUserReg");

    if(pfnSetDefaultLayoutOrTipUserReg)
    {
        bRet = (*pfnSetDefaultLayoutOrTipUserReg)( pszUserReg, pszSystemReg, pszSoftwareReg, psz);
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

