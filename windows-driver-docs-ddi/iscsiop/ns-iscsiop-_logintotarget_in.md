# _LoginToTarget_IN structure

## Description

The LoginToTarget_IN structure holds the input data for the [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) method, which is used to login to a target.

## Members

### `PortNumber`

The number of the port (initiator portal) that the HBA initiator uses to establish the logon session. This value must match the **Index** member of the [ISCSI_PortalInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_iscsi_portalinfo) structure.

### `LoginOptions`

A [ISCSI_LoginOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_loginoptions) structure that specifies the characteristics of the logon session.

### `SessionType`

A [LOGINSESSIONTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ne-iscsiop-loginsessiontype) enumeration value that specifies the type of logon session.

### `SecurityFlags`

A bitwise OR of security flags that indicate the security requirements that are associated with the authentication key that is used to establish the logon session. For a list of the flags that you can combine to define this member's value, see [SECURITY_FLAG_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/security-flag-qualifiers).

### `TargetPortal`

A [ISCSI_TargetPortal](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_targetportal) structure that indicates which target portal to use to make the connection.

### `UsernameSize`

The size, in bytes, of the string in **Username**.

### `PasswordSize`

The size, in bytes, of the string in **Password**.

### `KeySize`

The size, in bytes, of the string in **Key**.

### `UniqueIdForISID`

A number that the miniport driver that manages the HBA can use to construct a unique session identifier (ISID).

### `PersistentLogin`

A Boolean value that indicates if the logon should be persistent. If this member is **TRUE**, the logon should be persistent. The HBA's miniport driver should store the characteristics of this logon in non-volatile memory and log on to the target automatically every time the operating system loads the miniport driver. If this member is **FALSE**, the logon is not persistent.

### `InitiatorNode`

The iSCSI name of the initiator node to use for the connection. If this member is empty, the HBA's miniport driver can choose any initiator node name during authentication. The initiator node name is usually an iSCSI qualified name (IQN).

### `InitiatorAlias`

The iSCSI alias of the initiator node.

### `TargetName`

The iSCSI target name with which to establish the logon session.

### `Mappings`

A [ISCSI_TargetMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_targetmapping) structure that maps a collection of logical unit numbers (LUNs) that are locally defined to a group of 64-bit iSCSI LUNs. If the initiator service does not specify mappings, the HBA's miniport driver can use any mappings for the LUNs. The miniport driver should report unmapped LUNs to the port driver to be enumerated.

### `Key`

A variable-length array of UCHAR values that defines the preshared key that is associated with the target IP address.

## Remarks

You must implement this method.

## See also

[ISCSI_LoginOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_loginoptions)

[ISCSI_PortalInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_iscsi_portalinfo)

[ISCSI_TargetMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_targetmapping)

[ISCSI_TargetPortal](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_targetportal)

[LOGINSESSIONTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ne-iscsiop-loginsessiontype)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)

[LoginToTarget_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_logintotarget_out)

[MSiSCSI_Operations WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-operations-wmi-class)

[SECURITY_FLAG_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/security-flag-qualifiers)