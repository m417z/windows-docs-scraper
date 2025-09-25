# _D3DHAL_DP2SETLIGHT structure

## Description

The D3DHAL_DP2SETLIGHT structure allows lights to be set for [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

## Members

### `dwIndex`

Specifies an index into an array of lights.

### `dwDataType`

Specifies the type of data being passed.

|Value|Meaning|
|--- |--- |
|D3DHAL_SETLIGHT_DATA|Specifies that a D3DLIGHT7 (described in the Microsoft Windows SDK documentation) structure defining the light follows immediately in the command stream.|
|D3DHAL_SETLIGHT_ENABLE|Enables the light whose index is specified in **dwIndex**.|
|D3DHAL_SETLIGHT_DISABLE|Disables the light whose index is specified in **dwIndex**.|

## See also

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)