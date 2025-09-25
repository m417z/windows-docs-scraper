# wiasFormatArgs function

## Description

The **wiasFormatArgs** function formats an argument list into a packaged string for logging.

## Parameters

### `lpszFormat`

Specifies a variable argument list, which starts with an ANSI format string containing the message and any format specifiers.

### `...`

The ellipsis (...) specifies a variable number of arguments that follow the format string.

####### - lpszFormat, ...

Specifies a variable argument list, which starts with an ANSI format string containing the message and any format specifiers. The ellipsis (...) specifies a variable number of arguments that follow the format string.

## Return value

This function returns a BSTR containing the format string, the arguments following the format string, and a format signature.