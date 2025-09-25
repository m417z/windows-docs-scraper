# SE_TOKEN_USER structure

## Description

The **SE_TOKEN_USER** structure holds the maximum-sized valid user SID that can be returned by [**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken), [**GetTokenInformation**](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-gettokeninformation), or [**ZwQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryinformationtoken) with the **TokenUser** information class. This structure is suitable for stack allocation.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.TokenUser`

Specifies a **TOKEN_USER** structure representing the user associated with an access token.

### `DUMMYUNIONNAME.User`

Specifies an **SID_AND_ATTRIBUTES** structure representing the user associated with the access token.

### `DUMMYUNIONNAME2`

### `DUMMYUNIONNAME2.Sid`

Specifies a **Security Identifier (SID)** structure used to uniquely identify users or groups

### `DUMMYUNIONNAME2.Buffer`

Specifies an array of SECURITY_MAX_SID_SIZE for allocating enough memory for the largest possible SID size.

## See also

[**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[**SID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid_and_attributes)

[**TOKEN_USER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_user)