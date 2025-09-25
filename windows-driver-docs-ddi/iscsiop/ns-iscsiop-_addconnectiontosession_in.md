# _AddConnectionToSession_IN structure

## Description

The AddConnectionToSession_IN structure holds input data for the [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) method, which is used to add a new connection to an already existing session.

## Members

### `UniqueAdapterId`

A 64-bit integer that uniquely identifies an adapter and a particular loaded instance of a storage miniport driver that manages the adapter. This identifier is unique, not only on the computer where the adapter is located, but also across the entire network.

### `UniqueSessionId`

A 64-bit integer that uniquely identifies the session. The [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) and [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) methods both return this value in their *UniqueSessionId* parameter. Do not confuse this value with the values in the ISID and TSID members.

### `SecurityFlags`

A bitwise OR of flags that indicate the security requirements of a target. For a list of possible values for this member, see [SECURITY_FLAG_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/security-flag-qualifiers).

### `PortNumber`

The number of the port from which to initiate the target logon session.

### `LoginOptions`

A [ISCSI_LoginOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_loginoptions) structure that describes the characteristics of the target logon session that a connection will be added to.

### `TargetPortal`

A [ISCSI_TargetPortal](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_targetportal) structure that indicates which target portal to use to make the additional connection. The **AddConnectionToSession** method calls the **LoginToTarget** method to establish the new connection. If **LoginToTarget** fails with a status value of either ISCSC_TARGET_MOVED_PERMANENTLY or ISCSC_TARGET_MOVED_TEMPORARILY. **TargetPortal** will indicate, on output from **AddConnectionToSession**, the portal that the logon operation should be redirected to. For more information about the ISCSC_TARGET_MOVED_PERMANENTLY and ISCSC_TARGET_MOVED_TEMPORARILY status values, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

### `UsernameSize`

The username size, in bytes.

### `PasswordSize`

The password size, in bytes.

### `KeySize`

The preshared key size, in bytes.

### `Key`

A variable-length array of characters that specifies the preshared key that is associated with the target IP address. The number of elements in the array is specified by the KeySize field.

## Remarks

The iSCSI service requires this method. It is optional that you implement this method.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[AddConnectionToSession_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_addconnectiontosession_out)

[ISCSI_LoginOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_loginoptions)

[ISCSI_TargetPortal](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_targetportal)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)

[MSiSCSI_Operations WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-operations-wmi-class)

[SECURITY_FLAG_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/security-flag-qualifiers)