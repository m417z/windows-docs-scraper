# PMIB_SET_TRAP_INFO callback function

## Description

The
*MibSetTrapInfo* function passes in a handle to an event which is signaled whenever a TRAP needs to be issued.

The [PMIP_SET_TRAP_INFO](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-mpr50_routing_characteristics) type defines a pointer to this callback function. *MibSetTrapInfo* is a placeholder for the application-defined function name.

## Parameters

### `Event` [in]

Handle to an event that is signaled when a TRAP needs to be issued.

### `InputDataSize` [in]

Specifies a **ULONG** variable that contains the size in bytes of the data pointed to by *InputData*.

### `InputData` [in]

Pointer to the input data.

### `OutputDataSize` [out]

Pointer to a **ULONG** variable that specifies the size in bytes of the data pointed to by * *OutputData*.

### `OutputData` [out]

Receives the address of a pointer to the output data.

## Return value

If the functions succeeds, the return value is NO_ERROR

If the function fails, the return value is one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient privileges. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |

## See also

[MibGetTrapInfo](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pmib_get_trap_info)