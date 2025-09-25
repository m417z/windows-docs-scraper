# PWINDBG_EXTENSION_API_VERSION callback function

## Description

The *PWINDBG_EXTENSION_API_VERSION* (**ExtensionApiVersion**) callback function returns version information about the extension DLL.

## Return value

This function must return a pointer to an **EXT_API_VERSION** structure.

## Remarks

You must define this function in your code using the prototype above. Include wdbgexts.h.

*ExtensionApiVersion* is called by the debugger when the extension DLL is loaded.

The debugger uses the **MajorVersion** and **MinorVersion** fields of the returned **EXT_API_VERSION** structure when executing commands like [.chain](https://learn.microsoft.com/windows-hardware/drivers/debugger/-chain--list-debugger-extensions-) and [version](https://learn.microsoft.com/windows-hardware/drivers/mobilebroadband/version) that display the extension version number. The debugger does not perform any "version checking" -- the extension DLL will be loaded regardless of what version numbers are present in these fields.

The **Revision** field of the returned **EXT_API_VERSION** structure should be EXT_API_VERSION_NUMBER64 if you are using 64-bit pointers in your code, or EXT_API_VERSION_NUMBER32 if you are using 32-bit pointers. It is recommended that you always use 64-bit pointers in your code, since the debugger will automatically resize these pointers when necessary. See [32-Bit Pointers and 64-Bit Pointers](https://learn.microsoft.com/windows-hardware/drivers/debugger/32-bit-pointers-and-64-bit-pointers) for details.

For more details, see [Using WdbgExts Extension Callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-wdbgexts-extension-callbacks).