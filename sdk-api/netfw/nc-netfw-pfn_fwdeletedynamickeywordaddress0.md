## Description

Function pointer type of the entry point in the service that you call to delete the dynamic keyword address with the specified ID.

> [!NOTE]
> A pointer type for this free function is published via `NetFw.h`, but a static-link library isn't published. Use the [LoadLibraryExW](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw)/[GetProcAddress](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) pattern for calling this function.

When you call [GetProcAddress](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress), pass a handle to the *firewallapi.dll* module, and pass *FWDeleteDynamicKeywordAddress0* as the *lpProcName* argument.

For more info, and code examples, see [Firewall dynamic keywords](https://learn.microsoft.com/windows/win32/ics/firewall-dynamic-keywords).

## Parameters

### `dynamicKeywordAddressId`

Type: **[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**

The id of the dynamic keyword address object to delete.

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If the function succeeds (the object was successfully deleted, or no object with the specified ID exists), then it returns **ERROR_SUCCESS**. Otherwise, it returns one of the following values.

|Return value|Description|
|-|-|
|ERROR_ACCESS_DENIED|The caller doesn't have proper permissions to operate on the object with the specified ID. This likely means that the object is managed by MDM (it has origin type **FW_DYNAMIC_KEYWORD_ORIGIN_MDM**.|

## Remarks

> [!NOTE]
> This function returns **ERROR_SUCCESS** even if the object with the specified ID doesn't exist.

## See also

* [Firewall dynamic keywords](https://learn.microsoft.com/windows/win32/ics/firewall-dynamic-keywords)