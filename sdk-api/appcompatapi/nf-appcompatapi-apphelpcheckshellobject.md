# ApphelpCheckShellObject function

## Description

[This function is available for use in the Windows Server 2003 and Windows XP operating systems. It may be altered or unavailable in the future.]

Enables applications to detect bad extension objects and either
block them from running or fix them.

## Parameters

### `ObjectCLSID` [in]

The GUID of a register class.

### `bShimIfNecessary` [in]

This parameter is **TRUE** if a shim is needed; **FALSE** otherwise.

### `pullFlags` [out]

This parameter is filled with a 64-bit flag mask that can be used to turn on application modification flags in Explorer/IE. These are located in the application compatibility database.

## Return value

**FALSE** if the object should be blocked from instantiating; **TRUE** otherwise.

## Remarks

This is a helper function for Explorer and Internet Explorer that allows those applications to detect bad extension objects and either block them from running or fix them.

If the database indicates that a shim should be used to fix the extension
and *bShimIfNecessary* is **TRUE**, this function loads Shimeng.dll and
applies the fix.

This function has no associated import library or header file; you must call it using the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.