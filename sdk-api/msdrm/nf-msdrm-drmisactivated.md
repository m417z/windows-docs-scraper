# DRMIsActivated function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMIsActivated** function indicates whether the current user or machine is activated.

## Parameters

### `hClient` [in]

A handle to a client session created by using the [DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession) function.

### `uFlags` [in]

A value that determines whether the current user or machine is being queried for activation status. This can be one of the following values.

#### DRM_ACTIVATE_MACHINE

The machine is being queried for activation status. The machine is considered activated if there is a valid lockbox for the logged-on user
and a valid [machine certificates](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/m-gly) in the per-user certificate store.

In Rights Management Services client 1.0, the machine is considered activated if there is a valid lockbox
and a valid [machine certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/m-gly).

#### DRM_ACTIVATE_GROUPIDENTITY

The current user is being queried for activation status.

The current user is considered activated if the certificate store of the current user has a [rights account certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly) issued to the specified group ID.

### `pActServInfo` [in]

This parameter is reserved and must be set to **NULL**.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

You can call **DRMIsActivated** to determine the current state of computer or user activation before calling any function that requires prior activation. If **DRMIsActivated** fails, call [DRMActivate](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmactivate).

This function internally uses information contained in the client session. If the user ID associated with the client session does not match the ID of the logged–on user, this function will fail. For more information, see [DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession).

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[Activating a Computer](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/activating-a-computer)

[Activating a User](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/activating-a-user)

[DRMActivate](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmactivate)