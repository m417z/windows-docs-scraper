# SeQueryAuthenticationIdToken function

## Description

The **SeQueryAuthenticationIdToken** routine retrieves the authentication ID of an access token.

## Parameters

### `Token` [in]

Pointer to an access token.

### `AuthenticationId` [out]

Authentication ID of the access token. (An Authentication ID is the locally unique identifier, or [LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid), that is assigned to the logon session that the access token represents. There can be many tokens representing a single logon session.)

## Return value

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The call to **SeQueryAuthenticationIdToken** succeeded. |

## Remarks

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[PsDereferenceImpersonationToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psdereferenceimpersonationtoken)

[PsDereferencePrimaryToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psdereferenceprimarytoken)

[SeQueryInformationToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken)

[SeQuerySubjectContextToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequerysubjectcontexttoken)

[SeTokenIsAdmin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-setokenisadmin)

[SeTokenIsRestricted](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-setokenisrestricted)