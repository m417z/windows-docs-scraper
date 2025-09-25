## Description

A PSHED plug-in's *ClearErrorRecord* callback function clears the specified error record from the system's persistent data storage.

## Parameters

### `PluginContext` [in, out, optional]

A pointer to the context area that was specified in the **Context** member of the [WHEA_PSHED_PLUGIN_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure when the PSHED plug-in called the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED.

### `Flags` [in]

A bit-wise OR'ed combination of flags that affect the clear operation. No flags are currently defined.

### `ErrorRecordId` [in]

The identifier of the error record that is being cleared from the system's persistent data storage. This identifier should be compared to the **Header.RecordId** member of each [WHEA_ERROR_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record) structure that has been written to the system's persistent data storage to identify the error record to be cleared.

## Return value

A PSHED plug-in's *ClearErrorRecord* callback function returns one of the following NTSTATUS codes:

| Return code | Description |
|--|--|
| **STATUS_SUCCESS** | The error record was successfully cleared from the system's persistent data storage. |
| **STATUS_UNSUCCESSFUL** | An error occurred. |

## Remarks

A PSHED plug-in that participates in error record persistence sets the **Callbacks.WriteErrorRecord**, **Callbacks.ReadErrorRecord** and **Callbacks.ClearErrorRecord** members of the [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure to point to its [WriteErrorRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_write_error_record), [ReadErrorRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_read_error_record), and *ClearErrorRecord* callback functions when the plug-in calls the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED. The PSHED plug-in must also set the **PshedFAErrorRecordPersistence** flag in the **FunctionalAreaMask** member of the WHEA_PSHED_PLUGIN_REGISTRATION_PACKET structure.

The Windows kernel calls into the PSHED to clear an error record from the system's persistent data storage. If a PSHED plug-in is registered to participate in error record persistence, the PSHED calls the PSHED plug-in's *ClearErrorRecord* callback function to perform the clear operation. The mechanism that is used to clear the error record from the system's persistent data storage is platform-specific.

## See also

[PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin)

[ReadErrorRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_read_error_record)

[**WHEA_ERROR_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record)

[**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet)

[WriteErrorRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_write_error_record)