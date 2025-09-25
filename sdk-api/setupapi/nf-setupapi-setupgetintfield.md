# SetupGetIntField function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupGetIntField** function retrieves an integer value from the specified field of a line in an INF file.

## Parameters

### `Context` [in]

Pointer to the context for a line in an INF file.

### `FieldIndex` [in]

The 1-based index of the field within the specified line from which the integer should be retrieved.

A *FieldIndex* of 0 can be used to retrieve an integer key (For example, consider the following INF line, 431 = 1, 2, 4. The value 431 would be put into the variable pointed at by *IntegerValue* if
**SetupGetIntField** was called with a *FieldIndex* of 0).

### `IntegerValue` [out]

Pointer to a variable that receives the integer. If the field is not an integer, the function fails and a call to
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INVALID_DATA.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The integer field may start with a positive (+) or negative (-) sign. It will be interpreted as a decimal number, unless prefixed in the file with 0x or 0X, in which case it is hexadecimal.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupGetBinaryField](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetbinaryfield)

[SetupGetMultiSzField](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetmultiszfielda)

[SetupGetStringField](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetstringfielda)