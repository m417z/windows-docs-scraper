# RTM_REGN_PROFILE structure

## Description

The
**RTM_REGN_PROFILE** structure contains information returned during the registration process. The information is used for later function calls (such as the maximum number of routes that can be returned by a call to
[RtmGetEnumRoutes](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetenumroutes)).

## Members

### `MaxNextHopsInRoute`

Specifies the maximum number of equal-cost next hops in a route.

### `MaxHandlesInEnum`

Specifies the maximum number of handles that can be returned in one call to
[RtmGetEnumDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetenumdests),
[RtmGetChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetchangeddests),
[RtmGetEnumRoutes](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetenumroutes), or
[RtmGetListEnumRoutes](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetlistenumroutes). The number of handles that can be returned is limited (and configurable) to improve efficiency and performance of the routing table manager.

### `ViewsSupported`

Views supported by this address family.

### `NumberOfViews`

Number of views.

## See also

[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity)