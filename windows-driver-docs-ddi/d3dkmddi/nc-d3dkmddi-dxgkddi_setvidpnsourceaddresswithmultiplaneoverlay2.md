# DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY2 callback function

> [!NOTE] This callback has been replaced by [DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay3)

## Description

**DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay2** is called to change the overlay configuration being displayed. It must be implemented by Windows Display Driver Model (WDDM) 2.0 or later drivers that support multi-plane overlays.

## Parameters

### `hAdapter`

Identifies the adapter containing the overlay hardware.

### `pSetVidPnSourceAddressWithMultiPlaneOverlay` [in]

A pointer to a [DXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddresswithmultiplaneoverlay2) structure that describes the surfaces and display options to present.

## Return value

If this routine succeeds, it returns **NTSTATUS_SUCCESS**. The driver should always return a success code.

## See also

[DXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddresswithmultiplaneoverlay2)