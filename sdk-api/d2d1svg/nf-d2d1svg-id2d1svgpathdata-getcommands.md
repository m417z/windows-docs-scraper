# ID2D1SvgPathData::GetCommands

## Description

Gets commands from the commands array.

## Parameters

### `commands` [out]

Type: **[D2D1_SVG_PATH_COMMAND](https://learn.microsoft.com/windows/desktop/api/d2d1svg/ne-d2d1svg-d2d1_svg_path_command)***

Buffer to contain the commands.

### `commandsCount`

Type: **UINT32**

The element count of the buffer.

### `startIndex`

Type: **UINT32**

The index of the first commands to retrieve.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1SvgPathData](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgpathdata)