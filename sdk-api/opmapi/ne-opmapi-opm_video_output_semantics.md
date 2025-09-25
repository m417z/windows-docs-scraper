# OPM_VIDEO_OUTPUT_SEMANTICS enumeration

## Description

Specifies whether the [IOPMVideoOutput](https://learn.microsoft.com/windows/desktop/api/opmapi/nn-opmapi-iopmvideooutput) interface will use Output Protection Manager (OPM) semantics or Certified Output Protection Protocol (COPP) semantics.

## Constants

### `OPM_VOS_COPP_SEMANTICS:0`

The interface will use COPP semantics.

### `OPM_VOS_OPM_SEMANTICS:1`

The interface will use OPM semantics.

### `OPM_VOS_OPM_INDIRECT_DISPLAY:2`

## See also

[OPM Enumerations](https://learn.microsoft.com/windows/desktop/medfound/opm-enumerations)

[OPMGetVideoOutputsFromHMONITOR](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-opmgetvideooutputsfromhmonitor)

[OPMGetVideoOutputsFromIDirect3DDevice9Object](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-opmgetvideooutputsfromidirect3ddevice9object)