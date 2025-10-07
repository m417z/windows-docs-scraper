# SaveSystemAcctInputSettings function

Applies the user keyboard layout and text service setting to the system accounts hive.

## Parameters

*hwndParent* \[in\]

The parent window for the warning dialog box. The warning dialog box is not always shown and appears appropriately. If this parameter is **NULL**, the warning dialog box will not be shown.

*hSourceRegKey* \[in\]

The root registry key of the user setting to be copied.

## Return value

| Return code | Description |
|--------------------------------------------------------------------------------------|-------------------------------------------|
| **TRUE** | The function was successful.<br> |
| **FALSE** | An unspecified error occurred.<br> |

## Remarks

The system account hive is HKEY\_USERS\\.DEFAULT, HKEY\_USERS\\S-1-5-19, and HKEY\_USERS\\S-1-5-20.

## Examples

There is no import library available that defines this function, so it is necessary to obtain a pointer to this function using [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress). The following example demonstrates how to obtain a pointer to this function.

> [!Note]
> Using [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) incorrectly can compromise the security of your application by loading the wrong DLL. Refer to [Dynamic-Link Library Search Order](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-search-order) for information on how to correctly load DLLs with different versions of Microsoft Windows.

```C++
typedef HRESULT (WINAPI *PTF_ SAVESYSTEMACCTINPUTSETTINGS)(HWND hwndParent, HKEY hSourceRegKey);

HMODULE hInputDLL = LoadLibrary(TEXT("input.dll"));
BOOL bRet = FALSE;

if(hInputDLL == NULL)
{
    // Error loading module; fail as securely as possible.
}
else
{
    PTF_ SAVESYSTEMACCTINPUTSETTINGS pfnSaveSystemAcctInputSettings;

    pfnSaveSystemAcctInputSettings = (PTF_ SAVESYSTEMACCTINPUTSETTINGS)GetProcAddress(hInputDLL, "SaveSystemAcctInputSettings ");

    if(pfnSaveSystemAcctInputSettings)
    {
        bRet = (*pfnSaveSystemAcctInputSettings)( hwndParent, hSourceRegKey);
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

