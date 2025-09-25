## Description

The **OEMStretchBltROP** function performs a stretching bit-block transfer using a [raster operation (ROP)](https://learn.microsoft.com/windows-hardware/drivers/).

## Parameters

### `psoDest`

Defines the **SURFOBJ** parameter *psoDest*.

### `psoSrc`

Defines the **SURFOBJ** parameter *psoSrc*.

### `psoMask`

Defines the **SURFOBJ** parameter *psoMask*.

### `pco`

Defines the **CLIPOBJ** parameter *pco*.

### `pxlo`

Defines the **XLATEOBJ** parameter *pxlo*.

### `pca`

Defines the **COLORADJUSTMENT** parameter *pca*.

### `pptlHTOrg`

Defines the **POINTL** parameter *pptlHTOrg*.

### `prclDest`

Defines the **RECTL** parameter *prclDest*.

### `prclSrc`

Defines the **RECTL** parameter *prclSrc*.

### `pptlMask`

Defines the **POINTL** parameter *pptlMask*.

### `iMode`

Defines the **ULONG** parameter *iMode*.

### `pbo`

Defines the **BRUSHOBJ** parameter *pbo*.

### `rop4`

Defines the **ROP4** parameter *rop4*.

## Return value

Returns a **BOOL** value.