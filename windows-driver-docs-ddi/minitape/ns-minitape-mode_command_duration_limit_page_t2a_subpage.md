## Description

The **MODE_COMMAND_DURATION_LIMIT_PAGE_T2A_SUBPAGE** structure describes the Command Duration Limit T2A mode page, described in Section 7.5.11 of the T10 SCSI Primary Commands specification (SPC-6).

## Members

### `PageCode`

Described in the specification.

### `SubPageFormat`

Described in the specification.

### `PageSavable`

Described in the specification.

### `SubPageCode`

Described in the specification.

### `PageLength[2]`

Described in the specification.

### `Reserved[3]`

Reserved.

### `Reserved1`

Reserved.

### `PerfvsCommandDurationGuidelines`

Described in the specification.

### `T2CommandDurationLimitDescriptors[DURATION_LIMIT_T2_DESCRIPTOR_COUNT]`

An array of **DURATION_LIMIT_T2_DESCRIPTOR_COUNT** **[T2_COMMAND_DURATION_LIMIT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-t2_command_duration_limit_descriptor)** structures, where each structure contains a T2 command duration limit descriptor.

## Remarks

See Section 7.5.11 of the T10 SCSI Primary Commands specification (SPC-6) for details.

## See also

- **[MODE_COMMAND_DURATION_LIMIT_PAGE_T2B_SUBPAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-mode_command_duration_limit_page_t2b_subpage)**
- **[MODE_PAGE_SUBPAGE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-mode_page_subpage_header)**