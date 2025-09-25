# LoginIScsiTargetA function

## Description

The **LoginIscsiTarget** function establishes a full featured login session with the indicated target.

## Parameters

### `TargetName` [in]

The name of the target with which to establish a login session. The target must already exist in the list of discovered targets for the iSCSI initiator service.

### `IsInformationalSession` [in]

If **true**, the **LoginIscsiTarget** function establishes a login session, but the operation does not report the LUNs on the target to the "Plug and Play" Manager. If the login succeeds, management applications will be able to query the target for information with the [SendScsiReportLuns](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-sendscsireportluns) and [SendScsiReadCapacity](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-sendscsireadcapacity) functions, but the storage stack will not enumerate the target or load a driver for it.

If *IsInformationalSession* is **false**, **LoginIscsiTarget** reports the LUNs associated with the target to the "Plug and Play" Manager, and the system loads drivers for the LUNs.

### `InitiatorInstance` [in, optional]

The name of the initiator that logs in to the target. If *InitiatorName* is **null**, the iSCSI initiator service selects an initiator.

### `InitiatorPortNumber` [in, optional]

The port number of the Host Bus Adapter (HBA) that initiates the login session. If this parameter is **ISCSI_ANY_INITIATOR_PORT**, the caller did not specify a port for the initiator HBA to use when logging in to the target.

If *InitiatorName* is **null**, *InitiatorPortNumber* must be **ISCSI_ANY_INITIATOR_PORT**.

### `TargetPortal` [in, optional]

Pointer to a structure of type [ISCSI_TARGET_PORTAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_portala) that indicates the portal that the initiator uses to open the session. The specified portal must belong to a portal group that is associated with the *TargetName*. If *TargetPortal* is **null**, the iSCSI initiator service instructs the initiator to use any portal through which the target is accessible to the initiator. If the caller specifies the value for *TargetPortal*, the iSCSI initiator service will not verify that the *TargetPortal* is accessible to the initiator HBA.

### `SecurityFlags` [in, optional]

A bitmap that specifies the characteristics of the IPsec connection that the initiator adds to the session. If an IPsec security policy between the initiator and the target portal is already configured as a result of the current portal group policy or a previous connection to the target, the existing configuration takes precedence over the configuration specified in *SecurityFlags*.

If the ISCSI_SECURITY_FLAG_VALID flag is set to 0, the iSCSI initiator service uses default values for the security flags that are defined in the registry.

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

### `Mappings` [in, optional]

An array of structures of type [ISCSI_TARGET_MAPPING](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_mappinga), each of which holds information that the initiator uses to assign bus, target and LUN numbers to the devices that are associated with the target. If *Mappings* is **null**, the initiator will select the bus, target and LUN numbers.

### `LoginOptions` [in, optional]

A pointer to a structure of type [ISCSI_LOGIN_OPTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_login_options) that contains the options that specify the characteristics of the login session.

### `KeySize` [in, optional]

The size, in bytes, of the target's preshared key specified by the *Key* parameter.

### `Key` [in, optional]

A preshared key to use when logging in to the target portal that exposes this target.

**Note** If an IPsec policy is already associated with the target portal, the IPsec settings in this call are ignored.

### `IsPersistent` [in]

If **true**, the initiator should save the characteristics of the login session in non-volatile storage, so that the information persists across restarts of the initiator device and reboots of the operating system. The initiator should not establish the login session until after saving the persistent data.

Whenever the initiator device restarts, it should automatically attempt to re-establish the login session with the same characteristics. If **false**, the initiator device simply logs in to the target without saving the characteristics of the login session.

### `UniqueSessionId` [out]

A pointer to a structure of type [ISCSI_UNIQUE_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_unique_session_id) that, on return, contains a unique session identifier for the login session.

### `UniqueConnectionId` [out]

A pointer to a structure of type [ISCSI_UNIQUE_CONNECTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb870817(v=vs.85)) that, on return, contains a unique connection identifier for the login session.

## Return value

Returns ERROR_SUCCESS if the operation succeeds. Otherwise, it returns the appropriate Win32 or iSCSI error code.

## Remarks

The **LoginIscsiTarget** function either establishes a single login session with a target, or creates a persistent login to a target. If **LoginIscsiTarget** creates a persistent login, the specified initiator should log in to the target each time the initiator is started, typically at system boot. Callers to **LoginIscsiTarget** can request the creation of a persistent login by setting the *IsPersistent* parameter to **true**.

> [!NOTE]
> The iscsidsc.h header defines LoginIScsiTarget as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ISCSI_LOGIN_OPTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_login_options)

[ISCSI_TARGET_PORTAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_portala)

[ISCSI_UNIQUE_CONNECTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb870817(v=vs.85))

[ISCSI_UNIQUE_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_unique_session_id)