# ISCSI_LOGIN_OPTIONS structure

## Description

The **ISCSI_LOGIN_OPTIONS** structure is used by initiators to specify the characteristics of a login session.

## Members

### `Version`

The version of login option definitions that define the data in the structure. This member must be set to ISCSI_LOGIN_OPTIONS_VERSION 0.

### `InformationSpecified`

A bitmap that indicates which parts of the **ISCSI_LOGIN_OPTIONS** structure contain valid data.

| Bit | Meaning |
| --- | --- |
| **ISCSI_LOGIN_OPTIONS_USERNAME** | Specifies a user name to use in making a login connection. |
| **ISCSI_LOGIN_OPTIONS_PASSWORD** | Specifies a password to use in making a login connection. |
| **ISCSI_LOGIN_OPTIONS_HEADER_DIGEST** | Specifies the type of digest in use for guaranteeing the integrity of header data. |
| **ISCSI_LOGIN_OPTIONS_DATA_DIGEST** | Specifies the type of digest in use for guaranteeing the integrity of header data. |
| **ISCSI_LOGIN_OPTIONS_MAXIMUM_CONNECTIONS** | Specifies the maximum number of connections to target devices associated with the login session. |
| **ISCSI_LOGIN_OPTIONS_DEFAULT_TIME_2_WAIT** | Specifies the minimum time to wait, in seconds, before attempting to reconnect or reassign a connection that was dropped. |
| **ISCSI_LOGIN_OPTIONS_DEFAULT_TIME_2_RETAIN** | Specifies the maximum time allowed to reassign commands after the initial wait indicated in **DefaultTime2Wait**. |
| **ISCSI_LOGIN_OPTIONS_AUTH_TYPE** | Specifies the type of authentication that establishes the login session. |

### `LoginFlags`

A bitwise OR of login flags that define certain characteristics of the login session. The following table indicates the values that can be assigned to this member:

| Flag | Meaning |
| --- | --- |
| **ISCSI_LOGIN_FLAG_RESERVED1** | Reserved for internal use. |
| **ISCSI_LOGIN_FLAG_ALLOW_PORTAL_HOPPING** | The RADIUS server is permitted to use the portal hopping function for a target if configured to do so. |
| **ISCSI_LOGIN_FLAG_REQUIRE_IPSEC** | The login session must use the IPsec protocol. |
| **ISCSI_LOGIN_FLAG_MULTIPATH_ENABLED** | Multipathing is allowed. When specified the iSCSI Initiator service will allow multiple sessions to the same target. If there are multiple sessions to the same target then there must be some sort of multipathing software installed otherwise data corruption will occur on the target. |

### `AuthType`

An enumerator value of type [ISCSI_AUTH_TYPES](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ne-iscsidsc-iscsi_auth_types) that indicates the authentication type.

### `HeaderDigest`

An enumerator value of type [ISCSI_DIGEST_TYPES](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ne-iscsidsc-iscsi_digest_types) that indicates the type of digest for guaranteeing the integrity of header data.

### `DataDigest`

An enumerator value of type [ISCSI_DIGEST_TYPES](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ne-iscsidsc-iscsi_digest_types) that indicates the type of digest for guaranteeing the integrity of non-header data.

### `MaximumConnections`

A value between 1 and 65535 that specifies the maximum number of connections to the target device that can be associated with the login session.

### `DefaultTime2Wait`

The minimum time to wait, in seconds, before attempting to reconnect or reassign a connection that has been dropped.

### `DefaultTime2Retain`

The maximum time allowed to reassign a connection after the initial wait indicated in **DefaultTime2Wait** has elapsed.

### `UsernameLength`

The length, in bytes, of the user name specified in the **Username** member.

### `PasswordLength`

The length, in bytes, of the user name specified in the **Password** member.

### `Username`

The user name to authenticate to establish the login session. This value is not necessarily a string. For more information, see the Remarks section in this document.

### `size_is`

### `size_is.UsernameLength`

### `Password`

The user name to authenticate to establish the login session. This value is not necessarily a string. For more information, see the Remarks section in this document.

### `size_is.PasswordLength`

## Remarks

Initiators use the **ISCSI_LOGIN_OPTIONS** structure when creating a login session with the [LoginIScsiTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-loginiscsitargeta) routine.

The **Username** and **Password** members are either strings or binary values that are used for iSCSI authentication. The exact meaning and function of these two values depends on the type of authentication used. For the Challenge Handshake Authentication Protocol (CHAP), the value in the **Username** member is the CHAP name, and the value in the **Password** member is the shared secret of the target. If there is no value specified in **Username**, the initiator node name is used as the CHAP name.

If the authentication protocol requires that these two values be strings, they must be ANSI strings.

## See also

[LoginIScsiTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-loginiscsitargeta)