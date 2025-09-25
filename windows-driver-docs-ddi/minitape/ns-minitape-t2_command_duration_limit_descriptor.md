## Description

The **T2_COMMAND_DURATION_LIMIT_DESCRIPTOR** structure describes the command duration limit (CDL) information that corresponds to one **T2CommandDurationLimitDescriptors** index in a [**MODE_COMMAND_DURATION_LIMIT_PAGE_T2A_SUBPAGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-mode_command_duration_limit_page_t2a_subpage) and [**MODE_COMMAND_DURATION_LIMIT_PAGE_T2B_SUBPAGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-mode_command_duration_limit_page_t2b_subpage) structure. See Table 459 (T2 Command Duration Limit Descriptor format) in the T10 SCSI Primary Commands specification (SPC-6) for details.

## Members

### `T2CDLUNITS`

Described in the specification.

### `Reserved`

Reserved.

### `Reserved1`

Reserved.

### `MAX_INACTIVE_TIME`

Described in the specification.

### `MAX_ACTIVE_TIME`

Described in the specification.

### `MAX_ACTIVE_TIME_POLICY`

Described in the specification.

### `MAX_INACTIVE_TIME_POLICY`

Described in the specification.

### `Reserved2`

Reserved.

### `COMMAND_DURATION_GUIDELINE`

Described in the specification.

### `Reserved3`

Reserved.

### `COMMAND_DURATION_GUIDELINE_POLICY`

Described in the specification.

### `Reserved4`

Reserved.

### `BypassSequestration`

Described in the specification.

### `Reserved5`

Reserved.

### `Reserved6`

Reserved.

## Remarks

See Table 459 in Section 7.5.11.2 of the T10 SCSI Primary Commands specification (SPC-6) for details.

## See also

[**MODE_COMMAND_DURATION_LIMIT_PAGE_T2A_SUBPAGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-mode_command_duration_limit_page_t2a_subpage)

[**MODE_COMMAND_DURATION_LIMIT_PAGE_T2B_SUBPAGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-mode_command_duration_limit_page_t2b_subpage)