# D3DKMDT_VIDEO_SIGNAL_STANDARD enumeration

## Description

The **D3DKMDT_VIDEO_SIGNAL_STANDARD** enumeration contains constants that represent video signal standards.

## Constants

### `D3DKMDT_VSS_UNINITIALIZED`

Indicates that a variable of type **D3DKMDT_VIDEO_SIGNAL_STANDARD** has not yet been assigned a meaningful value.

### `D3DKMDT_VSS_VESA_DMT`

Represents the Video Electronics Standards Association (VESA) Display Monitor Timing (DMT) standard.

### `D3DKMDT_VSS_VESA_GTF`

Represents the VESA Generalized Timing Formula (GTF) standard.

### `D3DKMDT_VSS_VESA_CVT`

Represents the VESA Coordinated Video Timing (CVT) standard.

### `D3DKMDT_VSS_IBM`

Represents the IBM standard.

### `D3DKMDT_VSS_APPLE`

Represents the Apple standard.

### `D3DKMDT_VSS_NTSC_M`

Represents the National Television Standards Committee (NTSC) standard.

### `D3DKMDT_VSS_NTSC_J`

Represents the NTSC standard.

### `D3DKMDT_VSS_NTSC_443`

Represents the NTSC standard.

### `D3DKMDT_VSS_PAL_B`

Represents the Phase Alteration Line (PAL) standard.

### `D3DKMDT_VSS_PAL_B1`

Represents the PAL standard.

### `D3DKMDT_VSS_PAL_G`

Represents the PAL standard.

### `D3DKMDT_VSS_PAL_H`

Represents the PAL standard.

### `D3DKMDT_VSS_PAL_I`

Represents the PAL standard.

### `D3DKMDT_VSS_PAL_D`

Represents the PAL standard.

### `D3DKMDT_VSS_PAL_N`

Represents the PAL standard.

### `D3DKMDT_VSS_PAL_NC`

Represents the PAL standard.

### `D3DKMDT_VSS_SECAM_B`

Represents the Systeme Electronic Pour Couleur Avec Memoire (SECAM) standard.

### `D3DKMDT_VSS_SECAM_D`

Represents the SECAM standard.

### `D3DKMDT_VSS_SECAM_G`

Represents the SECAM standard.

### `D3DKMDT_VSS_SECAM_H`

Represents the SECAM standard.

### `D3DKMDT_VSS_SECAM_K`

Represents the SECAM standard.

### `D3DKMDT_VSS_SECAM_K1`

Represents the SECAM standard.

### `D3DKMDT_VSS_SECAM_L`

Represents the SECAM standard.

### `D3DKMDT_VSS_SECAM_L1`

Represents the SECAM standard.

### `D3DKMDT_VSS_EIA_861`

Represents the Electronics Industries Association (EIA) standard.

### `D3DKMDT_VSS_EIA_861A`

Represents the EIA standard.

### `D3DKMDT_VSS_EIA_861B`

Represents the EIA standard.

### `D3DKMDT_VSS_PAL_K`

Represents the PAL standard.

### `D3DKMDT_VSS_PAL_K1`

Represents the PAL standard.

### `D3DKMDT_VSS_PAL_L`

Represents the PAL standard.

### `D3DKMDT_VSS_PAL_M`

Represents the PAL standard.

### `D3DKMDT_VSS_OTHER`

Represents any video standard other than those represented by the previous constants in this enumeration.

## Remarks

This enumeration is used with the [**D3DKMDT_VIDPN_TARGET_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_target_mode) structure. This structure's **VideoSignalInfo** member is a [**D3DKMDT_VIDEO_SIGNAL_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_video_signal_info) structure whose **VideoStandard** member is a **D3DKMDT_VIDEO_SIGNAL_STANDARD** value.

For more information, see [VidPN Objects and Interfaces](https://learn.microsoft.com/windows-hardware/drivers/display/vidpn-objects-and-interfaces).

## See also

[**D3DKMDT_VIDEO_SIGNAL_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_video_signal_info)

[**D3DKMDT_VIDPN_TARGET_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_target_mode)