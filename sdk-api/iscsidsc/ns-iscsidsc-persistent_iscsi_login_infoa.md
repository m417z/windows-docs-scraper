# PERSISTENT_ISCSI_LOGIN_INFOA structure

## Description

The **PERSISTENT_ISCSI_LOGIN_INFO** structure contains information that describes a login session established by the Microsoft iSCSI initiator service after the machine boots up.

## Members

### `TargetName`

A string representing the name of the target the initiator will login to.

### `IsInformationalSession`

If set **TRUE**, the login session is for informational purposes only and will not result in the enumeration of the specified target on the local computer. For an informational login session, the LUNs on the target are not reported to the Plug and Play Manager and the device drivers for the target are not loaded.

A management application can still access targets not enumerated by the system via the [SendScsiInquiry](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-sendscsiinquiry), [SendScsiReportLuns](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-sendscsireportluns), and [SendScsiReadCapcity](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-sendscsireadcapacity) functions.

If set **FALSE**, the LUNs on the target are reported to the Plug and Play manager for enumeration.

### `InitiatorInstance`

A string representing the name of the initiator used to login to the target.

### `InitiatorPortNumber`

The port number of the Host-Bus Adapter (HBA) through which the session login is established. A value of **ISCSI_ANY_INITIATOR_PORT** indicates that a port on the initiator is not currently specified.

### `TargetPortal`

A [ISCSI_TARGET_PORTAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_portala) structure that describes the portal used by the Microsoft iSCSI initiator service to log on to the target.

### `SecurityFlags`

A bitmap that defines the security characteristics of a login connection.

| Value | Meaning |
| --- | --- |
| **ISCSI_SECURITY_FLAG_TUNNEL_MODE_PREFERRED** | The Host Bus Adapter (HBA) initiator should establish the TCP/IP connection to the target portal using IPsec tunnel mode. |
| **ISCSI_SECURITY_FLAG_TRANSPORT_MODE_PREFERRED** | The HBA initiator should establish the TCP/IP connection to the target portal using IPsec transport mode. |
| **ISCSI_SECURITY_FLAG_PFS_ENABLED** | The HBA initiator should establish the TCP/IP connection to the target portal with Perfect Forward Secrecy (PFS) mode enabled if IPsec is required. |
| **ISCSI_SECURITY_FLAG_AGGRESSIVE_MODE_ENABLED** | The HBA initiator should establish the TCP/IP connection to the target portal with aggressive mode enabled. |
| **ISCSI_SECURITY_FLAG_MAIN_MODE_ENABLED** | The HBA initiator should establish the TCP/IP connection to the target portal with main mode enabled. |
| **ISCSI_SECURITY_FLAG_IKE_IPSEC_ENABLED** | The HBA initiator should establish the TCP/IP connection to the target portal using IKE/IPsec protocol. If not set then IPsec is not required to login to the target. |
| **ISCSI_SECURITY_FLAG_VALID** | The other mask values are valid; otherwise, security flags are not specified. |

### `Mappings`

A pointer to a [ISCSI_TARGET_MAPPING](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_mappinga) structure that contains information about a target, its logical units, HBAs, and buses through which it is reached.

### `LoginOptions`

An [ISCSI_LOGIN_OPTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_login_options) structure that contains the persistent login characteristics.

## Remarks

The **PERSISTENT_ISCSI_LOGIN_INFO** structure is used in conjunction with the [ReportIScsiPersistentLogins](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-reportiscsipersistentloginsa) function to retrieve the list of targets for which the Microsoft Discovery Service (iscsiexe.exe) automatically opens a login session after the machine boots up.

> [!NOTE]
> The iscsidsc.h header defines PERSISTENT_ISCSI_LOGIN_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ISCSI_LOGIN_OPTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_login_options)

[ISCSI_TARGET_PORTAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_portala)

[ReportIScsiPersistentLogins](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-reportiscsipersistentloginsa)

[SendScsiInquiry](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-sendscsiinquiry)

[SendScsiReadCapacity](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-sendscsireadcapacity)

[SendScsiReportLuns](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-sendscsireportluns)