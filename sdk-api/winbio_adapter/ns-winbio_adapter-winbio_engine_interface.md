# WINBIO_ENGINE_INTERFACE structure

## Description

The **WINBIO_ENGINE_INTERFACE** structure contains pointers to your custom engine adapter functions. The Windows Biometric Framework uses this structure to locate the functions.

## Members

### `Version`

Version number of this structure.

**Windows 10:** The version number must be **WINBIO_ENGINE_INTERFACE_VERSION_3** or **WINBIO_ENGINE_INTERFACE_VERSION_4**. For more information on implementing **WINBIO_ENGINE_INTERFACE_VERSION_4**, see [Sensor requirements for secure biometrics](https://learn.microsoft.com/windows/desktop/SecBioMet/sensor-requirements-for-secure-biometrics).

**Windows Server 2012 R2, Windows 8.1, Windows Server 2012 and Windows 8:** The version number must be **WINBIO_ENGINE_INTERFACE_VERSION_2**.

**Windows Server 2008 R2 and Windows 7:** The version number must be **WINBIO_ENGINE_INTERFACE_VERSION_1**.

### `Type`

The type of adapter. This must be **WINBIO_ADAPTER_TYPE_ENGINE**.

### `Size`

The size, in bytes, of this structure. Set this value to the size of the **WINBIO_ENGINE_INTERFACE** structure.

### `AdapterId`

A GUID that uniquely identifies the engine adapter. You must generate this value.

### `Attach`

A pointer to your implementation of the [EngineAdapterAttach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_attach_fn) function.

### `Detach`

A pointer to your implementation of the [EngineAdapterDetach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_detach_fn) function.

### `ClearContext`

A pointer to your implementation of the [EngineAdapterClearContext](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_clear_context_fn) function.

### `QueryPreferredFormat`

A pointer to your implementation of the [EngineAdapterQueryPreferredFormat](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_query_preferred_format_fn) function.

### `QueryIndexVectorSize`

A pointer to your implementation of the [EngineAdapterQueryIndexVectorSize](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_query_index_vector_size_fn) function.

### `QueryHashAlgorithms`

A pointer to your implementation of the [EngineAdapterQueryHashAlgorithms](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_query_hash_algorithms_fn) function.

### `SetHashAlgorithm`

A pointer to your implementation of the [EngineAdapterSetHashAlgorithm](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_set_hash_algorithm_fn) function.

### `QuerySampleHint`

A pointer to your implementation of the [EngineAdapterQuerySampleHint](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_query_sample_hint_fn) function.

### `AcceptSampleData`

A pointer to your implementation of the [EngineAdapterAcceptSampleData](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_accept_sample_data_fn) function.

### `ExportEngineData`

A pointer to your implementation of the [EngineAdapterExportEngineData](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_export_engine_data_fn) function.

### `VerifyFeatureSet`

A pointer to your implementation of the [EngineAdapterVerifyFeatureSet](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_verify_feature_set_fn) function.

### `IdentifyFeatureSet`

A pointer to your implementation of the [EngineAdapterIdentifyFeatureSet](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_identify_feature_set_fn) function.

### `CreateEnrollment`

A pointer to your implementation of the [EngineAdapterCreateEnrollment](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_create_enrollment_fn) function.

### `UpdateEnrollment`

A pointer to your implementation of the [EngineAdapterUpdateEnrollment](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_update_enrollment_fn) function.

### `GetEnrollmentStatus`

A pointer to your implementation of the [EngineAdapterGetEnrollmentStatus](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_get_enrollment_status_fn) function.

### `GetEnrollmentHash`

A pointer to your implementation of the [EngineAdapterGetEnrollmentHash](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_get_enrollment_hash_fn) function.

### `CheckForDuplicate`

A pointer to your implementation of the [EngineAdapterCheckForDuplicate](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_check_for_duplicate_fn) function.

### `CommitEnrollment`

A pointer to your implementation of the [EngineAdapterCommitEnrollment](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_commit_enrollment_fn) function.

### `DiscardEnrollment`

A pointer to your implementation of the [EngineAdapterDiscardEnrollment](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_discard_enrollment_fn) function.

### `ControlUnit`

A pointer to your implementation of the [EngineAdapterControlUnit](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_control_unit_fn) function.

### `ControlUnitPrivileged`

A pointer to your implementation of the [EngineAdapterControlUnitPrivileged](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_control_unit_privileged_fn) function.

### `NotifyPowerChange`

A pointer to your implementation of the [EngineAdapterNotifyPowerChange](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_notify_power_change_fn) function. This member is supported starting in Windows 8.

### `Reserved_1`

This field is reserved and should be set to **NULL**.

### `PipelineInit`

A pointer to your implementation of the [EngineAdapterPipelineInit](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_pipeline_init_fn) function. This member is supported starting in Windows 10.

### `PipelineCleanup`

A pointer to your implementation of the [EngineAdapterPipelineCleanup](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_pipeline_cleanup_fn) function. This member is supported starting in Windows 10.

### `Activate`

A pointer to your implementation of the [EngineAdapterActivate](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_activate_fn) function. This member is supported starting in Windows 10.

### `Deactivate`

A pointer to your implementation of the [EngineAdapterDeactivate](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_deactivate_fn) function. This member is supported starting in Windows 10.

### `QueryExtendedInfo`

A pointer to your implementation of the [EngineAdapterQueryExtendedInfo](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_query_extended_info_fn) function. This member is supported starting in Windows 10.

### `IdentifyAll`

A pointer to your implementation of the [EngineAdapterIdentifyAll](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_identify_all_fn) function. This member is supported starting in Windows 10.

### `SetEnrollmentSelector`

A pointer to your implementation of the [EngineAdapterSetEnrollmentSelector](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_set_enrollment_selector_fn) function. This member is supported starting in Windows 10.

### `SetEnrollmentParameters`

A pointer to your implementation of the [EngineAdapterSetEnrollmentParameters](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_set_enrollment_parameters_fn) function. This member is supported starting in Windows 10.

### `QueryExtendedEnrollmentStatus`

A pointer to your implementation of the [EngineAdapterQueryExtendedEnrollmentStatus](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_query_extended_enrollment_status_fn) function. This member is supported starting in Windows 10.

### `RefreshCache`

A pointer to your implementation of the [EngineAdapterRefreshCache](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_refresh_cache_fn) function. This member is supported starting in Windows 10.

### `SelectCalibrationFormat`

A pointer to your implementation of the [EngineAdapterSelectCalibrationFormat](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_select_calibration_format_fn) function. This member is supported starting in Windows 10.

### `QueryCalibrationData`

A pointer to your implementation of the [EngineAdapterQueryCalibrationData](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_query_calibration_data_fn) function. This member is supported starting in Windows 10.

### `SetAccountPolicy`

A pointer to your implementation of the [EngineAdapterSetAccountPolicy](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_set_account_policy_fn) function. This member is supported starting in Windows 10.

### `CreateKey`

A pointer to your implementation of the [EngineAdapterCreateKey](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_create_key_fn) function. This member is supported starting in Windows 10, version 1607.

### `IdentifyFeatureSetSecure`

A pointer to your implementation of the [EngineAdapterIdentifyFeatureSetSecure](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_identify_feature_set_secure_fn) function. This member is supported starting in Windows 10, version 1607.

### `AcceptPrivateSensorTypeInfo`

### `CreateEnrollmentAuthenticated`

### `IdentifyFeatureSetAuthenticated`

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[Plug-in Structures](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-structures)

[WbioQueryEngineInterface](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nf-winbio_adapter-wbioqueryengineinterface)