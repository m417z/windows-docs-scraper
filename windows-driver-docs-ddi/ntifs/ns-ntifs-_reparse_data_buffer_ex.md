# _REPARSE_DATA_BUFFER_EX structure

## Description

The REPARSE_DATA_BUFFER_EX structure contains data for a reparse point.

## Members

### `Flags`

Can be the following value:

| Flag Value | Meaning |
| ---------- | ------- |
| REPARSE_DATA_EX_FLAG_GIVEN_TAG_OR_NONE | Forces [FSCTL_SET_REPARSE_POINT_EX](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-reparse-point-ex) to set the reparse tag if the file has no tag, or if the tag on the file is same as the one in *ExistingReparseTag*. NOTE: If *ExistingReparseTag* is not a Microsoft tag, then *ExistingReparseGuid* should match if the file already has the *ExistingReparseTag.* |

### `ExistingReparseTag`

Reparse point tag on the file, if any, if the caller wants to also replace the reparse tag.

* To set the reparse data along with a reparse tag that might be different, *ExistingReparseTag* should be the current reparse tag of the file.
* To update the reparse data while maintaining the same reparse tag, *ExistingReparseTag* should be the existing reparse tag.
* To set the reparse tag along with reparse data on a file that does not yet have a reparse tag, *ExistingReparseTag* should be set to zero.

### `ExistingReparseGuid`

For non-Microsoft reparse tags, this is the existing reparse GUID on the file, if any, when the caller wants to replace the reparse tag and/or GUID along with the data. If *ExistingReparseTag* is zero, the file is not expected to have any reparse tags, so *ExistingReparseGuid* is ignored. For non-Microsoft tags, *ExistingReparseGuid* should match the GUID in the file if *ExistingReparseTag* is non-zero.

### `Reserved`

Reserved. Do not use.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.ReparseDataBuffer`

A [REPARSE_DATA_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_data_buffer) structure that contains data for a Microsoft-defined reparse point.

### `DUMMYUNIONNAME.ReparseGuidDataBuffer`

A [REPARSE_GUID_DATA_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_guid_data_buffer) structure that contains data for a reparse point. Third party reparse points must use this structure.

## Remarks

The REPARSE_DATA_BUFFER_EX structure is used to store data for a reparse point. Use REPARSE_DATA_BUFFER_EX when setting a reparse point on a file or directory through the [FSCTL_SET_REPARSE_POINT_EX](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-reparse-point-ex) IOCTL.

## See also

[FSCTL_SET_REPARSE_POINT_EX](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-reparse-point-ex)

[REPARSE_DATA_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_data_buffer)

[REPARSE_GUID_DATA_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_guid_data_buffer)