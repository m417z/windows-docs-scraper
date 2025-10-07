# MirrorIcon function

\[**MirrorIcon** is available through Windows XP with Service Pack 2 (SP2). It might be altered or unavailable in subsequent versions.\]

Reverses (mirrors) icons so that they are displayed correctly on a mirrored device context.

## Parameters

*phIconSmall* \[in, out, optional\]

Type: **[**HICON**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

A pointer to the icon handle that references a small version of an icon.

*phIconLarge* \[in, out, optional\]

Type: **[**HICON**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

A pointer to the icon handle that references a large version of an icon.

## Return value

Type: **[**BOOL**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if successful; otherwise, **FALSE**.

## Remarks

**MirrorIcon** is not exported by name or declared in a public header file. To use it, you must use [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) and request ordinal 414 from ComCtl32.dll to obtain a function pointer.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Comctl32.dll (version 5.81 or later) |

