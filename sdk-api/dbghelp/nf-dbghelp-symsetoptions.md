# SymSetOptions function

## Description

Sets the options mask.

## Parameters

### `SymOptions` [in]

The symbol options. Zero is a valid value and indicates that all options are turned off. The options values are combined using the OR operator to form a valid options value. The following are valid values.

| Value | Meaning |
| --- | --- |
| **SYMOPT_ALLOW_ABSOLUTE_SYMBOLS**<br><br>0x00000800 | Enables the use of symbols that are stored with absolute addresses. Most symbols are stored as RVAs from the base of the module. DbgHelp translates them to absolute addresses. There are symbols that are stored as an absolute address. These have very specialized purposes and are typically not used.<br><br>**DbgHelp 5.1 and earlier:** This value is not supported. |
| **SYMOPT_ALLOW_ZERO_ADDRESS**<br><br>0x01000000 | Enables the use of symbols that do not have an address. By default, DbgHelp filters out symbols that do not have an address. |
| **SYMOPT_AUTO_PUBLICS**<br><br>0x00010000 | Do not search the public symbols when searching for symbols by address, or when enumerating symbols, unless they were not found in the global symbols or within the current scope. This option has no effect with **SYMOPT_PUBLICS_ONLY**.<br><br>**DbgHelp 5.1 and earlier:** This value is not supported. |
| **SYMOPT_CASE_INSENSITIVE**<br><br>0x00000001 | All symbol searches are insensitive to case. |
| **SYMOPT_DEBUG**<br><br>0x80000000 | Pass debug output through [OutputDebugString](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-outputdebugstringw) or the [SymRegisterCallbackProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psymbol_registered_callback) callback function. |
| **SYMOPT_DEFERRED_LOADS**<br><br>0x00000004 | Symbols are not loaded until a reference is made requiring the symbols be loaded. This is the fastest, most efficient way to use the symbol handler. |
| **SYMOPT_DISABLE_SYMSRV_AUTODETECT**<br><br>0x02000000 | Disables the auto-detection of symbol server stores in the symbol path, even without the "SRV*" designation, maintaining compatibility with previous behavior.<br><br>**DbgHelp 6.6 and earlier:** This value is not supported. |
| **SYMOPT_EXACT_SYMBOLS**<br><br>0x00000400 | Do not load an unmatched .pdb file. Do not load export symbols if all else fails. |
| **SYMOPT_FAIL_CRITICAL_ERRORS**<br><br>0x00000200 | Do not display system dialog boxes when there is a media failure such as no media in a drive. Instead, the failure happens silently. |
| **SYMOPT_FAVOR_COMPRESSED**<br><br>0x00800000 | If there is both an uncompressed and a compressed file available, favor the compressed file. This option is good for slow connections. |
| **SYMOPT_FLAT_DIRECTORY**<br><br>0x00400000 | Symbols are stored in the root directory of the default downstream store.<br><br>**DbgHelp 6.1 and earlier:** This value is not supported. |
| **SYMOPT_IGNORE_CVREC**<br><br>0x00000080 | Ignore path information in the CodeView record of the image header when loading a .pdb file. |
| **SYMOPT_IGNORE_IMAGEDIR**<br><br>0x00200000 | Ignore the image directory.<br><br>**DbgHelp 6.1 and earlier:** This value is not supported. |
| **SYMOPT_IGNORE_NT_SYMPATH**<br><br>0x00001000 | Do not use the path specified by **_NT_SYMBOL_PATH** if the user calls [SymSetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetsearchpath) without a valid path.<br><br>**DbgHelp 5.1:** This value is not supported. |
| **SYMOPT_INCLUDE_32BIT_MODULES**<br><br>0x00002000 | When debugging on 64-bit Windows, include any 32-bit modules. |
| **SYMOPT_LOAD_ANYTHING**<br><br>0x00000040 | Disable checks to ensure a file (.exe, .dbg., or .pdb) is the correct file. Instead, load the first file located. |
| **SYMOPT_LOAD_LINES**<br><br>0x00000010 | Loads line number information. |
| **SYMOPT_NO_CPP**<br><br>0x00000008 | All C++ decorated symbols containing the symbol separator "::" are replaced by "__". This option exists for debuggers that cannot handle parsing real C++ symbol names. |
| **SYMOPT_NO_IMAGE_SEARCH**<br><br>0x00020000 | Do not search the image for the symbol path when loading the symbols for a module if the module header cannot be read.<br><br>**DbgHelp 5.1:** This value is not supported. |
| **SYMOPT_NO_PROMPTS**<br><br>0x00080000 | Prevents prompting for validation from the symbol server. |
| **SYMOPT_NO_PUBLICS**<br><br>0x00008000 | Do not search the publics table for symbols. This option should have little effect because there are copies of the public symbols in the globals table.<br><br>**DbgHelp 5.1:** This value is not supported. |
| **SYMOPT_NO_UNQUALIFIED_LOADS**<br><br>0x00000100 | Prevents symbols from being loaded when the caller examines symbols across multiple modules. Examine only the module whose symbols have already been loaded. |
| **SYMOPT_OVERWRITE**<br><br>0x00100000 | Overwrite the downlevel store from the symbol store.<br><br>**DbgHelp 6.1 and earlier:** This value is not supported. |
| **SYMOPT_PUBLICS_ONLY**<br><br>0x00004000 | Do not use private symbols. The version of DbgHelp that shipped with earlier Windows release supported only public symbols; this option provides compatibility with this limitation.<br><br>**DbgHelp 5.1:** This value is not supported. |
| **SYMOPT_SECURE**<br><br>0x00040000 | DbgHelp will not load any symbol server other than SymSrv. SymSrv will not use the downstream store specified in **_NT_SYMBOL_PATH**. After this flag has been set, it cannot be cleared.<br><br>**DbgHelp 6.0 and 6.1:** This flag can be cleared.<br><br>**DbgHelp 5.1:** This value is not supported. |
| **SYMOPT_UNDNAME**<br><br>0x00000002 | All symbols are presented in undecorated form. <br><br>This option has no effect on global or local symbols because they are stored undecorated. This option applies only to public symbols. |

## Return value

The function returns the current options mask.

## Remarks

The options value can be changed any number of times while the library is in use by an application. The option change affects all future calls to the symbol handler.

To get the current options mask, call the
[SymGetOptions](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetoptions) function.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

#### Examples

For an example, see
[Initializing the Symbol Handler](https://learn.microsoft.com/windows/desktop/Debug/initializing-the-symbol-handler).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymGetOptions](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetoptions)