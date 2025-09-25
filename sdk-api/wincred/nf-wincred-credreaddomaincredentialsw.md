# CredReadDomainCredentialsW function

## Description

The **CredReadDomainCredentials** function reads the domain credentials from the user's credential set. The credential set used is the one associated with the logon session of the current token. The token must not have the user's SID disabled.

## Parameters

### `TargetInfo` [in]

Target information that identifies the target server. At least one of the naming members must not be **NULL**: NetbiosServerName, DnsServerName, NetbiosDomainName, DnsDomainName or DnsTreeName.

### `Flags` [in]

Flags controlling the operation of the function.

The following flag is defined:

CRED_CACHE_TARGET_INFORMATION

Cache the TargetInfo for a subsequent read using [CredGetTargetInfo](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credgettargetinfoa).

### `Count` [out]

Count of the credentials returned in the *Credentials* array.

### `Credential` [out]

Pointer to an array of pointers to credentials. The most specific existing credential matching the *TargetInfo* is returned. If credentials of various types (for example, CRED_TYPE_DOMAIN_PASSWORD and CRED_TYPE_DOMAIN_CERTIFICATE credentials) exist, one of each type is returned. If a connection were to be made to the named target, this most-specific credential would be used.

Only those credential types specified by the *TargetInfo*.CredTypes array are returned. The returned *Credentials* array is sorted in the same order as the *TargetInfo*.CredTypes array. That is, authentication packages specify a preferred credential type by specifying it earlier in the *TargetInfo*.CredTypes array.If *TargetInfo*.CredTypeCount is zero, the *Credentials* array is returned in the following sorted order:

* CRED_TYPE_DOMAIN_CERTIFICATE
* CRED_TYPE_DOMAIN_PASSWORD

The returned buffer is a single allocated block. Any pointers contained within the buffer are pointers to locations within this single allocated block. The single returned buffer must be freed by calling [CredFree](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credfree).

## Return value

The function returns **TRUE** on success and **FALSE** on failure. The [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function can be called to get a more specific status code. The following status codes can be returned:

* ERROR_INVALID_PARAMETER

  None of the naming parameters were specified.
* ERROR_NOT_FOUND

  There are no credentials matching the specified naming parameters.
* ERROR_NO_SUCH_LOGON_SESSION

  The logon session does not exist or there is no credential set associated with this logon session. Network logon sessions do not have an associated credential set.
* ERROR_INVALID_FLAGS

  A flag that is not valid was specified for the *Flags* parameter.

## Remarks

This function returns the most specific credentials matching the naming parameters. For instance, if there is a credential that matches the target server name and a credential that matches the target domain name, only the server specific credential is returned. This is the credential that would be used.

The following list specifies the order (from most specific to least specific) of what credential is returned if more than one matches:

* The credential target name is of the form <*DfsRoot*>\<*DfsShare*>, and it is an exact match on the *TargetName*.
* An exact match on the *DnsServerName*.
* An exact match on the *NetBIOSServerName*.
* An exact match on *TargetName*.
* A match of the *DnsServerName* to a wildcard server credential. If more than one wildcard server credential matches, the credential with the longer TargetName is used. That is, a credential for *.example.microsoft.com is used instead of a credential for *.microsoft.com.
* An exact match of the *DnsDomainName* to a wildcard domain credential of the form <*DnsDomainName*>\*.
* An exact match of the *NetBIOSDomainName*  to a wildcard domain credential of the form <*NetBIOSDomainName*>\*
* The credential named CRED_SESSION_WILDCARD_NAME.
* The credential named "*".

**CredReadDomainCredentials** differs from [CredRead](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credreada) in that it handles the idiosyncrasies of domain (CRED_TYPE_DOMAIN_PASSWORD or CRED_TYPE_DOMAIN_CERTIFICATE) credentials. Domain credentials contain more than one target member.

If the value of the **Type** member of the [CREDENTIAL](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-credentiala) structure specified by the *Credentials* parameter is **CRED_TYPE_DOMAIN_EXTENDED**, a namespace must be specified in the target name. This function can return only one credential of the specified type.

This function can return multiple credentials of this type, but **CRED_TYPE_DOMAIN_EXTENDED** cannot be mixed with other types in the **CredTypes** member of the [CREDENTIAL_TARGET_INFORMATION](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-credential_target_informationa) structure specified by the *TargetInfo* parameter.

> [!NOTE]
> The wincred.h header defines CredReadDomainCredentials as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).