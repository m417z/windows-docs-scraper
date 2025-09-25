# AddIScsiConnectionA function

## Description

The **AddIscsiConnection** function adds a new iSCSI connection to an existing session.

## Parameters

### `UniqueSessionId` [in]

A pointer to a structure of type [ISCSI_UNIQUE_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_unique_session_id) that, on input, contains the session identifier for the session that was added.

### `Reserved` [in]

This member should be **null** on input.

### `InitiatorPortNumber` [in, optional]

The number of the port on the initiator that the initiator uses to add the connection. A value of **ISCSI_ANY_INITIATOR_PORT** indicates that the initiator can use any of its ports to add the connection.

### `TargetPortal` [in]

A pointer to an ISCSI_TARGET_PORTAL-type structure that indicates the target portal to use when adding the connection.

The portal must belong to the same portal group that the initiator used to login to the target, and it must be a portal that the initiator discovered. The iSCSI initiator service does not verify that the target portal meets these requirements.

### `SecurityFlags` [in, optional]

A bitmap that specifies the characteristics of the IPsec connection that the initiator uses to establish the connection. If IPsec security policy between the initiator and the target portal is already configured because of the portal group policy or a previous connection to the portal, the existing configuration takes precedence over the configuration specified in SecurityFlags and the security bitmap is ignored.

If the **ISCSI_SECURITY_FLAG_VALID** flag is set to 0, the iSCSI initiator service uses default values for the security flags that are defined in the registry.

| Value | Meaning |
| --- | --- |
| **ISCSI_SECURITY_FLAG_TUNNEL_MODE_PREFERRED** | When set to 1, the initiator should make the connection in IPsec tunnel mode. Caller should set this flag or the ISCSI_SECURITY_FLAG_TRANSPORT_MODE_PREFERRED flag, but not both. |
| **ISCSI_SECURITY_FLAG_TRANSPORT_MODE_PREFERRED** | When set to 1, the initiator should make the connection in IPsec transport mode. Caller should set this flag or the ISCSI_SECURITY_FLAG_TUNNEL_MODE_PREFERRED flag, but not both. |
| **ISCSI_SECURITY_FLAG_PFS_ENABLED** | When set to 1, the initiator should make the connection with Perfect Forward Secrecy (PFS) mode enabled; otherwise, the initiator should make the connection with PFS mode disabled. |
| **ISCSI_SECURITY_FLAG_AGGRESSIVE_MODE_ENABLED** | When set to 1, the initiator should make the connection with aggressive mode enabled. Caller should set this flag or the ISCSI_SECURITY_FLAG_MAIN_MODE_ENABLED flag, but not both. <br><br>**Note** The Microsoft software initiator driver does not support aggressive mode. |
| **ISCSI_SECURITY_FLAG_MAIN_MODE_ENABLED** | When set to 1, the initiator should make the connection with main mode enabled. Caller should set this flag or the ISCSI_SECURITY_FLAG_AGGRESSIVE_MODE_ENABLED flag, but not both. |
| **ISCSI_SECURITY_FLAG_IKE_IPSEC_ENABLED** | When set to 1, the initiator should make the connection with the IKE/IPsec protocol enabled; otherwise, the IKE/IPsec protocol is disabled. |
| **ISCSI_SECURITY_FLAG_VALID** | When set to 1, the other mask values are valid; otherwise, the iSCSI initiator service will use bitmap values that were previously defined for the target portal, or if none are available, the initiator service uses the default values defined in the registry. |

### `LoginOptions` [in, optional]

A pointer to a structure of type [ISCSI_LOGIN_OPTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_login_options) that contains the options that specify the characteristics of the login session.

### `KeySize` [in, optional]

The size, in bytes, of the preshared key that is passed to the target.

### `Key` [in, optional]

If the IPsec security policy between the initiator and the target portal is already configured as a result of the portal group policy or a previous connection to the portal, the existing key takes precedence over the key currently specified in this member.

### `ConnectionId` [out, optional]

An [ISCSI_UNIQUE_CONNECTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb870817(v=vs.85))-type structure that, on output, receives an opaque value that uniquely identifies the connection that was added to the session.

## Return value

Returns ERROR_SUCCESS if the operation succeeds. Otherwise, it returns the appropriate Win32 or iSCSI error code.

## See also

[ISCSI_LOGIN_OPTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_login_options)

[ISCSI_TARGET_PORTAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_portala)

[ISCSI_UNIQUE_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_unique_session_id)

## Remarks

> [!NOTE]
> The iscsidsc.h header defines AddIScsiConnection as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).