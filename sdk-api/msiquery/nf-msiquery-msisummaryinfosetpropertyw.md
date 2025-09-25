# MsiSummaryInfoSetPropertyW function

## Description

The
**MsiSummaryInfoSetProperty** function sets a single summary information property.

**Note** The meaning of the property value depends on whether the summary information stream is for an installation database (.msi file), transform (.mst file) or patch (.msp file). See [Summary Property Descriptions](https://learn.microsoft.com/windows/desktop/Msi/summary-property-descriptions) and [Summary Information Stream Property Set](https://learn.microsoft.com/windows/desktop/Msi/summary-information-stream-property-set) for more information about summary information properties.

## Parameters

### `hSummaryInfo` [in]

Handle to summary information.

### `uiProperty` [in]

Specifies the property ID of the summary property being set. This parameter can be a property ID listed in the [Summary Information Stream Property Set](https://learn.microsoft.com/windows/desktop/Msi/summary-information-stream-property-set). This function does not set values for PID_DICTIONARY OR PID_THUMBNAIL property.

### `uiDataType` [in]

Specifies the type of property to set. This parameter can be a type listed in the
[Summary Information Stream Property Set](https://learn.microsoft.com/windows/desktop/Msi/summary-information-stream-property-set).

### `iValue` [in]

Specifies the integer value.

### `pftValue` [in]

Specifies the file-time value.

### `szValue` [in]

Specifies the text value.

## Return value

The
**MsiSummaryInfoSetProperty** function returns the following values:

## See also

[Summary Information Property Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)

[Summary Information Stream Property Set](https://learn.microsoft.com/windows/desktop/Msi/summary-information-stream-property-set)

[Summaryinfo.Property](https://learn.microsoft.com/windows/desktop/Msi/summaryinfo-summaryinfo)

## Remarks

> [!NOTE]
> The msiquery.h header defines MsiSummaryInfoSetProperty as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).