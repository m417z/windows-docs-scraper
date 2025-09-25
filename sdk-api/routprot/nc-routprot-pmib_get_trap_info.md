# PMIB_GET_TRAP_INFO callback function

## Description

The **MibGetTrapInfo** function queries the module that set a trap event for more information about the trap.

The [PMIB_GET_TRAP_INFO](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-mpr50_routing_characteristics) type defines a pointer to this callback function. *MibGetTrapInfo* is a placeholder for the application-defined function name.

## Parameters

### `InputDataSize` [in]

Specifies a **ULONG** variable that specifies the size in bytes of the data pointed to by *InputData*.

### `InputData` [in]

Pointer to the input data.

### `OutputDataSize` [out]

Pointer to a **ULONG** variable that receives the size in bytes of the data pointed to by * *OutputData*.

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

[MibSetTrapInfo](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pmib_set_trap_info)