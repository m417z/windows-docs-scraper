# FW_RULE structure

Represents a firewall rule (appropriate for use by binary policy version 2.27 servers and clients). Also see [FW_GLOBAL_CONFIG](https://learn.microsoft.com/openspecs/windows_protocols/ms-fasp/faf4ffbe-1d51-40ad-ae90-2230f2c0b6a9) and [FW_RULE](https://learn.microsoft.com/openspecs/windows_protocols/ms-fasp/8c008258-166d-46d4-9090-f2ffaa01be4b).

## Members

`pNext`

Points to the next **FW_RULE** structure in a linked list.

`wSchemaVersion`

TBD

`wszRuleId`

TBD

`wszName`

TBD

`wszDescription`

TBD

`dwProfiles`

TBD

`Direction`

An **FW_DIRECTION** structure.

`wIpProtocol`

A **WORD** value in the range 0-255, or **FW_IP_PROTOCOL_ANY**.

`LocalPorts`

Ports specified if *wIpProtocol* has the value 6 (TCP) or 17 (UDP).

`RemotePorts`

Ports specified if *wIpProtocol* has the value 6 (TCP) or 17 (UDP).

`V4TypeCodeList`

ICMP types/codes specified if *wIpProtocol* has the value of 1 (ICMPv4) or 58 (ICMPv6).

`V6TypeCodeList`

ICMP types/codes specified if *wIpProtocol* has the value of 1 (ICMPv4) or 58 (ICMPv6).

`LocalAddresses`

TBD

`RemoteAddresses`

TBD

`LocalInterfaceIds`

TBD

`dwLocalInterfaceTypes`

Bit flags from **FW_INTERFACE_TYPE**.

`wszLocalApplication`

TBD

`wszLocalService`

TBD

`Action`

TBD

`wFlags`

Bit flags from **FW_RULE_FLAGS**.

`wszRemoteMachineAuthorizationList`

Authorized remote machines SDDL.

`wszRemoteUserAuthorizationList`

Authorized remote users SDDL.

`wszEmbeddedContext`

TBD

`PlatformValidityList`

TBD

`Status`

Parsing error if any, filled on return. On input, set this to **FW_RULE_STATUS_OK**.

`Origin`

Rule origin, filled on enumerated rules. Ignored on input.

`wszGPOName`

Name of originating GPO, if rule origin is GP.

`Reserved`

Reserved; don't use.

`pMetaData`

TBD

`wszLocalUserAuthorizationList`

Authorized local users SDDL.

`wszPackageId`

Application Container Package Id Sid.

`wszLocalUserOwner`

User owner of the rule.

`dwTrustTupleKeywords`

Trust tuple keywords.

`OnNetworkNames`

TBD

`wszSecurityRealmId`

Security realm identifier.

`wFlags2`

Bit flags from **FW_RULE_FLAGS2**.

`RemoteOutServerNames`

TBD

`wszFqbn`

TBD

`compartmentId`

TBD

## Requirements

|   |   |
| ---- |:---- |
| **Minimum supported client** | Windows 11, version 23H2 [desktop apps only] |
| **Target Platform** | Windows |
| **Header** | None |