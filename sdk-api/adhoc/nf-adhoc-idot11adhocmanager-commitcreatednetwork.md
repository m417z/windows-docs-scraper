# IDot11AdHocManager::CommitCreatedNetwork

## Description

Initializes a created network and optionally commits the network's profile to the profile store. The network must be created using [CreateNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocmanager-createnetwork) before calling **CommitCreatedNetwork**.

## Parameters

### `pIAdHoc` [in]

A pointer to a [IDot11AdHocNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocnetwork) interface that specifies the network to be initialized and committed.

### `fSaveProfile` [in]

An optional parameter that specifies whether a wireless profile should be saved. If **TRUE**, the profile is saved to the profile store. Once a profile has been saved, the user can modify the profile using the **Manage Wireless Network** user interface. Profiles can also be modified using the [Native Wifi Functions](https://learn.microsoft.com/windows/desktop/NativeWiFi/native-wifi-functions).

Saving a profile modifies the network signature returned by [IDot11AdHocNetwork::GetSignature](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocnetwork-getsignature).

### `fMakeSavedProfileUserSpecific` [in]

An optional parameter that specifies whether the profile to be saved is an all-user profile. If set to **TRUE**, the profile is specific to the current user. If set to **FALSE**, the profile is an all-user profile and can be used by any user logged into the machine. This parameter is ignored if *fSaveProfile* is **FALSE**.

By default, only members of the Administrators group can persist an all-user profile. These security settings can be altered using the [WlanSetSecuritySettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetsecuritysettings) function. Your application must be launched by a user with sufficient privileges for an all-user profile to be persisted successfully.

If your application is running in a Remote Desktop window, you can only save an all-user profile. User-specific profiles cannot be saved from an application running remotely.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The method failed. |
| **E_INVALIDARG** | One of the parameters is invalid. |
| **E_NOINTERFACE** | A specified interface is not supported. |
| **E_OUTOFMEMORY** | The method could not allocate the memory required to perform this operation. |
| **E_POINTER** | A pointer passed as a parameter is not valid. |

## See also

[IDot11AdHocManager](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocmanager)

[IDot11AdHocManager::CreateNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocmanager-createnetwork)