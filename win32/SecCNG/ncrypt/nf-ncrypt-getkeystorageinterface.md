# GetKeyStorageInterface function

Retrieves the key storage interface for the specified provider.

## Parameters

`pszProviderName`

The provider name.

`ppFunctionTable`

Used to retrieve the key storage interface.

`dwFlags`

Flags.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

**GetKeyStorageInterface** isn't associated with a header file. You can call it by first using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryw) function (to load `Ncrypt.dll`), and then by calling the [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) function to retrieve the address of **GetKeyStorageInterface**.

## Requirements

| Requirement | Value |
| ---- | ---- |
| **Target Platform** | Windows |
| **Header** | N/A |
| **Library** | `Ncrypt.lib` |
| **DLL** | `Ncrypt.dll` |