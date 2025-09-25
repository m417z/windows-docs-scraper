# ID2D1SvgDocument::CreatePathData

## Description

Creates a path data object which can be used to set a 'd' attribute on a 'path' element.

## Parameters

### `segmentData` [in, optional]

Type: **const FLOAT***

An array of segment data.

### `segmentDataCount`

Type: **UINT32**

Number of items in segmentData.

### `commands` [in, optional]

Type: **const [D2D1_SVG_PATH_COMMAND](https://learn.microsoft.com/windows/desktop/api/d2d1svg/ne-d2d1svg-d2d1_svg_path_command)***

An array of path commands.

### `commandsCount`

Type: **UINT32**

The number of items in commands.

### `pathData` [out]

Type: **ID2D1SvgPathData****

When this method completes, this points to the created path data.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1SvgDocument](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgdocument)