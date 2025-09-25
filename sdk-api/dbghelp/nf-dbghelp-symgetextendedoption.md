# SymGetExtendedOption function

## Description

Gets whether the specified extended symbol option on or off.

## Parameters

### `option` [in]

The extended symbol option to check. The following are valid values.

| Value | Meaning |
| --- | --- |
| **SYMOPT_EX_DISABLEACCESSTIMEUPDATE**<br><br>0 | Turns off explicit updates to the last access time of a symbol that is loaded. By default, DbgHelp updates the last access time of a symbol file that is consumed so that a symbol cache can be maintained by using a least recently used mechanism. |

## Return value

The value of the specified symbol option.

## See also

[IMAGEHLP_EXTENDED_OPTIONS](https://learn.microsoft.com/windows/desktop/api/dbghelp/ne-dbghelp-imagehlp_extended_options)

[SymSetExtendedOption](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetextendedoption)