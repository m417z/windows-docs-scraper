## Description

The **DrvUnidriverTextOut** function is obsolete.

Windows 2000 and later printer drivers should use [IPrintOemDriverUni::DrvUniTextOut](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriveruni-drvunitextout).

This function pointer prototype defines the type of the **DrvUnidriverTextOut** member of the [DRVPROCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_drvprocs) structure.

## Parameters

### `pso`

Defines the **SURFOBJ** parameter *pso*.

### `pstro`

Defines the **STROBJ** parameter *pstro*.

### `pfo`

Defines the **FONTOBJ** parameter *pfo*.

### `pco`

Defines the **CLIPOBJ** parameter *pco*.

### `prclExtra`

Defines the **RECTL** parameter *prclExtra*.

### `prclOpaque`

Defines the **RECTL** parameter *prclOpaque*.

### `pboFore`

Defines the **BRUSHOBJ** parameter *pboFore*.

### `pboOpaque`

Defines the **BRUSHOBJ** parameter *pboOpaque*.

### `pptlBrushOrg`

Defines the **POINTL** parameter *pptlBrushOrg*.

### `mix`

Defines the **MIX** parameter *mix*.

## Return value

Returns a **BOOL** value.