# _DXVA_MVvalue structure

## Description

The DXVA_MVvalue structure is sent by the host decoder to the accelerator to specify the two-dimensional motion vector value.

## Members

### `horz`

Specifies the horizontal component of the value of a motion vector. Contains a signed integer motion offset in half-sample units. The value of this member will be an even integer if the **bMVprecisionAndChromaRelation** member of [DXVA_PictureParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_pictureparameters) equals 2 (H.261-style motion supporting only integer-sample offsets).

### `vert`

Specifies the vertical component of the value of a motion vector. Contains a signed integer motion offset in half-sample units. The value of this member will be an even integer if the **bMVprecisionAndChromaRelation** member of [DXVA_PictureParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_pictureparameters) equals 2 (H.261-style motion supporting only integer-sample offsets).

## Remarks

The DXVA_MVvalue structure is used in the [DXVA_MBctrl_P_HostResidDiff_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mbctrl_p_hostresiddiff_1) and [DXVA_MBctrl_P_OffHostIDCT_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mbctrl_p_offhostidct_1) structures.

## See also

[DXVA_MBctrl_P_HostResidDiff_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mbctrl_p_hostresiddiff_1)

[DXVA_MBctrl_P_OffHostIDCT_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mbctrl_p_offhostidct_1)