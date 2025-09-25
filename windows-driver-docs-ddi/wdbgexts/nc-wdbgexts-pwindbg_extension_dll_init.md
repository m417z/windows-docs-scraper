# PWINDBG_EXTENSION_DLL_INIT callback function

## Description

The **PWINDBG_EXTENSION_DLL_INIT** ( **WinDbgExtensionDllInit**) callback function is used to load and initialize the extension module.

## Parameters

### `lpExtensionApis`

A pointer to a WINDBG_EXTENSION_APIS64 structure, which contains pointers to functions that you can use for standard operations. Copy the entire structure to a global variable in your DLL. For example, you could create a global variable named ExtensionApis as shown in the following example.

```cpp
WINDBG_EXTENSION_APIS64   ExtensionApis;
```

### `MajorVersion`

Specifies the Microsoft Windows build type. A value of 0xC indicates the checked build of Windows. A value of 0xF indicates the free build of Windows. Save this value in a global variable in your DLL. For example, you could create a global variable named SavedMajorVersion.

### `MinorVersion`

Specifies the Windows build number (for example 2600) of the target system. Save this value in a global variable in your DLL. For example, you could create a global variable named SavedMinorVersion.

## Remarks

*WinDbgExtensionDllInit* is called by the debugger when the extension DLL is loaded.

It is recommended that you always use 64-bit pointers in your code, since the debugger will automatically resize these pointers when necessary. See [32-Bit Pointers and 64-Bit Pointers](https://learn.microsoft.com/windows-hardware/drivers/debugger/32-bit-pointers-and-64-bit-pointers) for details. However, if you choose to use 32-bit pointers, the first parameter of *WinDbgExtensionDllInit* will have the type PWINDBG_EXTENSION_APIS instead of PWINDBG_EXTENSION_APIS64.

For more details, see [Using WdbgExts Extension Callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-wdbgexts-extension-callbacks).