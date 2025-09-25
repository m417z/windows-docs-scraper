## Description

A PSHED plug-in's *ClearErrorStatus* callback function clears any platform-specific error status registers for a corrected hardware error condition.

## Parameters

### `PluginContext` [in, out, optional]

A pointer to the context area that was specified in the **Context** member of the [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure when the PSHED plug-in called the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED.

### `ErrorSource` [in]

A pointer to a [**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor) structure that describes the error source that reported the hardware error.

### `BufferLength` [in]

The size, in bytes, of the buffer pointed to by the *ErrorRecord* parameter.

### `ErrorRecord` [in]

A pointer to a [**WHEA_ERROR_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record) structure that describes an error record. The error record describes the corrected hardware error condition for which the platform-specific error status registers are being cleared.

## Return value

A PSHED plug-in's *ClearErrorStatus* callback function returns one of the following NTSTATUS codes:

| Return code | Description |
|--|--|
| **STATUS_SUCCESS** | The platform-specific error status registers for the corrected hardware error condition were successfully cleared. |
| **STATUS_NOT_SUPPORTED** | The PSHED plug-in does not support the specified error source. |
| **STATUS_UNSUCCESSFUL** | An error occurred. |

## Remarks

A PSHED plug-in that participates in error information retrieval sets the **Callbacks.RetrieveErrorInfo**, **Callbacks.FinalizeErrorRecord**, and **Callbacks.ClearErrorStatus** members of the [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure to point to its [RetrieveErrorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_retrieve_error_info), [FinalizeErrorRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_finalize_error_record), and *ClearErrorStatus* callback functions when the plug-in calls the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED. The PSHED plug-in must also set the **PshedFAErrorInfoRetrieval** flag in the **FunctionalAreaMask** member of the WHEA_PSHED_PLUGIN_REGISTRATION_PACKET structure.

For corrected hardware error conditions, the Windows kernel calls into the PSHED to clear the error source's error status registers as the final step of processing the error. If a PSHED plug-in is registered to participate in error information retrieval, the PSHED calls the PSHED plug-in's *ClearErrorStatus* callback function so that the PSHED plug-in can clear any additional platform-specific error status registers.

## See also

[FinalizeErrorRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_finalize_error_record)

[PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin)

[RetrieveErrorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_retrieve_error_info)

[**WHEA_ERROR_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record)

[**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor)

[**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet)