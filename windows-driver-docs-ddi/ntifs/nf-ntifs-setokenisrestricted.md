# SeTokenIsRestricted function

## Description

The **SeTokenIsRestricted** routine determines whether a token contains a list of restricting security identifiers (SID).

## Parameters

### `Token` [in]

Pointer to the access token to test.

## Return value

**SeTokenIsRestricted** returns **TRUE** if the token contains a list of restricting SIDs, **FALSE** otherwise.

## Remarks

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[PsDereferenceImpersonationToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psdereferenceimpersonationtoken)

[PsDereferencePrimaryToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psdereferenceprimarytoken)

[SeQueryAuthenticationIdToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryauthenticationidtoken)

[SeQueryInformationToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken)

[SeQuerySubjectContextToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequerysubjectcontexttoken)

[SeTokenIsAdmin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-setokenisadmin)

[SeTokenIsRestricted](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-setokenisrestricted)