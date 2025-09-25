# SECPKG_FUNCTION_TABLE structure

## Description

The **SECPKG_FUNCTION_TABLE** structure contains pointers to the LSA functions that a [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) must implement. The [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) obtains this structure from an SSP/AP DLL when it calls the
[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn) function.

## Members

### `InitializePackage`

Pointer to the [LsaApInitializePackage](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_initialize_package) function.

### `LogonUser`

Pointer to the [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera) function.

### `CallPackage`

Pointer to the [CallPackage](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_call_package) function.

### `LogonTerminated`

Pointer to the [LsaApLogonTerminated](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_logon_terminated) function.

### `CallPackageUntrusted`

Pointer to the [LsaApCallPackageUntrusted](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa378218(v=vs.85)) function.

### `CallPackagePassthrough`

Pointer to the [CallPackagePassthrough](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_call_package_passthrough) function.

### `LogonUserEx`

Pointer to the [LogonUserEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonuserexa) function.

### `LogonUserEx2`

Pointer to the [LsaApLogonUserEx2](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_logon_user_ex2) function.

### `Initialize`

Pointer to the [SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

### `Shutdown`

Pointer to the [SpShutdown](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380183(v=vs.85)) function.

### `GetInfo`

Pointer to the [SpGetInfo](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spgetinfofn) function.

### `AcceptCredentials`

Pointer to the [SpAcceptCredentials](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spacceptcredentialsfn) function.

### `AcquireCredentialsHandle`

Pointer to the [AcquireCredentialsHandle](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea) function.

### `QueryCredentialsAttributes`

Pointer to the [QueryCredentialsAttributes](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycredentialsattributesa) function.

### `FreeCredentialsHandle`

Pointer to the [FreeCredentialsHandle](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecredentialshandle) function.

### `SaveCredentials`

Pointer to the [SpSaveCredentials](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spsavecredentialsfn) function.

### `GetCredentials`

Pointer to the [GetCredentials](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_get_credentials) function.

### `DeleteCredentials`

Pointer to the [SpDeleteCredentials](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spdeletecredentialsfn) function.

### `InitLsaModeContext`

Pointer to the [SpInitLsaModeContext](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitlsamodecontextfn) function.

### `AcceptLsaModeContext`

Pointer to the [SpAcceptLsaModeContext](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spacceptlsamodecontextfn) function.

### `DeleteContext`

Pointer to the [SpDeleteContext](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-kspdeletecontextfn) function.

### `ApplyControlToken`

Pointer to the [ApplyControlToken](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-applycontroltoken) function.

### `GetUserInfo`

Pointer to the [SpGetUserInfo](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spgetuserinfofn) function.

### `GetExtendedInformation`

Pointer to the [SpGetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spgetextendedinformationfn) function.

### `QueryContextAttributes`

Pointer to the [QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) function.

### `AddCredentials`

Pointer to the [SpAddCredentials](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spaddcredentialsfn) function.

### `SetExtendedInformation`

Pointer to the [SpSetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spsetextendedinformationfn) function.

### `SetContextAttributes`

Pointer to the [SetContextAttributes](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-setcontextattributesa) function.

### `SetCredentialsAttributes`

Pointer to the [SetCredentialsAttributes](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-setcredentialsattributesa) function.

### `ChangeAccountPassword`

Pointer to the [ChangeAccountPassword](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-changeaccountpassworda) function.

### `QueryMetaData`

Pointer to the [QueryMetaData](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spquerymetadatafn) function.

### `ExchangeMetaData`

Pointer to the [ExchangeMetaData](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spexchangemetadatafn) function.

### `GetCredUIContext`

Pointer to the [GetCredUIContext](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spgetcreduicontextfn) function.

### `UpdateCredentials`

Pointer to the [UpdateCredentials](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spupdatecredentialsfn) function.

### `ValidateTargetInfo`

Pointer to the [SpValidateTargetInfoFn](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spvalidatetargetinfofn) function.

### `PostLogonUser`

### `GetRemoteCredGuardLogonBuffer`

### `GetRemoteCredGuardSupplementalCreds`

### `GetTbalSupplementalCreds`

### `LogonUserEx3`

### `PreLogonUserSurrogate`

### `PostLogonUserSurrogate`

### `ExtractTargetInfo`