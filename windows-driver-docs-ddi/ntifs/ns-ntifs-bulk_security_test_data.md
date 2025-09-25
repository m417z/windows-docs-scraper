## Description

The **BULK_SECURITY_TEST_DATA** structure is used with the [**FSCTL_SECURITY_ID_CHECK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_security_id_check) control code to verify security identifiers (SIDs) against specified access rights in bulk.

## Members

### `DesiredAccess`

An [**ACCESS_MASK**](https://learn.microsoft.com/windows/win32/secauthz/access-mask) value that specifies the access rights to be checked against the provided security identifiers. This mask defines the permissions required for the operation.

### `SecurityIds[1]`

An array of security identifiers (SIDs) to be tested.

## See also

[**FSCTL_SECURITY_ID_CHECK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_security_id_check)

[**ACCESS_MASK**](https://learn.microsoft.com/windows/win32/secauthz/access-mask)