# ICreateErrorInfo::SetDescription

## Description

Sets the textual description of the error.

## Parameters

### `szDescription` [in]

A brief description of the error.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

The text should be supplied in the language specified by the locale ID (LCID) that was passed to the method raising the error. For more information, see LCID Attribute in [Type Libraries and the Object Description Language](https://learn.microsoft.com/previous-versions/windows/desktop/automat/type-libraries-and-the-object-description-language).

Use of this function is demonstrated in the file Main.cpp of the COM Fundamentals Hello sample.

## See also

[ICreateErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreateerrorinfo)