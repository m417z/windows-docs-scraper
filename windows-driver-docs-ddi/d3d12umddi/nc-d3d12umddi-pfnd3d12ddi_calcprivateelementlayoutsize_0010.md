# PFND3D12DDI_CALCPRIVATEELEMENTLAYOUTSIZE_0010 callback function

## Description

The CalcPrivateElementLayoutSize function determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for an element layout.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

## Return value

Returns SIZE_T.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALCPRIVATEELEMENTLAYOUTSIZE_0010 Pfnd3d12ddiCalcprivateelementlayoutsize0010;

// Definition

SIZE_T Pfnd3d12ddiCalcprivateelementlayoutsize0010
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATEELEMENTLAYOUT_0010 *
)
{...}

PFND3D12DDI_CALCPRIVATEELEMENTLAYOUTSIZE_0010

```

## Remarks

## See also