# IsReparseTagMicrosoft macro

## Syntax

```cpp
ULONG IsReparseTagMicrosoft(
    ULONG _tag
);
```

## Return value

Type: **ULONG**

A nonzero return value indicates that the tag is a Microsoft tag. A zero return value indicates that the tag is not a Microsoft tag. Only software developed by Microsoft or in partnership with Microsoft can use Microsoft tags. All other software must use non-Microsoft tags.

## Description

Determines whether a reparse point tag indicates a Microsoft reparse point.

## Parameters

### `_tag`

The reparse point tag to be tested.

## Remarks

If the Microsoft tag bit is set, Microsoft provides the tag. All other tags must use zero for this bit.

## See also

[FSCTL_GET_REPARSE_POINT](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_reparse_point)

[Reparse Points](https://learn.microsoft.com/windows/desktop/FileIO/reparse-points)