# _REG_QUERY_MULTIPLE_VALUE_KEY_INFORMATION structure

## Description

The **REG_QUERY_MULTIPLE_VALUE_KEY_INFORMATION** structure describes the multiple value entries that are being retrieved for a key.

## Members

### `Object`

A pointer to the registry key object for the key whose value entries are being retrieved.

### `ValueEntries`

A pointer to an array of [KEY_VALUE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_entry) structures, one for each value entry that is retrieved.

### `EntryCount`

The number of entries in the **ValueEntries** array.

### `ValueBuffer`

A pointer to a buffer that receives (from the system) the data for all the value entries specified by the **ValueEntries** array.

### `BufferLength`

A pointer to a variable that contains the length, in bytes, of the **ValueBuffer** buffer.

### `RequiredBufferLength`

A pointer to a variable that receives (from the system) the number of bytes required to hold the data for all the value entries that the **ValueEntries** array specifies. This member can be **NULL**.

### `CallContext`

Optional driver-defined context information that the driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can supply. This member is defined for Windows Vista and later versions of the Windows operating system.

### `ObjectContext`

A pointer to driver-defined context information that the driver has associated with a registry object by calling [CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext). This member is defined for Windows Vista and later versions of the Windows operating system.

### `Reserved`

This member is reserved for future use. This member is defined for Windows Vista and later versions of the Windows operating system.

## Remarks

The system passes this structure to the [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine every time a thread attempts to retrieve multiple value entries for a key at once—for example, when a user-mode thread calls **RegQueryMultipleValues**.

Each [KEY_VALUE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_entry) structure in the **ValueEntries** array describes one value entry in the **ValueBuffer** buffer. Specifically, the **DataOffset** member of **KEY_VALUE_ENTRY** contains the offset within **ValueBuffer** where the data for that value entry begins, and the **DataLength** member contains the length, in bytes, of the data for that value entry.

For more information about registry filtering operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext)

[KEY_VALUE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_entry)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)