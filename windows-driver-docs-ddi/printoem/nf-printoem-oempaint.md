## Description

The **OEMPaint** function is obsolete, and is no longer called by GDI in Windows 2000 and later. See [DrvPaint](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvpaint).

## Parameters

### `pso`

Defines the **SURFOBJ** parameter *pso*.

### `pco`

Defines the **CLIPOBJ** parameter *pco*.

### `pbo`

Defines the **BRUSHOBJ** parameter *pbo*.

### `pptlBrushOrg`

Defines the **POINTL** parameter *pptlBrushOrg*.

### `mix`

Defines the **MIX** parameter *mix*.

## Return value

Returns a **BOOL** value.

## Remarks

If you call into the core driver, cast the call using the **PFN_DrvPaint** function pointer.