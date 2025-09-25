## Description

The *DxSkipNextField* callback function is called when the next field needs to be skipped or reenabled.

## Parameters

### `unnamedParam1`
Points to the miniport driver's device extension.

### `unnamedParam2`
Points to a [DDSKIPNEXTFIELDINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddskipnextfieldinfo) structure that contains the skip information for the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object.

### `unnamedParam3`
Reserved for system use.

## Return value

*DxSkipNextField* returns DX_OK if it succeeds; otherwise, it returns one of the following error values:

## Remarks

If the **dwSkipFlags** member of the DDSKIPNEXTFIELDINFO structure at *SkipNextFieldInfo* is DDSKIP_SKIPNEXT, the following field should be skipped. If the vertical blanking interval (VBI) height is greater than zero, only the video data should be skipped (not the VBI data). If **dwSkipFlags** is set to DDSKIP_ENABLENEXT, the next field should be restored.

## See also

[DDSKIPNEXTFIELDINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddskipnextfieldinfo)