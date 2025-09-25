# DRMBOUNDLICENSEPARAMS structure

## Description

>[!Note]
>The AD RMS SDK leveraging functionality exposed by the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal), which leverages functionality exposed by the client in Msipc.dll.

The **DRMBOUNDLICENSEPARAMS** structure is used by [DRMCreateBoundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateboundlicense) to bind to a license.

## Members

### `uVersion`

Specifies the version of the structure. This member should be set to **DRMBOUNDLICENSEPARAMSVERSION**.

### `hEnablingPrincipal`

A handle to an enabling principal in the [end-user license](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/e-gly) that should be bound. Create this handle by using the [DRMCreateEnablingPrincipal](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateenablingprincipal) function. The default for this member is **NULL**. If **NULL** is used, the application will bind to the first principal in the license.

### `hSecureStore`

Reserved for future use. This member must be set to **NULL**.

### `wszRightsRequested`

A pointer to a null-terminated Unicode string that contains a comma-delimited list of the rights requested. This member cannot be **NULL**, and the string must contain valid rights such as EDIT and OWNER.

### `wszRightsGroup`

A pointer to a null-terminated Unicode string that contains the name of the rights group to use in the license; for more information, see Remarks. This member can be set to **NULL** if it is not used.

### `idResource`

A [DRMID](https://learn.microsoft.com/windows/desktop/api/msdrmdefs/ns-msdrmdefs-drmid) structure that identifies the content to which you are trying to bind. You must set the *wszID* and *wszIDType* parameters of this structure to the values you specified in the *wszContentId* and *wszContentIdType* parameters, respectively, in the [DRMSetMetaData](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmsetmetadata) function. If the values are **NULL** or they do not match the corresponding values in **DRMSetMetaData**, the [DRMCreateBoundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateboundlicense) function returns an error.

### `cAuthenticatorCount`

Reserved for future use. This member must be set to zero.

### `rghAuthenticators`

Reserved for future use. This member must be set to **NULL**.

### `wszDefaultEnablingPrincipalCredentials`

A pointer to a null-terminated Unicode string that contains the certificate for the enabling principal (the [rights account certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly)). This member can be set to **NULL** if it is not used.

### `dwFlags`

Optional. Contains flags for additional settings. This member can be zero or the following value.

#### DRMBINDINGFLAGS_IGNORE_VALIDITY_INTERVALS

Normally, a bind will fail if the [end-user license](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/e-gly) has an expired certificate chain. However, if this flag is passed and the user's [rights account certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly) and [machine certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/m-gly) are valid, and all other license requirements are valid, the bind will succeed. When this occurs, the application should alert the user that the content cannot be verified, and it will be opened at the user's risk.

### `_DRMBOUNDLICENSEPARAMS`

TBD

## Remarks

In a C++ application, this structure has a default constructor that initializes the members to the following values.

```cpp
uVersion = DRMBOUNDLICENSEPARAMSVERSION
hEnablingPrincipal = NULL
hSecureStore = NULL
wszRightsRequested = NULL
wszRightsGroup = NULL
cAuthenticatorCount = 0
rghAuthenticators = NULL
wszDefaultEnablingPrincipalCredentials = NULL
idResource.uVersion = DRMIDVERSION
idResource.wszIDType = NULL
idResource.wszID = NULL
dwFlags = 0
```

If there is more than one rights group in the [end-user license](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/e-gly), the *wszRightsGroup* parameter specifies the name of the rights group to use. By default, the first rights group found in the end-user license is chosen. If any one of the requested rights is not granted, the bind request ([DRMCreateBoundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateboundlicense)) will fail.

## See also

[AD RMS Structures](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-structures)

[DRMCreateBoundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateboundlicense)