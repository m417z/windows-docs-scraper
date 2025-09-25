# _SID_IDENTIFIER_AUTHORITY structure

## Description

The SID_IDENTIFIER_AUTHORITY structure represents the top-level authority of a security identifier (SID).

## Members

### `Value`

An array of six bytes specifying a SID's top-level authority.

## Remarks

The identifier authority value identifies the agency that issued the SID. The following identifier authorities are predefined.

| Identifier Authority | Value |
| --- | --- |
| SECURITY_NULL_SID_AUTHORITY | 0 |
| SECURITY_WORLD_SID_AUTHORITY | 1 |
| SECURITY_LOCAL_SID_AUTHORITY | 2 |
| SECURITY_CREATOR_SID_AUTHORITY | 3 |
| SECURITY_NON_UNIQUE_AUTHORITY | 4 |
| SECURITY_NT_AUTHORITY | 5 |

## See also

[RtlInitializeSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinitializesid)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)