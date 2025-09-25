# SetupGetInfInformationW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The **SetUpGetInfInformation** function returns the
[SP_INF_INFORMATION](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_inf_information) structure for the specified INF file to a buffer.

## Parameters

### `InfSpec` [in]

Handle or a file name for an INF file, depending on the value of *SearchControl*.

### `SearchControl` [in]

This parameter can be one of the following constants.

#### INFINFO_INF_SPEC_IS_HINF

*InfSpec* is an INF handle. A single INF handle may reference multiple INF files if they have been append-loaded together. If it does, the structure returned by this function contains multiple sets of information.

#### INFINFO_INF_NAME_IS_ABSOLUTE

The string specified for *InfSpec* is a full path. No further processing is performed on *InfSpec*.

#### INFINFO_DEFAULT_SEARCH

Search the default locations for the INF file specified for *InfSpec*, which is assumed to be a filename only. The default locations are *%windir%*\*inf*, followed by *%windir%*\*system32*.

#### INFINFO_REVERSE_DEFAULT_SEARCH

Same as INFINFO_DEFAULT_SEARCH, except the default locations are searched in reverse order.

#### INFINFO_INF_PATH_LIST_SEARCH

Search for the INF in each of the directories listed in the *DevicePath* value entry under the following:**HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion**

### `ReturnBuffer` [in, out]

If not **NULL**, points to a buffer in which this function returns the [SP_INF_INFORMATION](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_inf_information) structure.

You can call the function one time to get the required buffer size, allocate the necessary memory, and then call the function a second time to retrieve the data. Using this technique, you can avoid errors due to an insufficient buffer size. For more information, see the Remarks section of this topic.

### `ReturnBufferSize` [in]

Size of *ReturnBuffer*, in bytes.

### `RequiredSize` [in, out]

If not **NULL**, points to a variable in which this function returns the required size, in bytes, for the buffer pointed to by *ReturnBuffer*.

If *ReturnBuffer* is specified and the size needed is larger than *ReturnBufferSize*, the function fails and a call to [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER.

##### - SearchControl.INFINFO_DEFAULT_SEARCH

Search the default locations for the INF file specified for *InfSpec*, which is assumed to be a filename only. The default locations are *%windir%*\*inf*, followed by *%windir%*\*system32*.

##### - SearchControl.INFINFO_INF_NAME_IS_ABSOLUTE

The string specified for *InfSpec* is a full path. No further processing is performed on *InfSpec*.

##### - SearchControl.INFINFO_INF_PATH_LIST_SEARCH

Search for the INF in each of the directories listed in the *DevicePath* value entry under the following:**HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion**

##### - SearchControl.INFINFO_INF_SPEC_IS_HINF

*InfSpec* is an INF handle. A single INF handle may reference multiple INF files if they have been append-loaded together. If it does, the structure returned by this function contains multiple sets of information.

##### - SearchControl.INFINFO_REVERSE_DEFAULT_SEARCH

Same as INFINFO_DEFAULT_SEARCH, except the default locations are searched in reverse order.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is 0 (zero). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the INF file cannot be located, the function returns **FALSE** and a subsequent call to
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_FILE_NOT_FOUND.

## Remarks

If this function is called with a ReturnBuffer of **NULL** and a ReturnBufferSize of 0 (zero), the function puts the buffer size needed to hold the specified data into the variable pointed to by RequiredSize. If the function succeeds, the return value is a nonzero value. Otherwise, the return value is 0 (zero), and extended error information can be obtained by calling [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

> [!NOTE]
> The setupapi.h header defines SetupGetInfInformation as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupQueryInfFileInformation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueryinffileinformationa)

[SetupQueryInfVersionInformation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueryinfversioninformationa)