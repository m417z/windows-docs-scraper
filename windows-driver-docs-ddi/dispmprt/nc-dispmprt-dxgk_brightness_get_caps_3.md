# DXGK_BRIGHTNESS_GET_CAPS_3 callback function

## Description

Implemented by the client driver to retrieve the brightness control capabilities of an integrated display panel.

## Parameters

### `Context` [in]

A handle to a context block that is associated with a display adapter.

### `ChildUid` [in]

An integer that uniquely identifies the child device. The display miniport driver's [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations) function previously provided this identifier to the display port driver.

### `pBrightnessCaps:` [out]

Pointer to a [DXGK_BRIGHTNESS_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_brightness_caps) structure that represents the brightness control capabilities of the display panel.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code defined in ntstatus.h.

## Prototype

```cpp
//Declaration

DXGK_BRIGHTNESS_GET_CAPS_3 DxgkBrightnessGetCaps3;

// Definition

NTSTATUS DxgkBrightnessGetCaps3
(
	PVOID Context
	ULONG ChildUid
	DXGK_BRIGHTNESS_CAPS *pBrightnessCaps
)
{...}

DXGK_BRIGHTNESS_GET_CAPS_3

```

## Remarks

Any device supporting the Brightness3 interface must support transition times, so SmoothBrightness is no longer used.

The NitsBrightness bit has been introduced to represent support for calibrated nit-based brightness. If the device does not support nit-based brightness, brightness levels will still be represented in millinits, but the operating system will be aware that they don’t map to known absolute brightness levels.