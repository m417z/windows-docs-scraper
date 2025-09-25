# AddIScsiSendTargetPortalA function

## Description

The **AddIscsiSendTargetPortal** function adds a static target portal to the list of target portals to which the iSCSI initiator service transmits **SendTargets** requests.

## Parameters

### `InitiatorInstance` [in, optional]

The initiator that the iSCSI initiator service utilizes to transmit **SendTargets** requests to the specified target portal. If **null**, the iSCSI initiator service will use any initiator that can reach the target portal.

### `InitiatorPortNumber` [in, optional]

The port number to use for the **SendTargets** request. This port number corresponds to the source IP address on the Host-Bus Adapter (HBA). A value of **ISCSI_ALL_INITIATOR_PORTS** indicates that the initiator must select the appropriate port based upon current routing information.

### `LoginOptions` [in, optional]

A pointer to a structure of type [ISCSI_LOGIN_OPTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_login_options) that contains the login options to use with the target portal.

### `SecurityFlags` [in, optional]

A bitmap that specifies the characteristics of the IPsec connection that the initiator adds to the session. If IPsec security policy between the initiator and the target portal is already configured as a result of the portal group policy or a previous connection to the portal, the existing configuration takes precedence over the configuration specified in SecurityFlags and the security bitmap is ignored.

If the **ISCSI_SECURITY_FLAG_VALID** flag is set to 0, the iSCSI initiator service uses default values for the security flags that are defined in the registry.

Caller can set any of the following flags in the bitmap:

| Value | Meaning |
| --- | --- |
| **ISCSI_SECURITY_FLAG_TUNNEL_MODE_PREFERRED** | When set to 1, the initiator should make the connection in IPsec tunnel mode. Caller should set this flag or the ISCSI_SECURITY_FLAG_TRANSPORT_MODE_PREFERRED flag, but not both. |
| **ISCSI_SECURITY_FLAG_TRANSPORT_MODE_PREFERRED** | When set to 1, the initiator should make the connection in IPsec transport mode. Caller should set this flag or the ISCSI_SECURITY_FLAG_TUNNEL_MODE_PREFERRED flag, but not both. |
| **ISCSI_SECURITY_FLAG_PFS_ENABLED** | When set to 1, the initiator should make the connection with Perfect Forward Secrecy (PFS) mode enabled; otherwise, the initiator should make the connection with PFS mode disabled. |
| **ISCSI_SECURITY_FLAG_AGGRESSIVE_MODE_ENABLED** | When set to 1, the initiator should make the connection with aggressive mode enabled. Caller should set this flag or the ISCSI_SECURITY_FLAG_MAIN_MODE_ENABLED flag, but not both. <br><br>**Note** The Microsoft software initiator driver does not support aggressive mode. |
| **ISCSI_SECURITY_FLAG_MAIN_MODE_ENABLED** | When set to 1, the initiator should make the connection with main mode enabled. Caller should set this flag or the ISCSI_SECURITY_FLAG_AGGRESSIVE_MODE_ENABLED flag, but not both. |
| **ISCSI_SECURITY_FLAG_IKE_IPSEC_ENABLED** | When set to 1, the initiator should make the connection with the IKE/IPsec protocol enabled; otherwise, the IKE/IPsec protocol is disabled. |
| **ISCSI_SECURITY_FLAG_VALID** | When set to 1, the other mask values are valid; otherwise, the iSCSI initiator service will use bitmap values that were previously defined for the target portal, or if none are available, the initiator service uses the default values defined in the registry. |

### `Portal`

A pointer to a structure of type [ISCSI_TARGET_PORTAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_portala) that indicates the portal to which SendTargets will be sent for target discovery.

## Return value

Returns ERROR_SUCCESS if the operation succeeds. Otherwise, it returns the appropriate Win32 or iSCSI error code.

## See also

[ISCSI_LOGIN_OPTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_login_options)

[ISCSI_TARGET_PORTAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_portala)

## Remarks

> [!NOTE]
> The iscsidsc.h header defines AddIScsiSendTargetPortal as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).