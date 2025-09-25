# _MBB_MBIM_EXTENDED_VERSION enumeration

## Description

> [!WARNING]
> Some information in this topic relates to prereleased product, which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.
>
> MBBCx is preview only in Windows 10, version 1809.

The **MBB_MBIM_EXTENDED_VERSION** enumeration defines the version of the extended MBIM (MBIMEx) specification that a client driver and its device support.

## Constants

### `MbbMbimExtendedVersion1Dot0`

The client driver and device support MBIMEx specification Rev 1.0.

### `MbbMbimExtendedVersion2Dot0`

The client driver and device support MBIMEx specification Rev 2.0.

### `MbbMbimExtendedVersion3Dot0`

The client driver and device support MBIMEx specification Rev 3.0.

### `MbbMbimExtendedVersion4Dot0`

The client driver and device support MBIMEx specification Rev 4.0.

### `MbbMbimExtendedVersionMax`

The maximum MBIMEx version.

## Remarks

Client drivers set the lowest MBIMEx specification version they support in the **ExtendedVersion** member of the [**MBB_DEVICE_MBIM_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/ns-mbbcx-_mbb_device_mbim_parameters) structure.

## See also