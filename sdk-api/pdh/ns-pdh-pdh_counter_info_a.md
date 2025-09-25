# PDH_COUNTER_INFO_A structure

## Description

The
**PDH_COUNTER_INFO** structure contains information describing the properties of a counter. This information also includes the counter path.

## Members

### `dwLength`

Size of the structure, including the appended strings, in bytes.

### `dwType`

Counter type. For a list of counter types, see the Counter Types section of the [Windows Server 2003 Deployment Kit](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc776490(v=ws.10)). The counter type constants are defined in Winperf.h.

### `CVersion`

Counter version information.
Not used.

### `CStatus`

Counter status that indicates if the counter value is valid. For a list of possible values, see
[Checking PDH Interface Return Values](https://learn.microsoft.com/windows/desktop/PerfCtrs/checking-pdh-interface-return-values).

### `lScale`

Scale factor to use when computing the displayable value of the counter.
The scale factor is a power of ten. The valid range of this parameter is PDH_MIN_SCALE (–7) (the returned value is the actual value times 10–⁷) to PDH_MAX_SCALE (+7) (the returned value is the actual value times 10⁺⁷). A value of zero will set the scale to one, so that the actual value is returned

### `lDefaultScale`

Default scale factor as suggested by the counter's provider.

### `dwUserData`

The value passed in the *dwUserData* parameter when calling [PdhAddCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhaddcountera).

### `dwQueryUserData`

The value passed in the *dwUserData* parameter when calling [PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya).

### `szFullPath`

**Null**-terminated string that specifies the full counter path. The string follows this structure in memory.

### `DataItemPath`

A
[PDH_DATA_ITEM_PATH_ELEMENTS](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_data_item_path_elements_a) structure. Not used.

### `CounterPath`

A
[PDH_COUNTER_PATH_ELEMENTS](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_counter_path_elements_a) structure.

### `szMachineName`

**Null**-terminated string that contains the name of the computer specified in the counter path. Is **NULL**, if the path does not specify a computer. The string follows this structure in memory.

### `szObjectName`

**Null**-terminated string that contains the name of the performance object specified in the counter path. The string follows this structure in memory.

### `szInstanceName`

**Null**-terminated string that contains the name of the object instance specified in the counter path. Is **NULL**, if the path does not specify an instance. The string follows this structure in memory.

### `szParentInstance`

**Null**-terminated string that contains the name of the parent instance specified in the counter path. Is **NULL**, if the path does not specify a parent instance. The string follows this structure in memory.

### `dwInstanceIndex`

Instance index specified in the counter path. Is 0, if the path does not specify an instance index.

### `szCounterName`

**Null**-terminated string that contains the counter name. The string follows this structure in memory.

### `szExplainText`

Help text that describes the counter. Is **NULL** if the source is a log file.

### `DataBuffer`

Start of the string data that is appended to the structure.

## Remarks

When you allocate memory for this structure, allocate enough memory for the member strings, such as **szCounterName**, that are appended to the end of this structure.

## See also

[PDH_COUNTER_PATH_ELEMENTS](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_counter_path_elements_a)

[PDH_DATA_ITEM_PATH_ELEMENTS](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_data_item_path_elements_a)

[PdhGetCounterInfo](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetcounterinfoa)