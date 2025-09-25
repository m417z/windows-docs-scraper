# CF_PLACEHOLDER_RANGE_INFO_CLASS enumeration

## Description

Indicates the type of range info for the placeholder file data.

## Constants

### `CF_PLACEHOLDER_RANGE_INFO_ONDISK:1`

On-disk data is data that is physical present in the file, which is a super set of other types of ranges.

### `CF_PLACEHOLDER_RANGE_INFO_VALIDATED:2`

Validated data is a subset of the on-disk data that is currently in sync with the cloud.

### `CF_PLACEHOLDER_RANGE_INFO_MODIFIED:3`

Modified data is a subset of the on-disk data that is currently not in sync with the cloud, i.e., either modified or appended.

## See also

[CfGetPlaceholderRangeInfo](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgetplaceholderrangeinfo)