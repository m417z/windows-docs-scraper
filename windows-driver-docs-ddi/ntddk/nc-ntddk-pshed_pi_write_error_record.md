## Description

A PSHED plug-in's *WriteErrorRecord* callback function writes an error record to the system's persistent data storage.

## Parameters

### `PluginContext` [in, out, optional]

A pointer to the context area that was specified in the **Context** member of the [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure when the PSHED plug-in called the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED.

### `Flags` [in]

A bit-wise OR'ed combination of flags that affect the write operation. A possible flag is:

#### WHEA_WRITE_FLAG_DUMMY

The write operation is a dummy write operation. No data is to be written to the system's persistent data storage.

### `RecordLength` [in]

The size, in bytes, of the error record pointed to by the *ErrorRecord* parameter.

### `ErrorRecord` [in]

A pointer to a [**WHEA_ERROR_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record) structure that describes the error record that is being written to the system's persistent data storage.

## Return value

A PSHED plug-in's *WriteErrorRecord* callback function returns one of the following NTSTATUS codes:

| Return code | Description |
|--|--|
| **STATUS_SUCCESS** | The error record was successfully written to the system's persistent data storage. |
| **STATUS_UNSUCCESSFUL** | An error occurred. |

## Remarks

A PSHED plug-in that participates in error record persistence sets the **Callbacks.WriteErrorRecord**, **Callbacks.ReadErrorRecord** and **Callbacks.ClearErrorRecord** members of the [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure to point to its *WriteErrorRecord*, [ReadErrorRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_read_error_record), and [ClearErrorRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_clear_error_record) callback functions when the plug-in calls the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED. The PSHED plug-in must also set the **PshedFAErrorRecordPersistence** flag in the **FunctionalAreaMask** member of the **WHEA_PSHED_PLUGIN_REGISTRATION_PACKET** structure.

The Windows kernel calls into the PSHED to write an error record to the system's persistent data storage whenever a fatal or otherwise unrecoverable error condition exists so that the error record is preserved while the system is restarted. If a PSHED plug-in is registered to participate in error record persistence, the PSHED calls the PSHED plug-in's *WriteErrorRecord* callback function to perform the write operation. The mechanism that is used to write the error record to the system's persistent data storage is platform-specific.

## See also

[ClearErrorRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_clear_error_record)

[PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin)

[ReadErrorRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_read_error_record)

[**WHEA_ERROR_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record)

[**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet)