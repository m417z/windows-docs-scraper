# _STORAGE_DIAGNOSTIC_MP_REQUEST structure

## Description

Describes a diagnostic request to Miniport. The **STORAGE_DIAGNOSTIC_MP_REQUEST** structure is provided in the input/output buffer of an [IOCTL_SCSI_MINIPORT_DIAGNOSTIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport_diagnostic) request.

## Members

### `Version`

Version of this structure.

### `Size`

Specifies the whole size of the structure and the associated data buffer.

### `TargetType`

Specifies the request target type. See definitions for [STORAGE_DIAGNOSTIC_TARGET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_diagnostic_target_type).

### `Level`

Specifies the Diagnostic level. See definitions for [STORAGE_DIAGNOSTIC_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_diagnostic_level).

### `ProviderId`

Specifies the GUID of the diagnostic data provider.

### `BufferSize`

Specifies the Data buffer size. As an input buffer, *BufferSize* should be set to number of bytes allocated for the *DataBuffer*. If the request is failed because of buffer too short, *BufferSize* should be set to the
length required for *DataBuffer* by the diagnostic data provider;
If the request is successful, it should be filled with returned data size of *DataBuffer*. For other cases, it should be cleared to 0.

### `Reserved`

Reserved for future use.

### `DataBuffer`

Specifies the Diagnostic data buffer.

## See also

[IOCTL_SCSI_MINIPORT_DIAGNOSTIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport_diagnostic)

[STORAGE_DIAGNOSTIC_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_diagnostic_data)

[STORAGE_DIAGNOSTIC_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_diagnostic_level)

[STORAGE_DIAGNOSTIC_TARGET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_diagnostic_target_type)