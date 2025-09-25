# _SID_AND_ATTRIBUTES structure

## Description

The SID_AND_ATTRIBUTES structure represents a security identifier (SID) and its attributes. SIDs are used to uniquely identify users or groups.

## Members

### `Sid`

Pointer to a SID structure.

### `Attributes`

Specifies attributes of the SID. This value contains up to 32 one-bit flags. Its meaning depends on the definition and use of the SID.

## Remarks

A group is represented by a SID. SIDs have attributes that indicate whether they are currently enabled, disabled, or mandatory, and how they are used. A **SID_AND_ATTRIBUTES** structure can represent a SID whose attributes change frequently. For example, it is used to represent groups in the [TOKEN_GROUPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_groups) structure.

## See also

[ACE](https://learn.microsoft.com/windows-hardware/drivers/ifs/ace)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[SeFilterToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sefiltertoken)

[TOKEN_GROUPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_groups)