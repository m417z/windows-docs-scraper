# SetupQueryInfVersionInformationW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupQueryInfVersionInformation** function returns INF file version information from an
[SP_INF_INFORMATION](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_inf_information) structure to a buffer.

## Parameters

### `InfInformation` [in]

Pointer to an
[SP_INF_INFORMATION](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_inf_information) structure previously returned from a call to the
[SetupGetInfInformation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetinfinformationa) function.

### `InfIndex` [in]

Index of the constituent INF file to retrieve version information from. This index can be in the range [0, *InfInformation.InfCount*). Meaning that the values zero through, but not including, *InfInformation.InfCount* are valid.

### `Key` [in]

Optional pointer to a **null**-terminated string containing the key name whose associated string is to be retrieved. If this parameter is **NULL**, all resource keys are copied to the supplied buffer. Each string is **null**-terminated, with an extra **null** at the end of the list.

### `ReturnBuffer` [in, out]

If not **NULL**, *ReturnBuffer* points to a call-supplied character buffer in which this function returns the INF file style. You should use a **null**-terminated string. The **null**-terminated string should not exceed the size of the destination buffer. You can call the function once to get the required buffer size, allocate the necessary memory, and then call the function a second time to retrieve the data. Using this technique, you can avoid errors due to an insufficient buffer size. See the Remarks section. This parameter can be **NULL**.

### `ReturnBufferSize` [in]

Size of the buffer pointed to by the *ReturnBuffer* parameter, in characters. This number includes the **null** terminator.

### `RequiredSize` [in, out]

If not **NULL**, pointer to a variable that receives the size required for the buffer pointed to by the *ReturnBuffer* parameter, in characters. This number includes the **null** terminator. If *ReturnBuffer* is specified and the actual size is larger than the value specified by *ReturnBufferSize*, the function fails and a call to
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If this function is called with a *ReturnBuffer* of **NULL** and a *ReturnBufferSize* of zero, the function puts the buffer size needed to hold the specified data into the variable pointed to by *RequiredSize*. If the function succeeds in this, the return value is a nonzero value. Otherwise, the return value is zero and extended error information can be obtained by calling [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If
**SetupQueryInfVersionInformation** is called on a legacy INF file , then version information is generated from the legacy INF file in the following manner:

1. The OptionType key in the **Identification** section of the legacy file is returned as the Class key value.
2. The FileType key in the **Signature** section of the legacy INF file becomes the Signature key value.
3. If the value of the FileType key of the legacy INF file is MICROSOFT_FILE, then the Provider key value is set to "Microsoft".

The following table summarizes how the information is translated before it is passed into the
[SP_INF_INFORMATION](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_inf_information) structure.

| Legacy file information | Windows INF information |
| --- | --- |
| ``` syntax [Identification] OptionType = Mouse ``` | ``` syntax [Version] Class=Mouse ``` |
| ``` syntax [Signature] FileType = MICROSOFT_FILE ``` | ``` syntax Signature=MICROSOFT_FILE ``` |
| (if the FileType is MICROSOFT_FILE) | ``` syntax Provider="Microsoft" ``` |

> [!NOTE]
> The setupapi.h header defines SetupQueryInfVersionInformation as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupGetInfInformation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetinfinformationa)

[SetupQueryInfFileInformation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueryinffileinformationa)