# IsReparseTagNameSurrogate macro

## Syntax

```cpp
ULONG IsReparseTagNameSurrogate(
    ULONG _tag
);
```

## Return value

Type: **ULONG**

A nonzero return value means that the tag indicates a surrogate reparse point. A zero return value means that the tag does not indicate a surrogate reparse point.

## Description

Determines whether a tag's associated reparse point is a surrogate for another named entity (for example, a mounted folder).

## Parameters

### `_tag`

The reparse point tag to be tested for surrogacy.

## Remarks

If the surrogacy bit is set, the file or directory represents another named entity in the system, such as a mounted folder that associates this directory with another volume. For more information on volume mounting, see
[Mounted Folders](https://learn.microsoft.com/windows/desktop/FileIO/volume-mount-points).

## See also

[FSCTL_GET_REPARSE_POINT](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_reparse_point)

[Reparse Points](https://learn.microsoft.com/windows/desktop/FileIO/reparse-points)