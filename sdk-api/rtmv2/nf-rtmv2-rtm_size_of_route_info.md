# RTM_SIZE_OF_ROUTE_INFO macro

## Syntax

```cpp
ULONG RTM_SIZE_OF_ROUTE_INFO(
     NumHops
);
```

## Return value

Type: **ULONG**

The return value is the size of the route information structure with the specified number of next hops.

## Description

The **RTM_SIZE_OF_ROUTE_INFO** macro returns the size of the route information structure, [RTM_ROUTE_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_route_info). The size of this structure is variable, and is based on the number of next hops associated with the route. Use this macro when allocating memory for route structures.

## Parameters

### `NumHops`

Specifies the number of next hops in the route structure.

## Remarks

If the client only allocates one next hop per route, the client can allocate an
[RTM_ROUTE_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_route_info) structure statically.

The macro is defined as follows:

```cpp
#include <windows.h>

#define RTM_SIZE_OF_ROUTE_INFO(NumHops)                     \
    FIELD_OFFSET(RTM_ROUTE_INFO, NextHopsList.NumNextHops)

#define RTM_BASIC_ROUTE_INFO_SIZE                           \
    (RTM_BASIC_ROUTE_INFO_SIZE + (NumHops) *                \
     sizeof(RTM_NEXTHOP_HANDLE))

```