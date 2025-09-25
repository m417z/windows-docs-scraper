## Description

The **LINK_TRACKING_INFORMATION** structure contains the link tracking information of the file.

## Members

### `Type`

A [**LINK_TRACKING_INFORMATION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-link_tracking_information_type) value that specifies the type of file system that the file resides on.

### `VolumeId[16]`

An unsigned character array that holds the volume identifier.

## Remarks

## See also

[**FSCTL_LMR_GET_LINK_TRACKING_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-lmr-get-link-tracking-information)