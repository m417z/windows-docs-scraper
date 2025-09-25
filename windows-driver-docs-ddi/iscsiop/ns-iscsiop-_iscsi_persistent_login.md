# _ISCSI_Persistent_Login structure

## Description

The ISCSI_Persistent_Login structure defines a persistent logon that the operating system initiates automatically when the computer boots up.

## Members

### `TargetName`

A wide character string that indicates the name of the target with which the iSCSI initiator service establishes a persistent logon when it restarts.

### `SecurityFlags`

A bitwise OR of security flags that indicate the security requirements of the target that is specified in the persistent logon. For a list of possible values for this member, see [SECURITY_FLAG_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/security-flag-qualifiers).

### `InitiatorPortNumber`

The port number on the initiator side to perform the logon operation through.

### `UsernameSize`

The size, in bytes, of the string in **Username**.

### `IsInformationalSession`

A Boolean value that indicates whether the persistent logon is configured to establish a purely informational session. If this member is **TRUE**, the persistent logon is configured to establish a purely informational session.

### `UniqueIdForISID`

Portal to use for initial connection

### `TargetPortal`

An [ISCSI_TargetPortal](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_targetportal) structure that specifies which target portal to use for the initial logon connection.

### `LoginOptions`

An [ISCSI_LoginOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_loginoptions) structure that specifies the characteristics of the persistent logon session.

### `TargetMapping`

An [ISCSI_TargetMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_targetmapping) structure that defines the target mappings.

### `Username`

A variable-length array of characters that specifies the challenge handshake authentication protocol user name (CHAP_N) to use when the initiator is authenticating the target. The number of elements in the array is specified by the **UsernameSize** field.

## See also

[ISCSI_LoginOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_loginoptions)

[ISCSI_Persistent_Login WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-persistent-login-wmi-class)

[ISCSI_TargetMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_targetmapping)

[ISCSI_TargetPortal](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_targetportal)

[SECURITY_FLAG_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/security-flag-qualifiers)