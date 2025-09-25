# SetupGetBinaryField function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupGetBinaryField** function retrieves binary data from a line in an INF file section, from the specified field to the end of the line.

## Parameters

### `Context` [in]

INF context for the line.

### `FieldIndex` [in]

The 1-based index of the starting field within the specified line from which the binary data should be retrieved. The binary data is built from each field, starting at this point to the end of the line. Each field corresponds to 1 byte and is in hexadecimal notation. A *FieldIndex* of zero is not valid with this function.

### `ReturnBuffer` [in, out]

Optional pointer to a buffer that receives the binary data. You should ensure the destination buffer is the same size or larger than the source buffer. You can call the function once to get the required buffer size, allocate the necessary memory, and then call the function a second time to retrieve the data. Using this technique, you can avoid errors due to an insufficient buffer size. See the Remarks section.

### `ReturnBufferSize` [in]

Size of the buffer pointed to by *ReturnBuffer*, in characters. This number includes the **null** terminator.

### `RequiredSize` [in, out]

Optional pointer to a variable that receives the required size for the buffer pointed to *ReturnBuffer*, in characters. This number includes the **null** terminator. If the size needed is larger than the value specified by *ReturnBufferSize*, the function fails and a call to [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INVALID_DATA if a field that
**SetupGetBinaryField** retrieves is not a valid hexadecimal number in the range 0-FF.

## Remarks

If this function is called with a *ReturnBuffer* of **NULL** and a *ReturnBufferSize* of zero, the function puts the buffer size needed to hold the specified data into the variable pointed to by *RequiredSize*. If the function succeeds in this, the return value is a nonzero value. Otherwise, the return value is zero and extended error information can be obtained by calling [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

To better understand how this function works, consider the following line from an INF file.

``` syntax
X=34,FF,00,13
```

If
**SetupGetBinaryField** was called on the preceding line, the binary values 34, FF, 00, and 13 would be put into the buffer specified by *ReturnBuffer*.

For the Unicode version of this function, the buffer sizes *ReturnBufferSize* and *RequiredSize* are specified in number of characters. This number includes the **null** terminator. For the ANSI version of this function, the sizes are specified in number of bytes.

If this function is called with a *ReturnBuffer* of **NULL** and a *ReturnBufferSize* of zero, the function puts the buffer size needed to hold the specified data into the variable pointed to by *RequiredSize*. If the function succeeds in this, the return value is a nonzero value. Otherwise, the return value is zero and extended error information can be obtained by calling
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Thus, you can call the function once to get the required buffer size, allocate the necessary memory, and then call the function a second time to retrieve the data. Using this technique, you can avoid errors due to an insufficient buffer size.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupGetIntField](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetintfield)

[SetupGetMultiSzField](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetmultiszfielda)

[SetupGetStringField](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetstringfielda)