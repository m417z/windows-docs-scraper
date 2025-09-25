# _ISCSI_LoginOptions structure

## Description

The ISCSI_LoginOptions structure defines the characteristics of a logon session. The LoginToTarget_IN routines use these defined characteristics while it logs into an iSCSI target.

## Members

### `InformationSpecified`

A bitmap that indicates which members of the ISCSI_LoginOptions structure contain valid data. The following table describes the possible values:

| Bit | Description |
| --- | --- |
| ISCSI_LOGIN_OPTIONS_HEADER_DIGEST | The **HeaderDigest** member specifies the type of digest that is used to guarantee the integrity of header data. |
| ISCSI_LOGIN_OPTIONS_DATA_DIGEST | The **DataDigest** member specifies the type of digest that is used to guarantee the integrity of header data. |
| ISCSI_LOGIN_OPTIONS_MAXIMUM_CONNECTIONS | The **MaximumConnections** member specifies the maximum number of connections that are allowed in the iSCSI session. |
| ISCSI_LOGIN_OPTIONS_DEFAULT_TIME_2_WAIT | The **DefaultTime2Wait** member specifies the minimum time to wait, in seconds, before the initiator attempts to reconnect or reassign a connection that was dropped. |
| ISCSI_LOGIN_OPTIONS_DEFAULT_TIME_2_RETAIN | The **DefaultTime2Retain** member specifies the maximum time that is allowed to reassign commands after the initial wait indicated in **DefaultTime2Wait**. |
| ISCSI_LOGIN_OPTIONS_AUTH_TYPE | The **AuthType** member specifies the type of authentication that establishes the logon session. |
| ISCSI_LOGIN_OPTIONS_USERNAME | The username to be used during logon. |
| ISCSI_LOGIN_OPTIONS_PASSWORD | The password to be used during logon. |

### `HeaderDigest`

A [ISCSI_DIGEST_TYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ne-iscsidef-iscsi_digest_types) value that indicates the method that the initiator uses to verify the integrity of the header digest in a logon PDU.

### `DataDigest`

A [ISCSI_DIGEST_TYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ne-iscsidef-iscsi_digest_types) value that indicates the method that the initiator uses to verify the integrity of the data digest in a logon PDU.

### `MaximumConnections`

A value between 1 and 65535 that specifies the maximum number of connections to target devices that can be associated with a single logon session. A value of 0 indicates that there is no limit to the number of connections.

### `DefaultTime2Wait`

The minimum time to wait, in seconds, before the initiator attempts to reconnect or reassign a connection (or task) that has been dropped after an unexpected connection termination or reset. The initiator and target negotiate to determine this value.

### `DefaultTime2Retain`

The maximum time, in seconds, to reassign a connection after the initial wait that is indicated in **DefaultTime2Wait** has elapsed. The initiator and target negotiate to determine this value.

### `LoginFlags`

A bitwise OR of logon flags that define certain characteristics of the logon session. The following table indicates the values that you can assign to this member.

| Logon flag | Meaning |
| --- | --- |
| ISCSI_LOGIN_FLAG_REQUIRE_IPSEC | The logon session must use the IPSec protocol. |
| ISCSI_LOGIN_FLAG_MULTIPATH_ENABLED | Multipathing software is installed, so the iSCSI initiator service allows multiple sessions to the same target. |
| ISCSI_LOGIN_FLAG_RESERVED1 | Microsoft internal use only. |
| ISCSI_LOGIN_FLAG_ALLOW_PORTAL_HOPPING | If a target portal is not available for login, the initiator can "hop" through the list of target portals that it discovered and that can be used for login operations. That is, the initiator will continue to try the list of portals that are available until it finds one that can be used for login, so it can then log in to the available target portal. |
| ISCSI_LOGIN_FLAG_USE_RADIUS_RESPONSE | Use RADIUS to generate CHAP response. |
| ISCSI_LOGIN_FLAG_USE_RAIDUS_VERIFICATION | Use RADIUS to verify CHAP response. |

### `AuthType`

A [ISCSI_AUTH_TYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ne-iscsidef-iscsi_auth_types) value that indicates the authentication method that is used to establish a logon connection.

## See also

[ISCSI_AUTH_TYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ne-iscsidef-iscsi_auth_types)

[ISCSI_DIGEST_TYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ne-iscsidef-iscsi_digest_types)

[ISCSI_LoginOptions WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-loginoptions-wmi-class)