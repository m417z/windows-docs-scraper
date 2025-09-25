# VALENTW structure

## Description

Contains information about a registry value. The
[RegQueryMultipleValues](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regquerymultiplevaluesa) function uses this structure.

## Members

### `ve_valuename`

The name of the value to be retrieved. Be sure to set this member before calling
[RegQueryMultipleValues](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regquerymultiplevaluesa).

### `ve_valuelen`

The size of the data pointed to by **ve_valueptr**, in bytes.

### `ve_valueptr`

A pointer to the data for the value entry. This is a pointer to the value's data returned in the **lpValueBuf** buffer filled in by
[RegQueryMultipleValues](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regquerymultiplevaluesa).

### `ve_type`

The type of data pointed to by **ve_valueptr**. For a list of the possible types, see
[Registry Value Types](https://learn.microsoft.com/windows/desktop/SysInfo/registry-value-types).

## See also

[RegQueryMultipleValues](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regquerymultiplevaluesa)

## Remarks

> [!NOTE]
> The winreg.h header defines VALENT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).