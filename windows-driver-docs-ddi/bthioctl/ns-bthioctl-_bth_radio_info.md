# _BTH_RADIO_INFO structure

## Description

The BTH_RADIO_INFO structure contains information about a remote radio.

## Members

### `lmpSupportedFeatures`

A bitmap of Link Management Protocol (LMP) features that are supported by the local radio.

### `mfg`

The identification of the manufacturer.

### `lmpSubversion`

The minor version number for the LMP that is used by the local radio.

### `lmpVersion`

The major version number for the LMP that is used by the local radio.

## Remarks

The BTH_RADIO_INFO structure is returned as part of the output buffer of
[IOCTL_BTH_GET_LOCAL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_get_local_info). The local
radio information is returned in the
**radioInfo** member of the
[BTH_LOCAL_RADIO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_local_radio_info) structure.

## See also

[BTH_LOCAL_RADIO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_local_radio_info)

[IOCTL_BTH_GET_LOCAL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_get_local_info)