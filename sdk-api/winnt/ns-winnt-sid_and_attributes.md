# SID_AND_ATTRIBUTES structure

## Description

The **SID_AND_ATTRIBUTES** structure represents a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) and its attributes. SIDs are used to uniquely identify users or groups.

## Members

### `Sid`

A pointer to a [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure.

### `Attributes`

Specifies attributes of the SID. This value contains up to 32 one-bit flags. Its meaning depends on the definition and use of the SID.

## Remarks

A group is represented by a SID. SIDs have attributes that indicate whether they are currently enabled, disabled, or mandatory. SIDs also indicate how these attributes are used. A **SID_AND_ATTRIBUTES** structure can represent a SID whose attributes change frequently. For example, **SID_AND_ATTRIBUTES** is used to represent groups in the [TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure.

## See also

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups)

[TOKEN_USER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_user)