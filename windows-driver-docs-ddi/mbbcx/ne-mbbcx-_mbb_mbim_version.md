# _MBB_MBIM_VERSION enumeration

## Description

The **MBB_MBIM_VERSION** enumeration defines the version of the MBIM specification that a client driver and its device support.

## Constants

### `MbbMbimVersion1Dot0`

The client driver and device support the MBIM specification Rev 1.0.

### `MbbMbimVersion1Dot0Errata`

The client driver and device support the MBIM specification Rev 1.0 Errata-1.

## Remarks

Client drivers set the MBIM specification version they support in the **Version** member of the [**MBB_DEVICE_MBIM_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/ns-mbbcx-_mbb_device_mbim_parameters) structure.

Currently, client drivers must set the value of this field to **MbbMbimVersion1Dot0Errata**.

## See also