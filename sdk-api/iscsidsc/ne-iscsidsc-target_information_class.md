## Description

The **TARGET_INFORMATION_CLASS** enumeration specifies information about the indicated target device that the [GetIScsiTargetInformation](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-getiscsitargetinformationa) function retrieves.

## Constants

### `ProtocolType`

A value of the [TARGETPROTOCOLTYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ne-iscsidsc-targetprotocoltype) structure, indicating the protocol that the initiator uses to communicate with the target device.

### `TargetAlias`

A **null**-terminated string that contains the alias of the target device.

### `DiscoveryMechanisms`

A list of **null**-terminated strings that describe the discovery mechanisms that located the indicated target. The list is terminated by a double **null**.

### `PortalGroups`

A [ISCSI_TARGET_PORTAL_GROUP](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_portal_groupa) structure that contains descriptions of the portals in the portal group associated with the target.

### `PersistentTargetMappings`

An array of [ISCSI_TARGET_MAPPING](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_mappinga) structures that contains information about the HBAs and buses through which the target can be reached. The array is preceded by a **ULONG** value that contains the number of elements in the array. Each **ISCSI_TARGET_MAPPING** structure is aligned on a 4-byte boundary.

### `InitiatorName`

A **null**-terminated string that contains the initiator HBA that connects to the target.

### `TargetFlags`

The flags associated with the target. The following table lists the flags that can be associated with a target.

| Target Flag | Meaning |
| --- | --- |
| ISCSI_TARGET_FLAG_HIDE_STATIC_TARGET | The target will not be reported as discovered unless it is also discovered dynamically. |

### `LoginOptions`

A value of the [ISCSI_LOGIN_OPTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_login_options) structure that defines the login data.

## See also

[GetIScsiTargetInformation](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-getiscsitargetinformationa)