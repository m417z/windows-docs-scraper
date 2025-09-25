# ID2D1SvgPathData::UpdateCommands

## Description

Updates the commands array. Existing commands not updated by this method are preserved.
The array is resized larger if necessary to accommodate the new commands.

## Parameters

### `commands` [in]

Type: **const [D2D1_SVG_PATH_COMMAND](https://learn.microsoft.com/windows/desktop/api/d2d1svg/ne-d2d1svg-d2d1_svg_path_command)***

The commands array.

### `commandsCount`

Type: **UINT32**

The number of commands to update.

### `startIndex`

Type: **UINT32**

The index at which to begin updating commands. Must be less than or equal to the size of the commands array.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1SvgPathData](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgpathdata)