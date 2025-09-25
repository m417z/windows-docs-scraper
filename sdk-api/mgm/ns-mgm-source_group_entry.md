# SOURCE_GROUP_ENTRY structure

## Description

The
**SOURCE_GROUP_ENTRY** structure describes the entry returned by the group enumeration function
[MgmGroupEnumerationGetNext](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgroupenumerationgetnext).

## Members

### `dwSourceAddr`

Specifies the source address from which to receive multicast data. Specify zero to receive data from all sources (a wildcard receiver for a group); otherwise, specify the IP address of the source or source network.

To specify a range of source addresses, specify the source network using **dwSourceAddr**, and specify a subnet mask using **dwSourceMask**.

### `dwSourceMask`

Specifies the subnet mask that corresponds to **dwSourceAddr**. The **dwSourceAddr** and **dwSourceMask** parameters are used together to define a range of sources from which to receive multicast data.

Specify zero for this parameter if zero was specified for **dwSourceAddr** (a wildcard receiver).

### `dwGroupAddr`

Specifies the multicast group for which to receive data. Specify zero to receive all groups (a wildcard receiver); otherwise, specify the IP address of the group.

To specify a range of group addresses, specify the group address using **dwGroupAddr**, and specify a subnet mask using **dwGroupMask**.

### `dwGroupMask`

Specifies the subnet mask that corresponds to **dwGroupAddr**. The **dwGroupAddr** and **dwGroupMask** parameters are used together to define a range of multicast groups.

Specify zero for this parameter if zero was specified for **dwGroupAddr** (a wildcard receiver).

## See also

[MGM_ENUM_TYPES](https://learn.microsoft.com/windows/desktop/api/mgm/ne-mgm-mgm_enum_types)

[MgmGroupEnumerationEnd](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgroupenumerationend)

[MgmGroupEnumerationGetNext](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgroupenumerationgetnext)

[MgmGroupEnumerationStart](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgroupenumerationstart)