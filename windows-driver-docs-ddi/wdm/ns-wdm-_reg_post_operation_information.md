# _REG_POST_OPERATION_INFORMATION structure

## Description

The **REG_POST_OPERATION_INFORMATION** structure contains information about a completed registry operation that a [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can use.

## Members

### `Object`

A pointer to the registry key object for which the operation has completed. This member is valid only if the Status member of the structure is set to STATUS_SUCCESS. For more information, see [Invalid Key Object Pointers in Registry Notifications](https://learn.microsoft.com/windows-hardware/drivers/kernel/invalid-key-object-pointers-in-registry-notifications).

### `Status`

The NTSTATUS-typed value that the system will return for the registry operation.

### `PreInformation`

A pointer to the structure that contains preprocessing information for the registry operation that has completed. For example, if the [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine is processing a **RegNtPostQueryValueKey** operation, the **PreInformation** member points to a [REG_QUERY_VALUE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_query_value_key_information) structure. This member is defined for Windows Vista and later versions of the Windows operating system.

### `ReturnStatus`

A driver-supplied NTSTATUS-typed value. If the driver's *RegistryCallback* routine returns STATUS_CALLBACK_BYPASS, the operating system uses the **ReturnStatus** member's value as the status that it returns to the thread that initiated the registry operation. (In such cases, the operating system also copies the **ReturnStatus** member's value to the **Status** member.) Otherwise, this member is ignored. This member is defined for Windows Vista and later versions of the Windows operating system.

### `CallContext`

Optional driver-defined context information that the driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can supply. This member is defined for Windows Vista and later versions of the Windows operating system.

### `ObjectContext`

A pointer to driver-defined context information that the driver has associated with a registry object by calling [CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext). This member is defined for Windows Vista and later versions of the Windows operating system.

### `Reserved`

This member is reserved for future use. This member is defined for Windows Vista and later versions of the Windows operating system.

## Remarks

For more information about handling post-notifications, see [Handling Notifications](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-notifications).

For more information about registry filtering operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext)

[REG_QUERY_VALUE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_query_value_key_information)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)