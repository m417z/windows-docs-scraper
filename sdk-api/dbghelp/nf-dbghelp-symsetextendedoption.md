# SymSetExtendedOption function

## Description

Turns the specified extended symbol option on or off.

## Parameters

### `option` [in]

The extended symbol option to turn on or off. The following are valid values.

| Value | Meaning |
| --- | --- |
| **SYMOPT_EX_DISABLEACCESSTIMEUPDATE**<br><br>0 | When set to TRUE, turns off explicitly updating the last access time of a symbol that is loaded. By default, DbgHelp updates the last access time of a symbol file that is consumed so that a symbol cache can be maintained by using a least recently used mechanism. |

### `value` [in]

The value to set for the specified option, either TRUE or FALSE.

## Return value

The previous value of the specified extended option.

## See also

[IMAGEHLP_EXTENDED_OPTIONS](https://learn.microsoft.com/windows/desktop/api/dbghelp/ne-dbghelp-imagehlp_extended_options)

[SymGetExtendedOption](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetextendedoption)