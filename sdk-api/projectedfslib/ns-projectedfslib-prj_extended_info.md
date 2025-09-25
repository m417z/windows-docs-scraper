# PRJ_EXTENDED_INFO structure

## Description

A provider uses PRJ_EXTENDED_INFO to provide extended information about a file when calling [PrjFillDirEntryBuffer2](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjfilldirentrybuffer2) or [PrjWritePlaceholderInfo2](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjwriteplaceholderinfo2).

## Members

### `InfoType`

A [PRJ_EXT_INFO](https://learn.microsoft.com/windows/desktop/api/projectedfslib/ne-projectedfslib-prj_ext_info_type) value describing what kind of extended information this structure contains.

### `NextInfoOffset`

Offset in bytes from the beginning of this structure to the next PRJ_EXTENDED_INFO structure. If this is the last structure in the buffer this value must be 0.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Symlink`

The fields in this struct are used if InfoType is PRJ_EXT_INFO_TYPE_SYMLINK.

### `DUMMYUNIONNAME.Symlink.TargetName`

Specifies the name of the target of a symbolic link.

## Remarks

## See also