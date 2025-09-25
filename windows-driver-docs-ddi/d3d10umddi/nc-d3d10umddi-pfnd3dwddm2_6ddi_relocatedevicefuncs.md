# PFND3DWDDM2_6DDI_RELOCATEDEVICEFUNCS callback function

## Description

The RelocateDeviceFuncs function notifies the user-mode display driver about the new location of the driver function table.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pDeviceFunctions* [in]

A pointer to a D3DWDDM2_6DDI_DEVICEFUNCS structure that contains pointers to the functions of the user-mode display driver.

## Prototype

```
//Declaration

PFND3DWDDM2_6DDI_RELOCATEDEVICEFUNCS Pfnd3dwddm26DdiRelocatedevicefuncs;

// Definition

VOID Pfnd3dwddm26DdiRelocatedevicefuncs
(
	D3D10DDI_HDEVICE Arg1
	D3DWDDM2_6DDI_DEVICEFUNCS *
)
{...}

```

## Remarks

## See also