# _DXGK_MITIGATEDRANGEINFO structure

## Description

The list of pages in the virtual function’s BARs that need to be mitigated.

## Members

### `BasePageNumber`

Offset of the range from the beginning of the BAR.

### `PageCount`

Number of pages in the range. A mitigated range size should not exceed 2 GB. When the driver needs to mitigate a range, which is bigger than 2GB, it needs to report multiple consecutive ranges. There is no limit on the number of mitigate ranges the driver can report.

### `InterceptReads`

Set this to TRUE to mitigate reads to the range.

### `InterceptWrites`

Set this to TRUE to mitigates writes to the range.

## Remarks

## See also