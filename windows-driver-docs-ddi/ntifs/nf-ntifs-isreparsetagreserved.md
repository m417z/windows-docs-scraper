## Description

The **IsReparseTagReserved** macro determines whether a reparse point tag is reserved by Microsoft.

## Parameters

### `_tag`

[in] Reparse point tag to be tested.

## Remarks

Third-party reparse points must use non-Microsoft tags. However, third-party drivers can set Microsoft reparse points. For more information, see the Remarks section of the reference entry for the [**REPARSE_GUID_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_guid_data_buffer) structure.

For more information about reparse points, see [Reparse Points](https://learn.microsoft.com/windows-hardware/drivers/ifs/reparse-points).

## See also

[**IsReparseTagMicrosoft**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-isreparsetagmicrosoft)

[**REPARSE_GUID_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_guid_data_buffer)