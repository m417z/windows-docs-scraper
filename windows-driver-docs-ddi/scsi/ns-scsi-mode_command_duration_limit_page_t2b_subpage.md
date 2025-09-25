## Description

The **MODE_COMMAND_DURATION_LIMIT_PAGE_T2B_SUBPAGE** structure describes the Command Duration Limit T2B mode page, described in Section 7.5.12 of the T10 SCSI Primary Commands specification (SPC-6).

## Members

### `PageCode`

Described in the specification.

### `SubPageFormat`

Described in the specification.

### `PageSavable`

Described in the specification.

### `SubPageCode`

Described in the specification.

### `PageLength`

Described in the specification.

### `Reserved`

Reserved.

### `Reserved1`

Reserved.

### `PerfvsLatencyControls`

Described in the specification.

### `T2CommandDurationLimitDescriptors`

An array of **DURATION_LIMIT_T2_DESCRIPTOR_COUNT** [**T2_COMMAND_DURATION_LIMIT_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-t2_command_duration_limit_descriptor) structures, where each structure contains a T2 command duration limit descriptor.

## Remarks

See Section 7.5.12 of the T10 SCSI Primary Commands specification (SPC-6) for details.

## See also

[**MODE_COMMAND_DURATION_LIMIT_PAGE_T2A_SUBPAGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-mode_command_duration_limit_page_t2a_subpage)

[**MODE_PAGE_SUBPAGE_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-mode_page_subpage_header)