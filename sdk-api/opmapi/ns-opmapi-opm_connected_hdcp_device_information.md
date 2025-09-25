# OPM_CONNECTED_HDCP_DEVICE_INFORMATION structure

## Description

Contains the result from an [OPM_GET_CONNECTED_HDCP_DEVICE_INFORMATION](https://learn.microsoft.com/windows/desktop/medfound/opm-get-connected-hdcp-device-information) query.

## Members

### `rnRandomNumber`

An [OPM_RANDOM_NUMBER](https://learn.microsoft.com/windows/desktop/api/ksopmapi/ns-ksopmapi-opm_random_number) structure. This structure contains the same 128-bit random number that the application sent to the driver in the [OPM_GET_INFO_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ksopmapi/ns-ksopmapi-opm_get_info_parameters) or [OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-coppcompatiblegetinformation) structure.

### `ulStatusFlags`

A bitwise **OR** of [OPM Status Flags](https://learn.microsoft.com/windows/desktop/medfound/opm-status-flags).

### `ulHDCPFlags`

A value that indicates whether the connected device is an HDCP repeater.

| Value | Meaning |
| --- | --- |
| **OPM_HDCP_FLAG_NONE**<br><br>0x00 | The device is not an HDCP repeater. |
| **OPM_HDCP_FLAG_REPEATER**<br><br>0x01 | The device is an HDCP repeater. |

### `ksvB`

An [OPM_HDCP_KEY_SELECTION_VECTOR](https://learn.microsoft.com/windows/desktop/api/opmapi/ns-opmapi-opm_hdcp_key_selection_vector) structure that contains the device's key selection vector (KSV). This is the value named *Bksv* in the HDCP specification.

### `Reserved`

Reserved for future use. Fill this array with zeros.

### `Reserved2`

Reserved for future use. Fill this array with zeros.

### `Reserved3`

Reserved for future use. Fill this array with zeros.

## Remarks

The layout of this structure is identical to the [DXVA_COPPStatusHDCPKeyData](https://learn.microsoft.com/windows/desktop/api/dxva9typ/ns-dxva9typ-dxva_coppstatushdcpkeydata) structure used in Certified Output Protection Protocol (COPP).

## See also

[OPM Structures](https://learn.microsoft.com/windows/desktop/medfound/opm-structures)

[Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager)