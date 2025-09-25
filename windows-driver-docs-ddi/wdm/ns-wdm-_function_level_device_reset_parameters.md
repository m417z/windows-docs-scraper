# _FUNCTION_LEVEL_DEVICE_RESET_PARAMETERS structure

## Description

The **FUNCTION_LEVEL_DEVICE_RESET_PARAMETER** structure is used as an argument to the [DeviceReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-device_reset_handler) routine of the GUID_DEVICE_RESET_INTERFACE_STANDARD interface. This structure specifies a callback routine that is called when a function-level device reset is completed, and a context structure that is passed to the callback routine. For more information, see [Working with the GUID_DEVICE_RESET_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/kernel/working-with-guid-device-reset-interface-standard)

## Members

### `Size`

The size, in bytes, of this structure.

### `DeviceResetCompletion`

Pointer to a completion callback routine to be called when a function-level device reset is completed. The callback must enter and exit at the same IRQL.

The function prototype for this callback routine is defined as follows:

```cpp
typedef
VOID
(*PDEVICE_RESET_COMPLETION)(
    _In_ NTSTATUS Status,
    _Inout_opt_ PVOID Context
    );
```

### `CompletionContext`

Points to a caller-supplied context structure to be passed to the *DeviceResetCompletion* callback.

## See also

[DEVICE_RESET_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_reset_interface_standard)

[DeviceReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-device_reset_handler)

[Working with the GUID_DEVICE_RESET_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/kernel/working-with-guid-device-reset-interface-standard)