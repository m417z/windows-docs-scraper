# IDot11AdHocNetwork::Connect

## Description

Connects to a previously created wireless ad hoc network. Before an application can connect to a network, the network must have been created using [IDot11AdHocManager::CreateNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocmanager-createnetwork) and committed using [IDot11AdHocManager::CommitCreatedNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocmanager-commitcreatednetwork).

## Parameters

### `Passphrase` [in]

The password string used to authenticate the user or machine on the network.

The length of the password string depends on the security settings passed in the *pSecurity* parameter of the [CreateNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocmanager-createnetwork) call. The following table shows the password length associated with various security settings.

| Security Settings | Password Length |
| --- | --- |
| Open-None | 0 |
| Open-WEP | 5 or 13 characters; 10 or 26 hexadecimal digits |
| WPA2PSK | 8 to 63 characters |

For the enumerated values that correspond to the security settings pair above, see [DOT11_ADHOC_AUTH_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/adhoc/ne-adhoc-dot11_adhoc_auth_algorithm) and [DOT11_ADHOC_CIPHER_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/adhoc/ne-adhoc-dot11_adhoc_cipher_algorithm).

### `GeographicalId` [in]

The geographical location in which the network was created. For a list of possible values, see [Table of Geographical Locations](https://learn.microsoft.com/windows/desktop/Intl/table-of-geographical-locations).

### `fSaveProfile` [in]

An optional parameter that specifies whether a wireless profile should be saved. If **TRUE**, the profile is saved to the profile store. Once a profile is saved, the user can modify the profile using the **Manage Wireless Network** user interface. Profiles can also be modified using the [Native Wifi Functions](https://learn.microsoft.com/windows/desktop/NativeWiFi/native-wifi-functions).

Saving a profile modifies the network signature returned by [IDot11AdHocNetwork::GetSignature](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocnetwork-getsignature).

### `fMakeSavedProfileUserSpecific` [in]

An optional parameter that specifies whether the profile to be saved is an all-user profile. If set to **TRUE**, the profile is specific to the current user. If set to **FALSE**, the profile is an all-user profile and can be used by any user logged into the machine. This parameter is ignored if *fSaveProfile* is **FALSE**.

By default, only members of the Administrators group can save an all-user profile. These security settings can be altered using the [WlanSetSecuritySettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetsecuritysettings) function. Your application must be launched by a user with sufficient privileges for an all-user profile to be saved successfully.

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

## Remarks

This method is asynchronous. **Connect** returns S_OK immediately if the parameters passed to the method are valid. However, a return code of S_OK does not indicate that the connection was successful. You must register for notifications on the [IDot11AdHocNetworkNotificationSink](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocnetworknotificationsink) interface to be notified of connection success or failure. The [IDot11AdHocNetworkNotificationSink::OnStatusChange](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocnetworknotificationsink-onstatuschange) method returns the connection status. For more information about registering for notifications, see [IDot11AdHocManager](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocmanager).

## See also

[IDot11AdHocNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocnetwork)

[IDot11AdHocNetwork::Disconnect](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocnetwork-disconnect)