# WINBIO_STORAGE_INTERFACE structure

## Description

The **WINBIO_STORAGE_INTERFACE** structure contains pointers to your custom storage adapter functions. The Windows Biometric Framework uses this structure to locate the functions.

## Members

### `Version`

Version number of this structure.

**Windows 10:** The version number must be **WINBIO_STORAGE_INTERFACE_VERSION_3**.

**Windows Server 2012 R2, Windows 8.1, Windows Server 2012 and Windows 8:** The version number must be **WINBIO_STORAGE_INTERFACE_VERSION_2**.

**Windows Server 2008 R2 and Windows 7:** The version number must be **WINBIO_STORAGE_INTERFACE_VERSION_1**.

### `Type`

The type of adapter. This must be **WINBIO_ADAPTER_TYPE_STORAGE**.

### `Size`

The size, in bytes, of this structure. Set this value to the size of the **WINBIO_STORAGE_INTERFACE** structure.

### `AdapterId`

A GUID that uniquely identifies the storage adapter. You must generate this value.

### `Attach`

A pointer to your implementation of the [StorageAdapterAttach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_attach_fn) function.

### `Detach`

A pointer to your implementation of the [StorageAdapterDetach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_detach_fn) function.

### `ClearContext`

A pointer to your implementation of the [StorageAdapterClearContext](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_clear_context_fn) function.

### `CreateDatabase`

A pointer to your implementation of the [StorageAdapterCreateDatabase](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_create_database_fn) function.

### `EraseDatabase`

A pointer to your implementation of the [StorageAdapterEraseDatabase](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_erase_database_fn) function.

### `OpenDatabase`

A pointer to your implementation of the [StorageAdapterOpenDatabase](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_open_database_fn) function.

### `CloseDatabase`

A pointer to your implementation of the [StorageAdapterCloseDatabase](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_close_database_fn) function.

### `GetDataFormat`

A pointer to your implementation of the [StorageAdapterGetDataFormat](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_get_data_format_fn) function.

### `GetDatabaseSize`

A pointer to your implementation of the [StorageAdapterGetDatabaseSize](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_get_database_size_fn) function.

### `AddRecord`

A pointer to your implementation of the [StorageAdapterAddRecord](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_add_record_fn) function.

### `DeleteRecord`

A pointer to your implementation of the [StorageAdapterDeleteRecord](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_delete_record_fn) function.

### `QueryBySubject`

A pointer to your implementation of the [StorageAdapterQueryBySubject](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_query_by_subject_fn) function.

### `QueryByContent`

A pointer to your implementation of the [StorageAdapterQueryByContent](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_query_by_content_fn) function.

### `GetRecordCount`

A pointer to your implementation of the [StorageAdapterGetRecordCount](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_get_record_count_fn) function.

### `FirstRecord`

A pointer to your implementation of the [StorageAdapterFirstRecord](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_first_record_fn) function.

### `NextRecord`

A pointer to your implementation of the [StorageAdapterNextRecord](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_next_record_fn) function.

### `GetCurrentRecord`

A pointer to your implementation of the [StorageAdapterGetCurrentRecord](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_get_current_record_fn) function.

### `ControlUnit`

A pointer to your implementation of the [StorageAdapterControlUnit](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_control_unit_fn) function.

### `ControlUnitPrivileged`

A pointer to your implementation of the [StorageAdapterControlUnitPrivileged](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_control_unit_privileged_fn) function.

### `NotifyPowerChange`

A pointer to your implementation of the [StorageAdapterNotifyPowerChange](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_notify_power_change_fn) function. This member is supported starting in Windows 8.

### `PipelineInit`

A pointer to your implementation of the [StorageAdapterPipelineInit](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_pipeline_init_fn) function. This member is supported starting in Windows 10.

### `PipelineCleanup`

A pointer to your implementation of the [StorageAdapterPipelineCleanup](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_pipeline_cleanup_fn) function. This member is supported starting in Windows 10.

### `Activate`

A pointer to your implementation of the [StorageAdapterActivate](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_activate_fn) function. This member is supported starting in Windows 10.

### `Deactivate`

A pointer to your implementation of the [StorageAdapterDeactivate](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_deactivate_fn) function. This member is supported starting in Windows 10.

### `QueryExtendedInfo`

A pointer to your implementation of the [StorageAdapterQueryExtendedInfo](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_query_extended_info_fn) function. This member is supported starting in Windows 10.

### `NotifyDatabaseChange`

### `Reserved1`

### `Reserved2`

### `UpdateRecordBegin`

### `UpdateRecordCommit`

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[Plug-in Structures](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-structures)

[WbioQueryStorageInterface](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nf-winbio_adapter-wbioquerystorageinterface)