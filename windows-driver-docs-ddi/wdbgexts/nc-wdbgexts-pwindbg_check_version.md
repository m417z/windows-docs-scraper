# PWINDBG_CHECK_VERSION callback function

## Description

The *PWINDBG_CHECK_VERSION* (**CheckVersion**) callback function verifies that the extension module version matches the debugger version, and outputs a warning message if there is a mismatch.

## Return value

None

### Additional Information

You must define this function in your code using the prototype above.

For more details, see [Using WdbgExts Extension Callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-wdbgexts-extension-callbacks).

## Remarks

*CheckVersion* is an optional callback function. If it exists, it will be called by the debugger the first time an extension function exported by the extension DLL is used.

The purpose of this function is to allow you to print out a version mismatch warning when the extension DLL is used. This is an optional feature, which should not be confused with the version number used by [ExtensionApiVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_extension_api_version).

If the [.noversion](https://learn.microsoft.com/windows-hardware/drivers/debugger/-noversion--disable-version-checking-) command is used, version checking is disabled and the debugger will not call *CheckVersion*.