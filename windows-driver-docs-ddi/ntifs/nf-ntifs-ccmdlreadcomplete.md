# CcMdlReadComplete function

## Description

The **CcMdlReadComplete** routine frees the memory descriptor lists (MDL) created by [CcMdlRead](https://learn.microsoft.com/previous-versions/ff539159(v=vs.85)) for a cached file.

## Parameters

### `FileObject` [in]

File object pointer that was passed to [CcMdlRead](https://learn.microsoft.com/previous-versions/ff539159(v=vs.85)).

### `MdlChain` [in]

Address of the MDL chain returned by [CcMdlRead](https://learn.microsoft.com/previous-versions/ff539159(v=vs.85)).

## Remarks

**CcMdlReadComplete** frees the memory descriptor lists (MDL) created by [CcMdlRead](https://learn.microsoft.com/previous-versions/ff539159(v=vs.85)) for a cached file. All physical pages that were locked down are unlocked. Any pages that were mapped are unmapped.

Each call to [CcMdlRead](https://learn.microsoft.com/previous-versions/ff539159(v=vs.85)) must be followed by a call to **CcMdlReadComplete**.

## See also

[CcMdlRead](https://learn.microsoft.com/previous-versions/ff539159(v=vs.85))