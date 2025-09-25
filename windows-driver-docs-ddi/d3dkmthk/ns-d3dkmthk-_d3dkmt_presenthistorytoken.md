# _D3DKMT_PRESENTHISTORYTOKEN structure

## Description

The **D3DKMT_PRESENTHISTORYTOKEN** structure identifies a type of present operation.

## Syntax

```cpp
typedef struct _D3DKMT_PRESENTHISTORYTOKEN
{
    D3DKMT_PRESENT_MODEL  Model;
    UINT                  TokenSize;

#if (DXGKDDI_INTERFACE_VERSION >= DXGKDDI_INTERFACE_VERSION_WIN8)
    UINT64                CompositionBindingId;
#endif

    union
    {
        D3DKMT_FLIPMODEL_PRESENTHISTORYTOKEN        Flip;
        D3DKMT_BLTMODEL_PRESENTHISTORYTOKEN         Blt;
        D3DKMT_VISTABLTMODEL_PRESENTHISTORYTOKEN    VistaBlt;
        D3DKMT_GDIMODEL_PRESENTHISTORYTOKEN         Gdi;
        D3DKMT_FENCE_PRESENTHISTORYTOKEN            Fence;
        D3DKMT_GDIMODEL_SYSMEM_PRESENTHISTORYTOKEN  GdiSysMem;
        D3DKMT_COMPOSITION_PRESENTHISTORYTOKEN      Composition;
        D3DKMT_FLIPMANAGER_PRESENTHISTORYTOKEN      FlipManager;
#if (DXGKDDI_INTERFACE_VERSION >= DXGKDDI_INTERFACE_VERSION_WDDM2_1)
        D3DKMT_SURFACECOMPLETE_PRESENTHISTORYTOKEN  SurfaceComplete;
#endif
    }
    Token;
} D3DKMT_PRESENTHISTORYTOKEN;
```

## Members

### `Model` [in]

A [D3DKMT_PRESENT_MODEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_present_model) enum value that indicates the model for a present operation.

### `TokenSize` [in]

The size, in bytes, of the present history token including the value in the *Model* member. When you submit a token, you should set *TokenSize* to zero. When the ICD calls [D3DKMTGetPresentHistory](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetpresenthistory) to retrieve present history, the runtime initializes *TokenSize*. You can then use the value in *TokenSize* to go to the next token in the present-history buffer.

A *present history token* is a data packet that the rendering app submits to inform the Desktop Window Manager (DWM) that rendering is complete and the swap chain back buffer is ready to be presented.

### `CompositionBindingId`

The identifier of the active bound buffer of the composition surface.

Supported starting with Windows 8.

### `Token`

A present history token.

### `Token.Flip` [in/out]

A [D3DKMT_FLIPMODEL_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_flipmodel_presenthistorytoken) structure that identifies a flip present-history operation. The *Token* union that is contained in D3DKMT_PRESENTHISTORYTOKEN holds this structure if the *Model* member is D3DKMT_PM_REDIRECTED_FLIP.

### `Token.Blt` [in/out]

A [D3DKMT_BLTMODEL_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_bltmodel_presenthistorytoken) structure that identifies a bit-block transfer (bitblt) present-history operation. The union that is contained in D3DKMT_PRESENTHISTORYTOKEN holds a structure of this type if the *Model* member is D3DKMT_PM_REDIRECTED_BLT.

### `Token.VistaBlt` [in/out]

A ULONGLONG value that identifies a Windows Vista bit-block transfer (bitblt) present-history operation. The union that is contained in D3DKMT_PRESENTHISTORYTOKEN holds a value of this type if the *Model* member is D3DKMT_PM_REDIRECTED_VISTABLT.

### `Token.Gdi` [in/out]

A [D3DKMT_GDIMODEL_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_gdimodel_presenthistorytoken) structure that identifies a GDI present-history operation. The union that is contained in D3DKMT_PRESENTHISTORYTOKEN holds a structure of this type if the *Model* member is D3DKMT_PM_REDIRECTED_GDI.

### `Token.Fence` [in/out]

A [D3DKMT_FENCE_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_fence_presenthistorytoken) structure that identifies a fence present-history operation. The union that is contained in D3DKMT_PRESENTHISTORYTOKEN holds a structure of this type if the *Model* member is D3DKMT_PM_SCREENCAPTUREFENCE.

### `Token.GdiSysMem` [in/out]

A [D3DKMT_GDIMODEL_SYSMEM_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_gdimodel_sysmem_presenthistorytoken) structure that identifies a GDI system present-history operation. The union that is contained in D3DKMT_PRESENTHISTORYTOKEN holds a structure of this type if the *Model* member is D3DKMT_PM_REDIRECTED_GDI_SYSMEM.

### `Token.Composition` [in/out]

A [D3DKMT_COMPOSITION_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_composition_presenthistorytoken) structure that identifies a composition swap chain present-history operation. This type of presentation is used for XAML-based apps.

Supported starting with Windows 8.1.

### `Token.FlipManager`

A [D3DKMT_FLIPMANAGER_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_surfacecomplete_presenthistorytoken) structure that identifies a flip manager operation.

### `Token.SurfaceComplete`

A [D3DKMT_SURFACECOMPLETE_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_surfacecomplete_presenthistorytoken) structure that identifies a surface complete operation.

Supported starting with Windows 10, version 1607.

## See also

[D3DKMT_PRESENT_MODEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_present_model)

[D3DKMTGetPresentHistory](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetpresenthistory)

[D3DKMT_FLIPMODEL_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_flipmodel_presenthistorytoken)

[D3DKMT_BLTMODEL_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_bltmodel_presenthistorytoken)

[D3DKMT_GDIMODEL_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_gdimodel_presenthistorytoken)

[D3DKMT_FENCE_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_fence_presenthistorytoken)

[D3DKMT_GDIMODEL_SYSMEM_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_gdimodel_sysmem_presenthistorytoken)

[D3DKMT_COMPOSITION_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_composition_presenthistorytoken)

[D3DKMT_FLIPMANAGER_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_surfacecomplete_presenthistorytoken)

[D3DKMT_SURFACECOMPLETE_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_surfacecomplete_presenthistorytoken)