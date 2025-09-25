# SID structure

## Description

The security identifier (SID) structure is a variable-length structure used to uniquely identify users or groups.

Drivers must not modify the SID structure directly. To create and manipulate a security identifier, use the support routines listed in the See Also section.

## Members

### `Revision`

The revision level assigned to the SID.

### `SubAuthorityCount`

Number of subauthorities in the SID.

### `IdentifierAuthority`

A [**SID_IDENTIFIER_AUTHORITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid_identifier_authority) structure that represents the top-level authority of the SID.

### `SubAuthority[*]`

The subauthority of the SID.

### `SubAuthority[ANYSIZE_ARRAY]`

The subauthority of the SID.

## See also

[**RtlCopySid**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcopysid)

[**RtlEqualPrefixSid**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlequalprefixsid)

[**RtlEqualSid**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlequalsid)

[**RtlGetOwnerSecurityDescriptor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetownersecuritydescriptor)

[**RtlInitializeSid**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinitializesid)

[**RtlLengthSid**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtllengthsid)

[**RtlSetOwnerSecurityDescriptor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsetownersecuritydescriptor)

[**RtlSubAuthoritySid**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsubauthoritysid)

[**RtlValidSid**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlvalidsid)

[**SID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid_and_attributes)

[**SID_IDENTIFIER_AUTHORITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid_identifier_authority)