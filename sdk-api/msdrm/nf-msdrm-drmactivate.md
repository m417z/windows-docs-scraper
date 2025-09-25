# DRMActivate function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMActivate** function obtains a lockbox and [machine certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/m-gly) for a machine or a [rights account certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly) for a user.

## Parameters

### `hClient` [in]

A handle to a client session, created by [DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession).

### `uFlags` [in]

Specifies the type of activation wanted, plus additional options; for more information, see Remarks. This parameter can be a combination of one or more of the following flags.

#### DRM_ACTIVATE_MACHINE

Activate the computer. The **DRM_ACTIVATE_SILENT** flag is also required, but the **DRM_ACTIVATE_GROUPIDENTITY** flag must not be set. The *pActServInfo* parameter is ignored.

Each computer is activated on a per-user basis. That is, the machine certificate is generated and stored for the currently logged-in user.

The application callback function specified in the [DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession) function will be called with the [DRM_MSG_ACTIVATE_MACHINE](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/drm-msg-activate-machine) message to provide machine activation status feedback.

#### DRM_ACTIVATE_GROUPIDENTITY

Activates a rights account. This flag cannot be combined with **DRM_ACTIVATE_MACHINE**.

The **DRM_ACTIVATE_SILENT** flag is required for RMS v1.0 SP2 and Windows Vista. The **DRM_ACTIVATE_SILENT** flag is, however, optional for Windows Vista with SP1 and Windows Server 2008.

The application callback function specified in the [DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession) function will be called with the [DRM_MSG_ACTIVATE_GROUPIDENTITY](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/drm-msg-activate-groupidentity) message to provide rights account activation status feedback.

#### DRM_ACTIVATE_TEMPORARY

Acquire a temporary [rights account certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly) (RAC). A temporary RAC is only good for a short period of time, but it is stored in the permanent license store. This flag is ignored in nonsilent activation; for more information, see Remarks.

#### DRM_ACTIVATE_CANCEL

Cancel an in-progress activation attempt.

#### DRM_ACTIVATE_SILENT

Activate a user without displaying a Windows password dialog box. This flag is required for **DRM_ACTIVATE_MACHINE** and optional for **DRM_ACTIVATE_GROUPIDENTITY**, depending on the operating system. For more information, see the **DRM_ACTIVATE_GROUPIDENTITY** parameter.

If this flag is used with **DRM_ACTIVATE_GROUPIDENTITY**, the *pActServInfo* parameter cannot be **NULL**. If it is used with **DRM_ACTIVATE_MACHINE**, *pActServInfo* is ignored.

#### DRM_ACTIVATE_SHARED_GROUPIDENTITY

This flag is not used.

#### DRM_ACTIVATE_DELAYED

Delayed machine activation. In normal silent activation, the client receives a CAB file that contains activation files that are expanded and run automatically. With this flag, the files are saved to a location that is passed to the *pvParam* parameter of the callback function, where a client can check them for viruses before expanding and running them.

### `uLangID` [in]

The language ID used by the application. If this parameter is set to zero, the default language ID for the logged-on user is used.

### `pActServInfo` [in]

Optional server information. If the client has not been configured to use Active Directory Federation Services (ADFS) with AD RMS, you can pass **NULL** to use the Windows Live ID service for service discovery. If the client has been configured to use ADFS, you must pass the Windows Live certification URL.  For more information about service discovery, see [DRMGetServiceLocation](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetservicelocation).

### `pvContext` [in]

A 32-bit, application-defined value that is sent in the *pvContext* parameter of the callback function. This value can be a pointer to data, a pointer to an event handle, or whatever else the custom callback function is designed to handle. For more information, see [Callback Prototype](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrmdefs/nc-msdrmdefs-drmcallback).

### `hParentWnd` [in]

Parent window handle used in nonsilent Windows Live ID activation (user activation only). In nonsilent activation, a Windows Live ID window opens to request user information. This parameter allows the application to assign an arbitrary window as the window's parent. If this parameter is **NULL**, the active window is used.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

If an application attempts to activate a user on a computer that has not yet been activated, the function will fail. We recommend that an application call [DRMIsActivated](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmisactivated) before calling this function to determine the activation status of the computer. Activating a machine that is already activated will overwrite the existing lockbox and machine certificate. Activating a user a second time will add an additional [rights account certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly) to the computer. A user needs to activate a particular computer only once, although updates in the lockbox architecture may require downloading and activating a new lockbox.

There are several options in activation.

| Option | Description |
| --- | --- |
| Silent or nonsilent | Nonsilent activation is the default. Silent activation is specified by **DRM_ACTIVATE_SILENT** and is required for machine activation. If silent activation is specified and *pActServInfo* is not **NULL**, the function creates and sends an activation request to the URL specified in the **wszURL** member of *pActServInfo*. For more information, see [DRM_ACTSERV_INFO](https://learn.microsoft.com/windows/desktop/api/msdrmdefs/ns-msdrmdefs-drm_actserv_info). |
| Windows or Windows Live ID | This is determined by the type of client handle passed in to *hClient*. |
| Temporary or permanent | This applies only to a [rights account certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly) (RAC), not to a machine certificate. Permanent activation is the default. Temporary is specified by the **DRM_ACTIVATE_TEMPORARY** flag. When you acquire a temporary RAC by using the **DRM_ACTIVATE_TEMPORARY** flag, the RAC is stored in the permanent license store, though it will expire shortly. The default validity time for a temporary RAC is 15 minutes, although this can be changed by the AD RMS service's administrator. To avoid cluttering the license store with expired RACs, you should delete a temporary RAC when ending a client session. |

The following list describes what happens with combinations of these options.

| Option | Temporary | Permanent |
| --- | --- | --- |
| Silent Windows | Activation occurs without a dialog box. The user currently logged in is activated. | Activation occurs without a dialog box. The user currently logged in is activated. |
| Nonsilent Windows | A Windows password dialog box appears. The user specified is activated. | A Windows password dialog box appears. The user specified is activated. |
| Silent Windows Live ID | Not allowed. | Not allowed. |
| Nonsilent Windows Live ID | A Windows Live ID login window appears. The user specified is activated. | A Windows Live ID login window appears. The user specified is activated. |

During execution, **DRMActivate** calls into the user-defined callback function and sets the *msg* parameter to **DRM_MSG_ACTIVATE_MACHINE** or **DRM_MSG_ACTIVATE_GROUPIDENTITY**. For more information, see [Creating a Callback Function](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/creating-a-callback-function).

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[Activating a Computer](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/activating-a-computer)

[Activating a User](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/activating-a-user)

[Creating a Callback Function](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/creating-a-callback-function)

[DRMIsActivated](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmisactivated)