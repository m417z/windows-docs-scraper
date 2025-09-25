# _D3DKMT_PRESENT_MODEL enumeration

## Description

The D3DKMT_PRESENT_MODEL enumeration type contains values that indicate the model for a present operation.

## Constants

### `D3DKMT_PM_UNINITIALIZED`

The present-operation model is not initialized.

### `D3DKMT_PM_REDIRECTED_GDI`

The present-operation model is redirected GDI.

### `D3DKMT_PM_REDIRECTED_FLIP`

The present-operation model is redirected flip.

### `D3DKMT_PM_REDIRECTED_BLT`

The present-operation model is redirected bit-block transfer (bitblt).

### `D3DKMT_PM_REDIRECTED_VISTABLT`

The present-operation model is redirected Windows Vista bitblt.

### `D3DKMT_PM_SCREENCAPTUREFENCE`

The present-operation model is screen capture through a fence.

### `D3DKMT_PM_REDIRECTED_GDI_SYSMEM`

The present-operation model is redirected system GDI.

### `D3DKMT_PM_REDIRECTED_COMPOSITION`

The present-operation model is redirected composition swap chain presentation. This type of presentation is used for XAML-based apps.

### `D3DKMT_PM_SURFACECOMPLETE`

### `D3DKMT_PM_FLIPMANAGER` :

## Syntax

```cpp
typedef enum _D3DKMT_PRESENT_MODEL {
  D3DKMT_PM_UNINITIALIZED           = 0,
  D3DKMT_PM_REDIRECTED_GDI          = 1,
  D3DKMT_PM_REDIRECTED_FLIP         = 2,
  D3DKMT_PM_REDIRECTED_BLT          = 3,
  D3DKMT_PM_REDIRECTED_VISTABLT     = 4,
  D3DKMT_PM_SCREENCAPTUREFENCE      = 5,
  D3DKMT_PM_REDIRECTED_GDI_SYSMEM   = 6,
  D3DKMT_PM_REDIRECTED_COMPOSITION  = 7
} D3DKMT_PRESENT_MODEL;
```

## See also

[D3DKMT_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_presenthistorytoken)