# SymGetOptions function

## Description

Retrieves the current option mask.

## Return value

The
function returns the current options that have been set. Zero is a valid value and indicates that all options are turned off.

## Remarks

These options can be changed several times while the library is in use by an application. Any option change affects all future calls to the symbol handler.

The return value is the combination of the
following values that have been set using the [SymSetOptions](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetoptions) function.

* SYMOPT_ALLOW_ABSOLUTE_SYMBOLS
* SYMOPT_ALLOW_ZERO_ADDRESS
* SYMOPT_AUTO_PUBLICS
* SYMOPT_CASE_INSENSITIVE
* SYMOPT_DEBUG
* SYMOPT_DEFERRED_LOADS
* SYMOPT_EXACT_SYMBOLS
* SYMOPT_FAIL_CRITICAL_ERRORS
* SYMOPT_FAVOR_COMPRESSED
* SYMOPT_FLAT_DIRECTORY
* SYMOPT_IGNORE_CVREC
* SYMOPT_IGNORE_IMAGEDIR
* SYMOPT_IGNORE_NT_SYMPATH
* SYMOPT_INCLUDE_32BIT_MODULES
* SYMOPT_LOAD_ANYTHING
* SYMOPT_LOAD_LINES
* SYMOPT_NO_CPP
* SYMOPT_NO_IMAGE_SEARCH
* SYMOPT_NO_PROMPTS
* SYMOPT_NO_PUBLICS
* SYMOPT_NO_UNQUALIFIED_LOADS
* SYMOPT_OVERWRITE
* SYMOPT_PUBLICS_ONLY
* SYMOPT_SECURE
* SYMOPT_UNDNAME

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)