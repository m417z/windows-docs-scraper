# MsiSummaryInfoGetPropertyA function

## Description

The
**MsiSummaryInfoGetProperty** function gets a single property from the [summary information stream](https://learn.microsoft.com/windows/desktop/Msi/summary-information-stream).

**Note** The meaning of the property value depends on whether the summary information stream is for an installation database (.msi file), transform (.mst file) or patch (.msp file). See [Summary Property Descriptions](https://learn.microsoft.com/windows/desktop/Msi/summary-property-descriptions) and [Summary Information Stream Property Set](https://learn.microsoft.com/windows/desktop/Msi/summary-information-stream-property-set) for more information about summary information properties.

## Parameters

### `hSummaryInfo` [in]

Handle to summary information.

### `uiProperty` [in]

Specifies the property ID of the summary property. This parameter can be a property ID listed in the [Summary Information Stream Property Set](https://learn.microsoft.com/windows/desktop/Msi/summary-information-stream-property-set). This function does not return values for PID_DICTIONARY OR PID_THUMBNAIL property.

### `puiDataType` [out]

Receives the returned property type. This parameter can be a type listed in the
[Summary Information Stream Property Set](https://learn.microsoft.com/windows/desktop/Msi/summary-information-stream-property-set).

### `piValue` [out]

Receives the returned integer property data.

### `pftValue` [out]

Pointer to a file value.

### `szValueBuf` [out]

Pointer to the buffer that receives the null terminated summary information property value. Do not attempt to determine the size of the buffer by passing in a null (value=0) for *szValueBuf*. You can get the size of the buffer by passing in an empty string (for example ""). The function then returns ERROR_MORE_DATA and *pcchValueBuf* contains the required buffer size in **TCHARs**, not including the terminating null character. On return of ERROR_SUCCESS, *pcchValueBuf* contains the number of **TCHARs** written to the buffer, not including the terminating null character. This parameter is an empty string if there are no errors.

### `pcchValueBuf` [in, out]

Pointer to the variable that specifies the size, in **TCHARs**, of the buffer pointed to by the variable *szValueBuf*. When the function returns ERROR_SUCCESS, this variable contains the size of the data copied to *szValueBuf*, not including the terminating null character. If *szValueBuf* is not large enough, the function returns ERROR_MORE_DATA and stores the required size, not including the terminating null character, in the variable pointed to by *pcchValueBuf*.

## Return value

The
**MsiSummaryInfoGetProperty** function returns one of the following values:

## Remarks

If ERROR_MORE_DATA is returned, the parameter which is a pointer gives the size of the buffer required to hold the string. If ERROR_SUCCESS is returned, it gives the number of characters written to the string buffer. Therefore you can get the size of the buffer by passing in an empty string (for example "") for the parameter that specifies the buffer. Do not attempt to determine the size of the buffer by passing in a Null (value=0).

Windows Installer functions that return data in a user provided memory location should not be called with null as the value for the pointer. These functions return a string or return data as integer pointers, but return inconsistent values when passing null as the value for the output argument. For more information, see
[Passing Null as the Argument of Windows Installer Functions](https://learn.microsoft.com/windows/desktop/Msi/passing-null-as-the-argument-of-windows-installer-functions).

The property information returned by the **MsiSummaryInfoGetProperty** function is received by the *piValue*, *pftValue*, or *szValueBuf* parameter depending upon the type of property value that has been specified in the *puiDataType* parameter.

> [!NOTE]
> The msiquery.h header defines MsiSummaryInfoGetProperty as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Passing Null as the Argument of Windows Installer Functions](https://learn.microsoft.com/windows/desktop/Msi/passing-null-as-the-argument-of-windows-installer-functions)

[Summary Information Property Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)

[Summary Information Stream Property Set](https://learn.microsoft.com/windows/desktop/Msi/summary-information-stream-property-set)

[Summaryinfo.Property](https://learn.microsoft.com/windows/desktop/Msi/summaryinfo-summaryinfo)