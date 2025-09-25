# D3DKMT_CHECK_MULTIPLANE_OVERLAY_SUPPORT_RETURN_INFO structure

## Description

The **D3DKMT_CHECK_MULTIPLANE_OVERLAY_SUPPORT_RETURN_INFO** structure is used to return multiplane overlay support failure information.

## Members

### `FailingPlane`

The 0 based index of the first plane that could not be supported.

### `TryAgain`

The configuration is not supported due to a transition condition, which should shortly go away.

### `Reserved`

Reserved for internal use.

### `Value`

The value used to operate over the other members of this structure.

## Remarks

## See also

[**D3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_checkmultiplaneoverlaysupport2)

[**D3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_checkmultiplaneoverlaysupport3)