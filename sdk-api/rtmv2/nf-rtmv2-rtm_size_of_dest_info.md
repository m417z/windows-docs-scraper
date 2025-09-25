# RTM_SIZE_OF_DEST_INFO macro

## Syntax

```cpp
ULONG RTM_SIZE_OF_DEST_INFO(
     NumViews
);
```

## Return value

Type: **ULONG**

The return value is the size of the destination information structure with the specified number of views.

## Description

The **RTM_SIZE_OF_DEST_INFO** macro returns the size of the destination information structure ([RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info)). The size of this structure is variable, and is based on the number of views for which it contains information. Use this macro when allocating memory for destination information.

## Parameters

### `NumViews`

Specifies the number of views in the destination structure.

## Remarks

If the client only uses one view per destination, the client can allocate an
[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info) structure statically.

The macro is defined as follows:

```cpp
#include <windows.h>

#define RTM_DEST_VIEW_INFO_SIZE                             \
    FIELD_OFFSET(RTM_DEST_INFO, ViewInfo)

#define RTM_SIZE_OF_DEST_INFO(NumViews)                     \
    (sizeof(RTM_DEST_INFO) - RTM_BASIC_DEST_INFO_SIZE)

#define RTM_BASIC_DEST_INFO_SIZE                            \
    (RTM_BASIC_DEST_INFO_SIZE + (NumViews) *                \
    RTM_DEST_VIEW_INFO_SIZE)

```