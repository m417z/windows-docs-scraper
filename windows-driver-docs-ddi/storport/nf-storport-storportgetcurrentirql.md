## Description

**StorPortGetCurrentIrql** retrieves the current interrupt request level (IRQL).

## Parameters

### `HwDeviceExtension` [in]

A pointer to the miniport's device extension.

### `Irql` [out]

Pointer to a KIRQL structure in which the current IRQL will be stored. **Irql** cannot be NULL.

## Return value

This function returns one of the following status codes.

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_SUCCESS | The IRQL was successfully retrieved. |
| STOR_STATUS_INVALID_PARAMETER | **Irql** is a null pointer. |
| STOR_STATUS_UNSUCCESSFUL | Returned for other internal system reasons. |

## Remarks

A miniport can call **StorPortGetCurrentIrql** to query the current IRQL. KIRQL is defined in *miniport.h*. For general information about IRQLs, see [Managing Hardware Priorities](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-hardware-priorities).

## See also