# EnumLayoutOrTipForSetup function

Enumerates the installed keyboard layouts and text services of the setup UI or OOBE.

## Parameters

*langid* \[in\]

The language id of the item to be enumerated.

*pLayoutOrTip* \[out\]

Pointer to the buffer that receives the array of LAYOUTORTIP structures. This can be **NULL** to get the number of items.

*uBufLength* \[in\]

The length of the buffer pointed to by *pLayoutOrTip*. This is ignored if *pLayoutOrTip* is **NULL**.

*dwFlags* \[in\]

Not used. This must be zero.

## Return value

If *pLayoutOrTip* is **NULL**, the number of keyboard items that are registered in System; otherwise, the number of keyboard items that are copied into *pLayoutOrTip*.

## Remarks

There is no import library available that defines this function, so it is necessary to obtain a pointer to this function using [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress).

> [!Note]
> Using [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) incorrectly can compromise the security of your application by loading the wrong DLL. Refer to [Dynamic-Link Library Search Order](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-search-order) for information on how to correctly load DLLs with different versions of Microsoft Windows.

The definition of LAYOUTORTIP is:

``` syntax
typedef struct tagLAYOUTORTIP {
    DWORD dwFlags;
#define LOT_DEFAULT    0x0001 // If this is on, this is a default item.
#define LOT_DISABLED   0x0002 // if this is on, this is not enabled.
    WCHAR szId[MAX_PATH]; // Id of the keyboard item in the string format.
    WCHAR szName[MAX_PATH]; // The description of the keyboard item.
} LAYOUTORTIP;
```

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Input.dll |

