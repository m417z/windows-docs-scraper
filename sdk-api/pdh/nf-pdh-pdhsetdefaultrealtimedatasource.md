# PdhSetDefaultRealTimeDataSource function

## Description

Specifies the source of the real-time data.

## Parameters

### `dwDataSourceId` [in]

Source of the performance data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DATA_SOURCE_REGISTRY** | The data source is the registry interface. This is the default. |
| **DATA_SOURCE_WBEM** | The data source is a WMI provider. |

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following is a possible value.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_ARGUMENT** | The parameter is not valid. |

## Remarks

The term *real-time* as used in the description of this function does not imply the standard meaning of the term *real-time*. Instead, it describes the collection of performance data from a source providing current information (for example, the registry or a WMI provider) rather than from a log file.

If you want to query real-time data from WMI, you must call **PdhSetDefaultRealTimeDataSource** to set the default real-time data source. You must call this function before calling any other PDH API function.

## See also

[PdhSelectDataSource](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhselectdatasourcea)