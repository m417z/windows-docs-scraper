# IDot11AdHocManager::CreateNetwork

## Description

Creates a wireless ad hoc network. Other clients and hosts can connect to this network.

## Parameters

### `Name` [in]

The friendly name of the network. This string should be limited to 32 characters. The SSID should be used as the friendly name. This name is broadcasted in a beacon.

### `Password` [in]

The password used for machine or user authentication on the network.

The length of the password string depends on the security settings passed in the *pSecurity* parameter. The following table shows the password length associated with various security settings.

| Security Settings | Password Length |
| --- | --- |
| Open-None | 0 |
| Open-WEP | 5 or 13 characters; 10 or 26 hexadecimal digits |
| WPA2PSK | 8 to 63 characters |

For the enumerated values that correspond to the security settings pair above, see [DOT11_ADHOC_AUTH_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/adhoc/ne-adhoc-dot11_adhoc_auth_algorithm) and [DOT11_ADHOC_CIPHER_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/adhoc/ne-adhoc-dot11_adhoc_cipher_algorithm)

### `GeographicalId` [in]

The geographical location in which the network will be created. For a list of possible values, see [Table of Geographical Locations](https://learn.microsoft.com/windows/desktop/Intl/table-of-geographical-locations).

If the interface is not 802.11d conformant, this value is ignored. That means if [IDot11AdHocInterface::IsDot11d](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocinterface-isdot11d) returns **FALSE**, this value is ignored.

If you are not sure which value to use, set *GeographicalId* to CTRY_DEFAULT. If you use CTRY_DEFAULT, 802.11d conformance is not enforced.

### `pInterface` [in]

An optional pointer to an [IDot11AdHocInterface](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocinterface) that specifies the network interface upon which the new network is created. If this parameter is **NULL**, the first unused interface is used. If all interfaces are in use, the first enumerated interface is used. In that case, the previous network on the interface is disconnected.

### `pSecurity` [in]

A pointer to an [IDot11AdHocSecuritySettings](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocsecuritysettings) interface that specifies the security settings used on the network.

### `pContextGuid` [in]

An optional parameter that specifies the GUID of the application that created the network. An application can use this identifier to limit the networks enumerated by [GetIEnumDot11AdHocNetworks](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocmanager-getienumdot11adhocnetworks) to networks created by the application. For this filtering to work correctly, all instances of the application on all machines must use the same GUID.

### `pIAdHoc` [out]

A pointer to an [IDot11AdHocNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocnetwork) interface that represents the created network.

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
| **HRESULT_FROM_WIN32(ERROR_ALREADY_EXISTS)** | A network with the specified *Name* already exists. |
| **HRESULT_FROM_WIN32(ERROR_NOT_READY)** | The *pInterface* interface reports that its radio is turned off. |
| **HRESULT_FROM_WIN32(ERROR_NOT_CAPABLE)** | The *pInterface* interface reports that it is not capable of forming an ad hoc network. This condition can occur because the NIC does not support ad hoc networks, or because the NIC does not support the security settings supplied by *pSecurity*. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The *pSecurity* settings are not supported by the *pInterface* interface. |
| **HRESULT_FROM_WIN32(ERROR_ILL_FORMED_PASSWORD)** | The *Password* supplied is invalid. The password supplied may be an invalid length for the security settings supplied by *pSecurity*. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | A wireless network interface card was not found on the machine. |
| **HRESULT_FROM_WIN32(ERROR_CURRENT_DOMAIN_NOT_ALLOWED)** | Group policy or administrative settings prohibit the creation of the network. |

## Remarks

After a successful **CreateNetwork** call, the network object returned by *pIAdHoc* is provisioned but not constructed. A subsequent call to [CommitCreatedNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocmanager-commitcreatednetwork) initializes the network. Beacons are not sent until the network is committed.

There are no clients or hosts connected to the network after a **CreateNetwork** call. Applications are notified of both successful and failed connection attempts using the [IDot11AdHocManagerNotificationSink](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocmanagernotificationsink) interface. For information about registering for notifications on that interface, see [IDot11AdHocManager](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocmanager).

## See also

[CommitCreatedNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocmanager-commitcreatednetwork)

[IDot11AdHocManager](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocmanager)