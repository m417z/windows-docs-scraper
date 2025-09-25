# DXGI_DEBUG_RLO_FLAGS enumeration

## Description

Flags used with [ReportLiveObjects](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nf-dxgidebug-idxgidebug-reportliveobjects) to specify the amount of info to report about an object's lifetime.

## Constants

### `DXGI_DEBUG_RLO_SUMMARY:0x1`

A flag that specifies to obtain a summary about an object's lifetime.

### `DXGI_DEBUG_RLO_DETAIL:0x2`

A flag that specifies to obtain detailed info about an object's lifetime.

### `DXGI_DEBUG_RLO_IGNORE_INTERNAL:0x4`

This flag indicates to ignore objects which have no external refcounts keeping them alive.
D3D objects are printed using an external refcount and an internal refcount.
Typically, all objects are printed.
This flag means ignore the objects whose external refcount is 0, because the application is not responsible for keeping them alive.

### `DXGI_DEBUG_RLO_ALL:0x7`

A flag that specifies to obtain both a summary and detailed info about an object's lifetime.

## Remarks

Use this enumeration with [IDXGIDebug::ReportLiveObjects](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nf-dxgidebug-idxgidebug-reportliveobjects).

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[DXGI Enumerations](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-enums)