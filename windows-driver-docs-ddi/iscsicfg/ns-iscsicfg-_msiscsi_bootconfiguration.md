# _MSiSCSI_BootConfiguration structure

## Description

The MSiSCSI_BootConfiguration structure describes how the boot device is configured.

## Members

### `LUN`

The logical unit number (LUN) that identifies the logical unit on the target that functions as a boot device.

### `SecurityFlags`

A bitwise OR of security flags that indicate the security requirements of the boot device. For a list of possible flags for this member, see [SECURITY_FLAG_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/security-flag-qualifiers).

### `UsernameSize`

The size, in bytes, of the string in **Username**.

### `PasswordSize`

The size, in bytes, of the string in **Password**.

### `DiscoverBootDevice`

A Boolean value that indicates whether the system should dynamically discover the boot device. If this member is **TRUE**, the system should dynamically discover the boot device.

### `InitiatorNode`

The iSCSI name of the initiator node to use for connecting to the boot device. If this member is **NULL**, the HBA can choose any initiator node. The iSCSI name for the initiator uniquely identifies the initiator anywhere in the world. For more information about how to specify this name, see the *iSCSI* specification that is published by the Internet Engineering Task Force (IETF) of the IP storage working group.

### `TargetName`

The iSCSI name for the target that contains the boot device.

### `TargetPortal`

A [ISCSI_TargetPortal](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_targetportal) structure that specifies the portal to use for the connection.

### `LoginOptions`

A [ISCSI_LoginOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_loginoptions) structure that specifies the characteristics of the logon session to establish with the boot device.

### `Username`

A variable length array of characters that specifies the user name to use with the challenge handshake authentication protocol (CHAP). The user name is also known as the *CHAP name* (CHAP_N). The initiator uses the CHAP name to authenticate the target.

## Remarks

The WMI tool suite automatically generates a declaration of the MSiSCSI_BootConfiguration structure when it compiles the [MSiSCSI_BootConfiguration WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-bootconfiguration-wmi-class) in *Config.mof*.It is optional that you implement this class.

## See also

[ISCSI_LoginOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_loginoptions)

[ISCSI_TargetPortal](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_targetportal)

[MSiSCSI_BootConfiguration WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-bootconfiguration-wmi-class)

[SECURITY_FLAG_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/security-flag-qualifiers)