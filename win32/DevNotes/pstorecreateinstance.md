# PStoreCreateInstance function

\[Protected Storage (Pstore) is available for use in Windows Server 2003 and Windows XP. It is only available for read-only operations in Windows Server 2008 and Windows Vista, but may be unavailable in subsequent versions. Pstore uses an older implementation of data protection. Developers are strongly encouraged to take advantage of the stronger data protection provided by the [**CryptProtectData**](https://learn.microsoft.com/windows/win32/api/dpapi/nf-dpapi-cryptprotectdata) and [**CryptUnprotectData**](https://learn.microsoft.com/windows/win32/api/dpapi/nf-dpapi-cryptunprotectdata) functions.\]

\[This function may be altered or unavailable in future versions of Windows. Use the **CryptProtectData** and **CryptUnprotectData** functions instead of this function.\]

Retrieves an interface pointer to a storage provider.

## Parameters

*ppProvider* \[out\]

A pointer to the retrieved interface pointer for the storage provider. When you finish using the interface, decrement its reference count by calling its [**IUnknown::Release**](https://learn.microsoft.com/windows/win32/api/unknwn/nf-unknwn-iunknown-release) method. This parameter cannot be **NULL**.

*pProviderID* \[in\]

A pointer to the **GUID** that identifies the storage provider. If this parameter is **NULL**, then the base storage provider is used.

*pReserved* \[in\]

Reserved; must be **NULL**.

*dwFlags* \[in\]

Reserved; must be zero.

## Return value

The return value is an **HRESULT**. A value of **S\_OK** indicates the function was successful.

## Remarks

This function has no associated import library; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | Pstore.h |
| DLL<br> | Pstorec.dll |

## See also

[**CryptProtectData**](https://learn.microsoft.com/windows/win32/api/dpapi/nf-dpapi-cryptprotectdata)

[**CryptUnprotectData**](https://learn.microsoft.com/windows/win32/api/dpapi/nf-dpapi-cryptunprotectdata)

