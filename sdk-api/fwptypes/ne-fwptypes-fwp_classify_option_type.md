# FWP_CLASSIFY_OPTION_TYPE enumeration

## Description

The **FWP_CLASSIFY_OPTION_TYPE** enumerated type is used by callouts and shims during run-time classification.

**FWP_CLASSIFY_OPTION_TYPE** specifies timeout options for unicast, multicast, and loose source mapping states and enables blocking or permission of state creation on outbound multicast and broadcast traffic.

## Constants

### `FWP_CLASSIFY_OPTION_MULTICAST_STATE:0`

Specifies the multicast conditions on outbound traffic. See [FWPM_CLASSIFY_OPTION0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_classify_option0) for possible values.

### `FWP_CLASSIFY_OPTION_LOOSE_SOURCE_MAPPING`

Specifies the source mapping conditions for callout filters. See [FWPM_CLASSIFY_OPTION0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_classify_option0) for possible values.

 Loose source mapping allows unicast responses from a remote peer to match only the port number, instead of the entire source address.

### `FWP_CLASSIFY_OPTION_UNICAST_LIFETIME`

Specifies the unicast state lifetime, in seconds.

### `FWP_CLASSIFY_OPTION_MCAST_BCAST_LIFETIME`

Specifies the multicast/broadcast state lifetime, in seconds.

### `FWP_CLASSIFY_OPTION_SECURE_SOCKET_SECURITY_FLAGS`

Specifies that the callout can set secure socket settings on the endpoint. Such flags are only allowed to increase the overall security level. The possible values are defined in the *Mstcpip.h* header file.

| Value | Meaning |
| --- | --- |
| SOCKET_SETTINGS_GUARANTEE_ENCRYPTION 0x00000001 | Indicates that guaranteed encryption of traffic is required. This flag should be set if the default policy prefers methods of protection that do not use encryption. If this flag is set and encryption is not possible for any reason, no packets will be sent and a connection will not be established. |
| SOCKET_SETTINGS_ALLOW_INSECURE 0x00000002 | Indicates that clear text connections are allowed. If this flag is set, some or all of the sent packets will be sent in clear text, especially if security with the peer could not be negotiated.<br><br>**Note** If this flag is not set, it is guaranteed that packets will never be sent in clear text, even if security negotiation fails. |

**Note** Available only in Windows 7, Windows Server 2008 R2, and later.

### `FWP_CLASSIFY_OPTION_SECURE_SOCKET_AUTHIP_MM_POLICY_KEY`

Allows the callout to specify the specific main mode (MM) policy used for the connection.

**Note** Available only in Windows 7, Windows Server 2008 R2, and later.

### `FWP_CLASSIFY_OPTION_SECURE_SOCKET_AUTHIP_QM_POLICY_KEY`

Allows the callout to specify the specific quick mode (QM) policy used for the connection.

**Note** Available only in Windows 7, Windows Server 2008 R2, and later.

### `FWP_CLASSIFY_OPTION_LOCAL_ONLY_MAPPING`

### `FWP_CLASSIFY_OPTION_MAX`

Maximum value for testing purposes.

## See also

[FWPM_CLASSIFY_OPTION0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_classify_option0)