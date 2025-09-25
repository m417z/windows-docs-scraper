# ISCSI_TARGET_PORTAL_INFO_EXA structure

## Description

The **ISCSI_TARGET_PORTAL_INFO_EX** structure contains information about login credentials to a target portal.

## Members

### `InitiatorName`

A string that represents the name of the Host-Bus Adapter (HBA) initiator.

### `InitiatorPortNumber`

A **ULONG** value that represents the port number on the HBA associated with the portal.

### `SymbolicName`

A string that represents the symbolic name associated with the portal.

### `Address`

A string that represents the IP address or DNS name associated with the portal.

### `Socket`

A **USHORT** value that represents the socket number.

### `SecurityFlags`

A pointer to an **ISCSI_SECURITY_FLAGS** structure that contains a bitmap that defines the security characteristics of a login connection.

| Value | Meaning |
| --- | --- |
| **ISCSI_SECURITY_FLAG_TUNNEL_MODE_PREFERRED** | When set to 1, the initiator should make the connection in IPsec tunnel mode. Caller should set this flag or the **ISCSI_SECURITY_FLAG_TRANSPORT_MODE_PREFERRED** flag, but not both. |
| **ISCSI_SECURITY_FLAG_TRANSPORT_MODE_PREFERRED** | When set to 1, the initiator should make the connection in IPsec transport mode. Caller should set this flag or the **ISCSI_SECURITY_FLAG_TUNNEL_MODE_PREFERRED** flag, but not both. |
| **ISCSI_SECURITY_FLAG_PFS_ENABLED** | When set to 1, the initiator should make the connection with Perfect Forward Secrecy (PFS) mode enabled; otherwise, the initiator should make the connection with PFS mode disabled. |
| **ISCSI_SECURITY_FLAG_AGGRESSIVE_MODE_ENABLED** | When set to 1, the initiator should make the connection with aggressive mode enabled. Caller should set this flag or the **ISCSI_SECURITY_FLAG_MAIN_MODE_ENABLED** flag, but not both. <br><br>**Note** The Microsoft software initiator driver does not support aggressive mode. |
| **ISCSI_SECURITY_FLAG_MAIN_MODE_ENABLED** | When set to 1, the initiator should make the connection with main mode enabled. Caller should set this flag or the **ISCSI_SECURITY_FLAG_AGGRESSIVE_MODE_ENABLED** flag, but not both. |
| **ISCSI_SECURITY_FLAG_IKE_IPSEC_ENABLED** | When set to 1, the initiator should make the connection with the IKE/IPsec protocol enabled; otherwise, the IKE/IPsec protocol is disabled. |
| **ISCSI_SECURITY_FLAG_VALID** | When set to 1, the other mask values are valid; otherwise, the iSCSI initiator service will use bitmap values that were previously defined for the target portal, or if none are available, the initiator service uses the default values defined in the registry. |

### `LoginOptions`

A pointer to an [ISCSI_LOGIN_OPTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_login_options) structure that defines the login data.

## See also

[ISCSI_TARGET_PORTAL_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_portal_infoa)

## Remarks

> [!NOTE]
> The iscsidsc.h header defines ISCSI_TARGET_PORTAL_INFO_EX as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).