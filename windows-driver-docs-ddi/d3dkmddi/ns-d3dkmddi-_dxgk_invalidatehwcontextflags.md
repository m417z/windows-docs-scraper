# DXGK_INVALIDATEHWCONTEXTFLAGS structure

## Description

**DXGK_INVALIDATEHWCONTEXTFLAGS** contains flag values associated with a context being invalidated.

## Members

### `CollateralDamage`

Identifies the scope of the collateral damage to the context being invalidated. **CollateralDamage** can be one of the following values.

| Value | Meaning |
| ----- | ------- |
| 0 | The context being invalidated was the primary cause of the engine hang. |
| 1 | The context being invalidated was not the primary cause of the engine hang, but still needs to be reset because it was affected by the hang. |

### `Reserved`

Reserved for internal use.

### `Value`

The value of the context flag.

## See also

[**DXGKARGCB_INVALIDATEHWCONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_invalidatehwcontext)

[**DXGKCB_INVALIDATEHWCONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_invalidatehwcontext)