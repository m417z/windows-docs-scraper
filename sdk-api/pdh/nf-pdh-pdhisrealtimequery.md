# PdhIsRealTimeQuery function

## Description

Determines if the specified query is a real-time query.

## Parameters

### `hQuery` [in]

Handle to the query. The
[PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya) function returns this handle.

## Return value

If the query is a real-time query, the return value is **TRUE**.

If the query is not a real-time query, the return value is **FALSE**.

## Remarks

The term *real-time* as used in the description of this function does not imply the standard meaning of the term *real-time*. Instead, it describes the collection of performance data from a source providing current information (for example, the registry or a WMI provider) rather than from a log file.

## See also

[PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya)

[PdhSelectDataSource](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhselectdatasourcea)