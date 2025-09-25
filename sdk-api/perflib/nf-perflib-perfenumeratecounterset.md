# PerfEnumerateCounterSet function

## Description

Gets the counter set identifiers of the counter sets that are registered on the

specified system.

Counter set identifiers are globally unique identifiers (GUIDs).

## Parameters

### `szMachine` [in, optional]

The name of the machine for which to get the counter set identifiers. If NULL, the function retrieves the counter set identifiers for the local machine.

### `pCounterSetIds` [out, optional]

A pointer to a buffer that has enough space to receive the number of GUIDs that the *cCounterSetIds* parameter specifies. May be NULL if

*cCounterSetIds* is 0.

### `cCounterSetIds`

The size of the buffer that the *pCounterSetIds* parameter specifies, measured in GUIDs.

### `pcCounterSetIdsActual` [out]

The size of the buffer actually required to get the counter set identifiers. The meaning depends on the value that the function

returns.

| Function Return Value | Meaning of *pcCounterSetIdsActual* |
| --- | --- |
| **ERROR_SUCCESS** | The number of <br><br> GUIDs that the function stored in the buffer that *pCounterSetIds* specified. |
| **ERROR_NOT_ENOUGH_MEMORY** | The <br><br> size (in GUIDs) of the buffer required. Enlarge the buffer to the required <br><br> size and call the function again. |
| Other | The value is undefined and should not be used. |

## Return value

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function successfully stored all of the content set identifiers in the buffer that *pCounterSetIds* specified. The value that *pcCounterSetIdsActual* points to indicates the number of counter set identifiers actually stored in the buffer. |
| **ERROR_NOT_ENOUGH_MEMORY** | The buffer that *pCounterSetIds* specified was not large enough to store all of the counter set identifiers for the counter sets on the specified system. The value that *pcCounterSetIdsActual* points to indicates the size of the buffer required to store all of the counter set identifiers. Enlarge the buffer to the required <br><br> size and call the function again. |

For other types of failures, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[PerfEnumerateCounterSetInstances](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfenumeratecountersetinstances)