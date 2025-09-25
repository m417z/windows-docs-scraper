# RTM_DEST_INFO structure

## Description

The
**RTM_DEST_INFO** structure is used to exchange destination information with clients registered with the routing table manager.

## Members

### `DestHandle`

Handle to the destination.

### `DestAddress`

Specifies the destination network address as an address and a mask.

### `LastChanged`

Specifies the last time this destination was updated.

### `BelongsToViews`

Specifies the views to which this destination belongs.

### `NumberOfViews`

Indicates the number of ViewInfo structures present in this destination.

### `ViewId`

### `NumRoutes`

### `Route`

### `Owner`

### `DestFlags`

### `HoldRoute`

### `ViewInfo`

Structure of the following components.

#### ViewId

Specifies the view to which this information applies.

#### NumRoutes

Specifies the number of routes in each of the supported views.

#### Route

Handle to the best route (with matching criteria) in each of the supported views.

#### Owner

Handle to the owner of the best route in each of the supported views.

#### DestFlags

Specifies the flags for the best route in each of the supported views.

#### HoldRoute

Handle to the route that is in a hold-down state in each of the supported views.

## See also

[RTM_NET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_net_address)

[RtmGetChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetchangeddests)

[RtmGetDestInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetdestinfo)

[RtmGetEnumDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetenumdests)

[RtmGetExactMatchDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetexactmatchdestination)

[RtmGetLessSpecificDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetlessspecificdestination)

[RtmGetMostSpecificDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetmostspecificdestination)

[RtmReleaseChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasechangeddests)

[RtmReleaseDestInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasedestinfo)

[RtmReleaseDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasedests)