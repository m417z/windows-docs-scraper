## Description

A PSHED plug-in's *FinalizeErrorRecord* callback function adds supplementary error record sections to an error record that more fully describe the error condition.

## Parameters

### `PluginContext` [in, out, optional]

A pointer to the context area that was specified in the **Context** member of the [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure when the PSHED plug-in called the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED.

### `ErrorSource` [in]

A pointer to a [**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor) structure that describes the error source that reported the hardware error.

### `BufferLength` [in]

The size, in bytes, of the buffer pointed to by the *ErrorRecord* parameter.

### `ErrorRecord` [in, out]

A pointer to a [**WHEA_ERROR_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record) structure that describes the error record that is being updated with supplementary error record sections.

## Return value

A PSHED plug-in's *FinalizeErrorRecord* callback function returns one of the following NTSTATUS codes:

| Return code | Description |
|--|--|
| **STATUS_SUCCESS** | The error record was successfully updated with any supplementary error record sections. |
| **STATUS_BUFFER_TOO_SMALL** | The size of the buffer pointed to by the *ErrorRecord* parameter as specified by the *BufferLength* parameter is too small to contain the error record if it is updated with the supplementary error record sections. |
| **STATUS_NOT_SUPPORTED** | The PSHED plug-in does not support the specified error source. |
| **STATUS_UNSUCCESSFUL** | An error occurred. |

## Remarks

A PSHED plug-in that participates in error information retrieval sets the **Callbacks.RetrieveErrorInfo**, **Callbacks.FinalizeErrorRecord**, and **Callbacks.ClearErrorStatus** members of the [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure to point to its [RetrieveErrorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_retrieve_error_info), *FinalizeErrorRecord*, and [ClearErrorStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_clear_error_status) callback functions when the plug-in calls the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED. The PSHED plug-in must also set the **PshedFAErrorInfoRetrieval** flag in the **FunctionalAreaMask** member of the **WHEA_PSHED_PLUGIN_REGISTRATION_PACKET** structure.

The Windows kernel calls into the PSHED so that it can add supplementary error record sections to an error record. If a PSHED plug-in is registered to participate in error information retrieval, the PSHED calls the PSHED plug-in's *FinalizeErrorRecord* callback function so that the PSHED plug-in can add any additional error record sections to the error record that more fully describe the error condition.

A PSHED plug-in must ensure that it does not add supplementary error record sections beyond the end of the error record. The amount of memory that the Windows kernel allocates for a buffer to contain a particular error record is calculated from the **MaxRawDataLength** and **MaxSectionsPerRecord** members of the [**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor) structure that describes the error source that reported the hardware error. If a PSHED plug-in requires additional buffer space to contain the supplementary error record sections that it adds to the error record, it must participate in error source discovery and increase the value in the **MaxSectionsPerRecord** member of the **WHEA_ERROR_SOURCE_DESCRIPTOR** structure for each error source as appropriate to account for any supplementary error record sections.

## See also

[ClearErrorStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_clear_error_status)

[PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin)

[RetrieveErrorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_retrieve_error_info)

[**WHEA_ERROR_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record)

[**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor)

[**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet)