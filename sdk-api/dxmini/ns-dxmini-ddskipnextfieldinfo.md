# DDSKIPNEXTFIELDINFO structure

## Description

The DDSKIPNEXTFIELDINFO structure contains the skip information for the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object.

## Members

### `lpVideoPortData`

Points to a [DDVIDEOPORTDATA](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddvideoportdata) structure that represents the VPE object.

### `dwSkipFlags`

Indicates whether to skip the next field. One of the following:

| Flag | Meaning |
| --- | --- |
| DDSKIP_ENABLENEXT | The next field should be restored. |
| DDSKIP_SKIPNEXT | The next field should be skipped. |

## See also

[DDVIDEOPORTDATA](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddvideoportdata)

[DxSkipNextField](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_skipnextfield)