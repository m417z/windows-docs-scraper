# IApplicationDesignModeSettings2::SetAdjacentDisplayEdges

## Description

Sets whether the application window will be adjacent to the edge of the emulated display.

## Parameters

### `adjacentDisplayEdges` [in]

Type: **ADJACENT_DISPLAY_EDGES**

The edge which should be adjacent.

#### ADE_NONE (0x0)

The widow will not be adjacent to either edge.

#### ADE_LEFT (0x1)

the left edge of the window will be adjacent.

#### ADE_RIGHT (0x2)

The right edge of the window will be adjacent.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IApplicationDesignModeSettings](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationdesignmodesettings)

[IApplicationDesignModeSettings2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationdesignmodesettings2)