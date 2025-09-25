# KSDS3D_ITD_PARAMS_MSG structure

## Description

The KSDS3D_ITD_PARAMS_MSG structure specifies the parameters used by the interaural time delay (ITD) algorithm in a 3D node ([KSNODETYPE_3D_EFFECTS](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-3d-effects)).

## Members

### `Enabled`

Specifies whether to enable the ITD algorithm. A nonzero value enables the algorithm. Zero disables it. For more information, see the following Remarks section.

### `LeftParams`

Specifies the ITD parameters for the left channel (channel 0). This parameter is a structure of type [KSDS3D_ITD_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksds3d_itd_params).

### `RightParams`

Specifies the ITD parameters for the right channel (channel 1). This parameter is a structure of type KSDS3D_ITD_PARAMS.

### `Reserved`

Reserved. Set to zero.

## Remarks

This structure is used by the [KSPROPERTY_ITD3D_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-itd3d-params) property request.

The *Enabled* parameter should track the DirectSound buffer's 3D mode: Disable ITD processing when the 3D mode is disabled, and enable it when the 3D mode is enabled. For more information, see the description of the **DirectSound3DBuffer::SetMode** method in the Microsoft Windows SDK documentation.

## See also

[KSDS3D_ITD_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksds3d_itd_params)

[KSNODETYPE_3D_EFFECTS](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-3d-effects)

[KSPROPERTY_ITD3D_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-itd3d-params)