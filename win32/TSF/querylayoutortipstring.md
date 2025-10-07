# QueryLayoutOrTipString function

Queries the specified string which represents the format of a keyboard layout list or text services profile list.

## Parameters

*psz* \[in\]

A string that represents a keyboard layout list or a text services profile list.

*dwFlags* \[in\]

This must be 0.

## Return value

This function can return one of these values.

| Return code | Description |
|----------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------|
| **S\_OK** | All layouts or profiles defined in *psz* are valid.<br> |
| **E\_INVALIDARG** | One or more of the layouts or profiles defined in *psz* are invalid.<br> |

## Remarks

There is no import library available that defines this function, so it is necessary to obtain a pointer to this function using [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress).

> [!Note]
> Using [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) incorrectly can compromise the security of your application by loading the wrong DLL. Refer to [Dynamic-Link Library Search Order](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-search-order) for information on how to correctly load DLLs with different versions of Microsoft Windows.

The string format of the layout list is:

\:\;\[...\:\

The string format of the text service profile list is:

\:{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx};

The following is an example of a value for the *psz* parameter:

``` syntax
"0x0407:0x00000407"
"0x0407:0x00000407;0x040C:0x0000040C"
"0x0407:0x00000407;0x0412:{A028AE76-01B1-46C2-99C4-ACD9858AE02F}{B5FE1F02-D5F2-4445-9C03-C568F23C99A1};0x040C:0x0000040C"
```

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Input.dll |

