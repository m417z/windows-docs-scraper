# ODJ_UNICODE_STRING structure

Contains a Unicode string.

## Members

### Length

Must be set to the number of bytes in Buffer containing the string, not including the NULL terminator.

### MaximumLength

This MUST be set to the total number of bytes in Buffer, not including the NULL terminator.

### Buffer

Must be a Unicode string.

## See also

[**Offline Domain Join IDL Definitions**](https://learn.microsoft.com/windows/win32/netmgmt/odj-idl)