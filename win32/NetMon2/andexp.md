# ANDEXP structure

The **ANDEXP** structure contains an array of pattern matches used to evaluate frame data.

## Members

**nPatternMatches**

Number of pattern matches.

**PatternMatch**

Array of pattern match elements. Note that each **ANDEXP** structure can contain up to four pattern match elements. For more information about this member, see [Capture Filters](https://learn.microsoft.com/windows/win32/netmon2/capture-filters).

## Remarks

The patterns in the **PatternMatch**\[MAX\_PATTERNS\] array are joined as peers in logical OR statements in the format

(Pattern 1 \|\| Pattern 2 \|\| Pattern 3).

For more information about implementing this structure, see [Capture Filters](https://learn.microsoft.com/windows/win32/netmon2/capture-filters) .

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[PATTERNMATCH](https://learn.microsoft.com/windows/win32/netmon2/patternmatch)

