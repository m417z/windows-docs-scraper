## Description

Attempts to find input mapping IDs which are valid for the given device and populate the provided buffer with those IDs.

## Parameters

### `PhysicalDeviceObject` [_In_]

A pointer to the physical device object (PDO) in the device stack.

### `Buffer` [_Inout_]

A pointer to the buffer of the type [**INPUT_MAPPING_ELEMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_input_mapping_element) that is populated with the input mapping IDs.

### `BufferLength` [_In_]

The length of the buffer pointed to by _Buffer_.

### `ReturnLength:` [_Out_opt]

Optional. A pointer to store the amount of data written (or data that would be written if a buffer of sufficient size was provided).

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values). Possible values include:

| Error code | Description |
|---|---|
| STATUS_BUFFER_TOO_SMALL | The provided buffer is of insufficient size. |
| STATUS_UNSUCCESSFUL | The request cannot be satisfied. |
| STATUS_SUCCESS | The buffer has been populated correctly. |

## Remarks

If the buffer is of insufficient length, no IDs will be written and ReturnLength (if provided) will be populated with the required buffer size.

This routine is currently only supported on ARM64 systems.

## See also