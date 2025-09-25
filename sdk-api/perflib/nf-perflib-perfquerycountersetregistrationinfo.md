# PerfQueryCounterSetRegistrationInfo function

## Description

Gets information about a counter set on the specified system.

## Parameters

### `szMachine` [in, optional]

The name of the machine for which to get the information about the counter set that the *pCounterSet* parameter specifies. If NULL, the function retrieves information about the specified counter set for the local machine.

### `pCounterSetId` [in]

The counter set identifier of the counter set for which you want to get information.

### `requestCode`

The type of information that you want to get about the counter set. See [PerfRegInfoType](https://learn.microsoft.com/windows/desktop/api/perflib/ne-perflib-perfreginfotype) for a list of possible values.

### `requestLangId`

The preferred locale identifier for the strings that contain the requested information if *requestCode* is **PERF_REG_COUNTERSET_NAME_STRING**,

**PERF_REG_COUNTERSET_HELP_STRING**, **PERF_REG_COUNTER_NAME_STRINGS**, or

**PERF_REG_COUNTER_HELP_STRINGS**.

The counter identifier of the counter for which you want data, if *requestCode* is **PERF_REG_COUNTER_STRUCT**.

Set to 0 for all other values of *requestCode*.

### `pbRegInfo` [out, optional]

Pointer to a buffer that is large enough to receive the amount of data that the *cbRegInfo* parameter specifies, in bytes. May be

NULL if *cbRegInfo* is 0.

### `cbRegInfo`

The size of the buffer that the *pbRegInfo* parameter specifies, in bytes.

### `pcbRegInfoActual` [out]

The size of the buffer actually required to get the information about the counter set. The meaning depends on the value that the function

returns.

| Function Return Value | Meaning of *pcbRegInfoActual* |
| --- | --- |
| **ERROR_SUCCESS** | The number of <br><br> bytes of information about the specified counter set that the function stored in the buffer that *pbRegInfo* specified. |
| **ERROR_NOT_ENOUGH_MEMORY** | The <br><br> size of the buffer required to store the information about the counter set on the specified machine, in bytes. Enlarge the buffer to the required <br><br> size and call the function again. |
| Other | The value is undefined and should not be used. |

## Return value

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function successfully stored all of the information about the counter set in the buffer that *pbRegInfo* specified. The value that *pcbRegInfoActual* points to indicates amount of information actually stored in the buffer, in bytes. |
| **ERROR_NOT_ENOUGH_MEMORY** | The buffer that *pbRegInfo* specified was not large enough to store all of the information about the counter set. The value that *pcbRegInfoActual* points to indicates the size of the buffer required to store all of the information. Enlarge the buffer to the required <br><br> size and call the function again. |

For other types of failures, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

See [PerfRegInfoType](https://learn.microsoft.com/windows/desktop/api/perflib/ne-perflib-perfreginfotype) for the types of data that you can request and

the formats of the data provided for each type of request.