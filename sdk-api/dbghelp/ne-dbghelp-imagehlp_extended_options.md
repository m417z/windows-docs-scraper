# IMAGEHLP_EXTENDED_OPTIONS enumeration

## Description

Lists the extended symbol options that you can get and set by using the [SymGetExtendedOption](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetextendedoption) and [SymSetExtendedOption](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetextendedoption) functions.

## Constants

### `SYMOPT_EX_DISABLEACCESSTIMEUPDATE`

Turns off explicit updates to the last access time of a symbol that is loaded. By default, DbgHelp updates the last access time of a symbol file that is consumed so that a symbol cache can be maintained by using a least recently used mechanism.

### `SYMOPT_EX_MAX`

Unused.

## See also

[SymGetExtendedOption](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetextendedoption)

[SymSetExtendedOption](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetextendedoption)