# SecurityFunctionTableA structure

## Description

The **SecurityFunctionTable** structure is a dispatch table that contains pointers to the functions defined in SSPI.

## Members

### `dwVersion`

Version number of the table.

### `EnumerateSecurityPackagesA`

### `QueryCredentialsAttributesA`

### `AcquireCredentialsHandleA`

### `FreeCredentialHandle`

### `Reserved2`

Reserved for future use.

### `InitializeSecurityContextA`

### `AcceptSecurityContext`

Pointer to the [AcceptSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) function.

### `CompleteAuthToken`

Pointer to the [CompleteAuthToken](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-completeauthtoken) function.

### `DeleteSecurityContext`

Pointer to the [DeleteSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-deletesecuritycontext) function.

### `ApplyControlToken`

Pointer to the [ApplyControlToken](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-applycontroltoken) function.

### `QueryContextAttributesA`

### `ImpersonateSecurityContext`

Pointer to the [ImpersonateSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-impersonatesecuritycontext) function.

### `RevertSecurityContext`

Pointer to the [RevertSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-revertsecuritycontext) function.

### `MakeSignature`

Pointer to the [MakeSignature](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-makesignature) function.

### `VerifySignature`

Pointer to the [VerifySignature](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-verifysignature) function.

### `FreeContextBuffer`

Pointer to the [FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer) function.

### `QuerySecurityPackageInfoA`

### `Reserved3`

Reserved for future use.

### `Reserved4`

Reserved for future use.

### `ExportSecurityContext`

Pointer to the [ExportSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-exportsecuritycontext) function.

### `ImportSecurityContextA`

### `AddCredentialsA`

### `Reserved8`

Reserved for future use.

### `QuerySecurityContextToken`

Pointer to the [QuerySecurityContextToken](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querysecuritycontexttoken) function.

### `EncryptMessage`

Pointer to the [EncryptMessage (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-encryptmessage) function.

### `DecryptMessage`

Pointer to the [DecryptMessage (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-decryptmessage) function.

### `SetContextAttributesA`

### `SetCredentialsAttributesA`

### `ChangeAccountPasswordA`

### `Reserved9`

### `QueryContextAttributesExA`

### `QueryCredentialsAttributesExA`

#### - AcquireCredentialsHandle

Pointer to the [AcquireCredentialsHandle](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea) function.

#### - AddCredentials

Pointer to the [AddCredential](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_add_credential) function.

#### - EnumerateSecurityPackages

Pointer to the [EnumerateSecurityPackages](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-enumeratesecuritypackagesa) function.

#### - FreeCredentialsHandle

Pointer to the [FreeCredentialsHandle](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecredentialshandle) function.

#### - ImportSecurityContext

Pointer to the [ImportSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-importsecuritycontexta) function.

#### - InitializeSecurityContext

Pointer to the [InitializeSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta) function.

#### - QueryContextAttributes

Pointer to the [QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) function.

#### - QueryCredentialsAttributes

Pointer to the [QueryCredentialsAttributes](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycredentialsattributesa) function.

#### - QuerySecurityPackageInfo

Pointer to the [QuerySecurityPackageInfo](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querysecuritypackageinfoa) function.

#### - Reserved1

Reserved for future use.

#### - SetContextAttributes

Pointer to the [SetContextAttributes](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-setcontextattributesa) function.

## See also

[InitSecurityInterface](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initsecurityinterfacea)

## Remarks

> [!NOTE]
> The sspi.h header defines SecurityFunctionTable as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).