# DXGIDDICB_PRESENT_MULTIPLANE_OVERLAY1 structure

## Description

Describes multiplane overlay allocations, private driver data, and context information for each multiplane overlay plane.

## Members

### `pDXGIContext`

A handle to the DXGI context. This handle is opaque to the driver. The driver should assign the handle from the pDXGIContext member DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY1 structure that the driver received in a call to its pfnPresentMultiplaneOverlay function to this member.

### `PresentPlaneCount`

The number of planes in the array that the ppPresentPlanes member specifies.

### `ppPresentPlanes`

An array of pointers to a structure of type DXGIDDI_MULTIPLANE_OVERLAY_PLANE_INFO that specify information about the multiplane overlay planes.