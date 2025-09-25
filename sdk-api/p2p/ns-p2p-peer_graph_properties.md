# PEER_GRAPH_PROPERTIES structure

## Description

The **PEER_GRAPH_PROPERTIES** structure contains data about the policy of a peer graph, ID, scope, and other information.

## Members

### `dwSize`

Specifies the size, in bytes, of this data structure. The **dwSize** member must be set to the size of **PEER_GRAPH_PROPERTIES** before calling [PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate). This member is required. There is not a default value.

### `dwFlags`

Flags that control the behavior of a peer in a graph. The default is does not have flags set. The valid value is identified in the following table.

| Value | Description |
| --- | --- |
| **PEER_GRAPH_PROPERTY_DEFER_EXPIRATION** | Specifies when to expire a graph record. When a graph is not connected and this flag is set, expiration does not occur until the graph connects to at least one other member. |

### `dwScope`

Specifies the scope in which the peer graph ID is published. The default value is global. Valid values are identified in the following table.

| Value | Description |
| --- | --- |
| **PEER_GRAPH_SCOPE_GLOBAL** | Scope includes the Internet. |
| **PEER_GRAPH_SCOPE_LINK_LOCAL** | Scope is restricted to a local subnet. |
| **PEER_GRAPH_SCOPE_SITE_LOCAL** | Scope is restricted to a site, for example, a corporation intranet. |

### `dwMaxRecordSize`

Specifies the value that indicates the largest record that can be added to a peer graph. A valid value is zero (0), which indicates that the default maximum record size is used (60 megabytes), and any value between 1024 bytes and 60 megabytes.

### `pwzGraphId`

Specifies the unique identifier for a peer graph. This ID must be unique for the computer/user pair. This member is required and has no default value. If the string value is greater than 256 characters (including the null terminator), an error is returned.

### `pwzCreatorId`

Specifies the unique identifier for the creator of a peer graph. This member is required and has no default value. If the string value is greater than 256 characters (including the null terminator), an error is returned.

### `pwzFriendlyName`

Specifies the friendly name of a peer graph. This member is optional and can be **NULL**. The default value is **NULL**. The maximum length of this string is 256 characters, including the null terminator.

### `pwzComment`

Specifies the comment used to describe a peer graph. This member is optional and can be **NULL**. The default value is **NULL**. The maximum length of this string is 512 characters, including the null terminator.

### `ulPresenceLifetime`

Specifies the number of seconds before a presence record expires. The default value is 300 seconds (5 minutes). Do not set the value of **ulPresenceLifetime** to less than 300 seconds. If this member is set less than the 300 (5 minutes) default value, then undefined behavior can occur.

### `cPresenceMax`

Specifies how many presence records the Peer Infrastructure keeps in a peer graph at one time. A node that has its presence published can be enumerated by all other nodes with [PeerGraphEnumNodes](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumnodes). Specify how presence records for users are published by specifying one of the values identified in the following table.

| Value | Description |
| --- | --- |
| -1 | Presence records are automatically published for all users. |
| 0 | Presence records are not automatically published. |
| 1-N | Up to N number of presence records are published at one time. The presence records that are published are randomly chosen by the Peer Graphing Infrastructure. |

## Remarks

An application can force the Peer Graphing Infrastructure to publish presence information by using [PeerGraphSetPresence](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphsetpresence).

Only specific fields in the **PEER_GRAPH_PROPERTIES** can be updated when calling [PeerGraphSetProperties](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphsetproperties). The following members can be updated:

* **pwzFriendlyName**
* **pwzComment**
* **ulPresenceLifetime**
* **cPresenceMax**

The remaining members cannot be modified.

## See also

[PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate)

[PeerGraphGetProperties](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetproperties)

[PeerGraphSetProperties](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphsetproperties)