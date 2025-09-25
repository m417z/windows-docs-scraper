# _MBB_DEVICE_MBIM_PARAMETERS structure

## Description

The client driver uses the **MBB_DEVICE_MBIM_PARAMETERS** structure to describe its MBIM specification-related parameters to the MBBCx framework.

## Members

### `Size`

The size of this structure, in bytes.

### `Version`

An [**MBB_MBIM_VERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/ne-mbbcx-_mbb_mbim_version) value that defines the version of the MBIM specification that the client driver supports. The value of this field must be **MBB_MBIM_VERSION1_0_ERRATA**.

> [!IMPORTANT]
> The client driver and device must support the MBIM specification Rev 1.0 Errata-1.

### `ExtendedVersion`

An [**MBB_MBIM_EXTENDED_VERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/ne-mbbcx-_mbb_mbim_extended_version) value that defines the version of the extended MBIM specification that the client driver supports. The value of this field must be **MBB_MBIM_EXTENDED_VERSION2_0**.

### `MaximumFragmentSize`

The maximum size of MBIM control messages that the client driver can support.

The MBBCx framework uses the value of this field to determine if it needs to fragment the MBIM message when it later calls into the client driver's [*EvtMbbDeviceSendMbimFragment*](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nc-mbbcx-evt_mbb_device_send_mbim_fragment) callback function to issue commands.

## Remarks

Call [**MBB_DEVICE_MBIM_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nf-mbbcx-mbb_device_mbim_parameters_init) to initialize this structure.

## See also