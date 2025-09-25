# GetEncSChannel function

## Description

[The GetEncSChannel function is no longer available for use as of Windows Server 2003 and Windows XP.]

**Note** This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Instrsa5.dll.

## Parameters

### `pData` [out]

A pointer to a pointer to bytes that receive the encrypted Schannel contents. When you have finished using the Schannel contents, free *pData* by calling the [VirtualFree](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfree) function.

### `dwDecSize` [out]

Number of bytes allocated for *pData*.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**