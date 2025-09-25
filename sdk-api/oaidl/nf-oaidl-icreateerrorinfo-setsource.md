# ICreateErrorInfo::SetSource

## Description

Sets the language-dependent programmatic identifier (ProgID) for the class or application that raised the error.

## Parameters

### `szSource` [in]

A ProgID in the form *progname*.*objectname*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

This method should be used to identify the class or application that is the source of the error. The language for the returned ProgID depends on the locale identifier (LCID) that was passed to the method at the time of invocation.

Use of this function is demonstrated in the file Main.cpp of the COM Fundamentals Hello sample.

## See also

[ICreateErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreateerrorinfo)