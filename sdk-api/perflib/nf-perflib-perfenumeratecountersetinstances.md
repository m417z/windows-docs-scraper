# PerfEnumerateCounterSetInstances function

## Description

Gets the names and identifiers of the active instances of a counter set on the

specified system.

## Parameters

### `szMachine` [in, optional]

The name of the machine for which to get the information about the active instances of the counter set that the *pCounterSet* parameter specifies. If NULL, the function retrieves information about the active instances of the specified counter set for the local machine.

### `pCounterSetId` [in]

The counter set identifier of the counter set for which you want to get the information about of the active instances.

### `pInstances` [out, optional]

Pointer to a buffer that is large enough to receive the amount of data that the *cbInstances* parameter specifies. May be

NULL if *cbInstances* is 0.

### `cbInstances`

The size of the buffer that the *pInstances* parameter specifies, in bytes.

### `pcbInstancesActual` [out]

The size of the buffer actually required to get the information about of the active instances. The meaning depends on the value that the function

returns.

| Function Return Value | Meaning of *pcbInstancesActual* |
| --- | --- |
| **ERROR_SUCCESS** | The number of <br><br> bytes of information about the active instances of the specified counter set that the function stored in the buffer that *pInstances* specified. |
| **ERROR_NOT_ENOUGH_MEMORY** | The <br><br> size of the buffer required to store the information about the active instances of the counter set on the specified machine, in bytes. Enlarge the buffer to the required <br><br> size and call the function again. |
| Other | The value is undefined and should not be used. |

## Return value

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function successfully stored all of the information about the active instances of the counter set in the buffer that *pInstances* specified. The value that *pcbInstancesActual* points to indicates amount of information actually stored in the buffer, in bytes. |
| **ERROR_NOT_ENOUGH_MEMORY** | The buffer that *pInstances* specified was not large enough to store all of the information about the active instances of the counter set. The value that *pcbInstancesActual* points to indicates the size of the buffer required to store all of the information. Enlarge the buffer to the required <br><br> size and call the function again. |

For other types of failures, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The information about the active instances of the specified counter set is written to the buffer that *pInstances* specifies as a sequence of [PERF_INSTANCE_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_instance_header) blocks. The size in bytes of

the sequence of blocks is written to *pcbInstancesActual*. Each **PERF_INSTANCE_HEADER** block consists

of a **PERF_INSTANCE_HEADER** structure, immediately followed by a null-terminated UTF-16LE

instance name, followed by padding so that the size of the

**PERF_INSTANCE_HEADER** block is a multiple of 8 bytes.

## See also

[PERF_INSTANCE_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_instance_header)

[PerfEnumerateCounterSet](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfenumeratecounterset)