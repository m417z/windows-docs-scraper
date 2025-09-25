## Description

A PSHED plug-in's *RetrieveErrorInfo* callback function retrieves platform-specific error information about a hardware error that has occurred.

## Parameters

### `PluginContext` [in, out, optional]

A pointer to the context area that was specified in the **Context** member of the [WHEA_PSHED_PLUGIN_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure when the PSHED plug-in called the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED.

### `ErrorSource` [in]

A pointer to a [WHEA_ERROR_SOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor) structure that describes the error source that reported the hardware error.

### `BufferLength` [in]

The size, in bytes, of the buffer pointed to by the *Packet* parameter.

### `Packet` [in, out]

A pointer to a [**WHEA_ERROR_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_packet_v2) structure that describes the hardware error packet for the hardware error.

## Return value

A PSHED plug-in's *RetrieveErrorInfo* callback function returns one of the following NTSTATUS codes:

| Return code | Description |
|---|---|
| **STATUS_SUCCESS** | The hardware error packet was successfully updated with any platform-specific error information. |
| **STATUS_BUFFER_TOO_SMALL** | The size of the buffer pointed to by the *Packet* parameter as specified by the *BufferLength* parameter is too small to contain the hardware error packet if it is updated with the platform-specific error information. |
| **STATUS_NOT_SUPPORTED** | The PSHED plug-in does not support the specified error source. |
| **STATUS_UNSUCCESSFUL** | An error occurred. |

## Remarks

A PSHED plug-in that participates in error information retrieval sets the **Callbacks.RetrieveErrorInfo**, **Callbacks.FinalizeErrorRecord**, and **Callbacks.ClearErrorStatus** members of the [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure to point to its *RetrieveErrorInfo*, [FinalizeErrorRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_finalize_error_record), and [ClearErrorStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_clear_error_status) callback functions when the plug-in calls the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED. The PSHED plug-in must also set the **PshedFAErrorInfoRetrieval** flag in the **FunctionalAreaMask** member of the WHEA_PSHED_PLUGIN_REGISTRATION_PACKET structure.

Each low-level hardware error handler (LLHEH) calls into the PSHED to retrieve any platform-specific error information about a hardware error that has occurred. If a PSHED plug-in is registered to participate in error information retrieval, the PSHED calls the PSHED plug-in's *RetrieveErrorInfo* callback function so that it can update the hardware error packet with any platform-specific error information. The PSHED plug-in can modify the existing contents of the hardware error packet as well as add supplementary information to the hardware error packet. Supplementary information is added to a hardware error packet beginning at the offset specified by the **RawDataOffset** member of the [**WHEA_ERROR_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_packet_v2) structure.

A PSHED plug-in must ensure that it does not add supplementary information beyond the end of the hardware error packet. The amount of memory that an LLHEH allocates for a buffer to contain a particular hardware error packet is calculated from the **MaxRawDataLength** member of the [**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor) structure that describes the error source. If a PSHED plug-in requires additional buffer space to contain the supplementary information, it must participate in error source discovery and increase the value in the **MaxRawDataLength** member of the **WHEA_ERROR_SOURCE_DESCRIPTOR** structure for each error source as appropriate to account for any supplemental information.

For all error sources, the PSHED plug-in's *RetrieveErrorInfo* callback function is called at a minimum IRQL of DISPATCH_LEVEL. The PSHED plug-in's *RetrieveErrorInfo* callback function must only perform operations and make calls to other functions that are permitted at that high IRQL level.

An important task of a PSHED plug-in's *RetrieveErrorInfo* callback function is to ensure that the severity of the error condition as specified by the **ErrorSeverity** member of the [**WHEA_ERROR_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_packet_v2) is appropriate. For example, if the severity level of the error condition is reported as **WheaErrSevFatal** by the LLHEH but the PSHED plug-in supports a recovery mechanism for the particular error condition that was reported, the PSHED plug-in can change the severity level to **WheaErrSevRecoverable** so that the operating system will attempt recovery from the error. Similarly, if the severity level of the error condition is reported as **WheaErrSevRecoverable** by the LLHEH but the PSHED plug-in recognizes that attempting recovery of the particular error condition that was reported would only cause further problems, the PSHED plug-in can change the severity level to **WheaErrSevFatal** so that the operating system will not attempt recovery from the error.

For corrected hardware errors, a PSHED plug-in must retrieve all of the error status information that it requires for processing the error condition from within its *RetrieveErrorInfo* callback function, as the remainder of the processing of the hardware error is not guaranteed to be synchronized with the LLHEH.

## See also

[ClearErrorStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_clear_error_status)

[FinalizeErrorRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_finalize_error_record)

[PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin)

[**WHEA_ERROR_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_packet_v2)

[**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor)

[**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet)