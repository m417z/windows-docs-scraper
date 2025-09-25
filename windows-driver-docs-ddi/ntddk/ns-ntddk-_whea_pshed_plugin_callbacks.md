# _WHEA_PSHED_PLUGIN_CALLBACKS structure

## Description

The WHEA_PSHED_PLUGIN_CALLBACKS structure describes the callback functions for a PSHED plug-in.

## Members

### `GetAllErrorSources`

A pointer to the PSHED plug-in's [GetAllErrorSources](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_get_all_error_sources) callback function. If a PSHED plug-in does not participate in error source discovery, this member should be set to **NULL**.

### `Reserved`

Reserved for system use. This member should be set to **NULL**.

### `GetErrorSourceInfo`

A pointer to the PSHED plug-in's [GetErrorSourceInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_get_error_source_info) callback function. If a PSHED plug-in does not participate in error source discovery, this member should be set to **NULL**.

### `SetErrorSourceInfo`

A pointer to the PSHED plug-in's [SetErrorSourceInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_set_error_source_info) callback function. If a PSHED plug-in does not participate in error source control, this member should be set to **NULL**.

### `EnableErrorSource`

A pointer to the PSHED plug-in's [EnableErrorSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_enable_error_source) callback function. If a PSHED plug-in does not participate in error source control, this member should be set to **NULL**.

### `DisableErrorSource`

A pointer to the PSHED plug-in's [DisableErrorSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_disable_error_source) callback function. If a PSHED plug-in does not participate in error source control, this member should be set to **NULL**.

### `WriteErrorRecord`

A pointer to the PSHED plug-in's [WriteErrorRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_write_error_record) callback function. If a PSHED plug-in does not participate in error record persistence, this member should be set to **NULL**.

### `ReadErrorRecord`

A pointer to the PSHED plug-in's [ReadErrorRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_read_error_record) callback function. If a PSHED plug-in does not participate in error record persistence, this member should be set to **NULL**.

### `ClearErrorRecord`

A pointer to the PSHED plug-in's [ClearErrorRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_clear_error_record) callback function. If a PSHED plug-in does not participate in error record persistence, this member should be set to **NULL**.

### `RetrieveErrorInfo`

A pointer to the PSHED plug-in's [RetrieveErrorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_retrieve_error_info) callback function. If a PSHED plug-in does not participate in error information retrieval, this member should be set to **NULL**.

### `FinalizeErrorRecord`

A pointer to the PSHED plug-in's [FinalizeErrorRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_finalize_error_record) callback function. If a PSHED plug-in does not participate in error information retrieval, this member should be set to **NULL**.

### `ClearErrorStatus`

A pointer to the PSHED plug-in's [ClearErrorStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_clear_error_status) callback function. If a PSHED plug-in does not participate in error information retrieval, this member should be set to **NULL**.

### `AttemptRecovery`

A pointer to the PSHED plug-in's [AttemptRecovery](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_attempt_error_recovery) callback function. If a PSHED plug-in does not participate in error recovery, this member should be set to **NULL**.

### `GetInjectionCapabilities`

A pointer to the PSHED plug-in's [GetInjectionCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_get_injection_capabilities) callback function. If a PSHED plug-in does not participate in error injection, this member should be set to **NULL**.

### `InjectError`

A pointer to the PSHED plug-in's [InjectError](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_inject_error) callback function. If a PSHED plug-in does not participate in error injection, this member should be set to **NULL**.

## Remarks

A WHEA_PSHED_PLUGIN_CALLBACKS structure is contained within the [WHEA_PSHED_PLUGIN_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure.

## See also

[AttemptRecovery](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_attempt_error_recovery)

[ClearErrorRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_clear_error_record)

[ClearErrorStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_clear_error_status)

[DisableErrorSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_disable_error_source)

[EnableErrorSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_enable_error_source)

[FinalizeErrorRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_finalize_error_record)

[GetAllErrorSources](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_get_all_error_sources)

[GetErrorSourceInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_get_error_source_info)

[GetInjectionCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_get_injection_capabilities)

[InjectError](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_inject_error)

[ReadErrorRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_read_error_record)

[RetrieveErrorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_retrieve_error_info)

[SetErrorSourceInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_set_error_source_info)

[WHEA_PSHED_PLUGIN_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet)

[WriteErrorRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_write_error_record)