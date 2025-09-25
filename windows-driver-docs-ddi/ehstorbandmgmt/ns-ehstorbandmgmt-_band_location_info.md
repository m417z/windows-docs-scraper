# _BAND_LOCATION_INFO structure

## Description

The **BAND_LOCATION_INFO** structure specifies the location information for a band table entry query.

## Members

### `StructSize`

The size of the structure in bytes. Set to **sizeof**(BAND_LOCATION_INFO).

### `Reserved`

Reserved.

### `BandStart`

The offset in bytes of this band location on the storage device. This value is always 0 for the global band.

### `BandSize`

The size in bytes of the band configured at this location. This value is set to the maximum size possible for the global band.

### `Metadata`

A metadata field used as a data area for a band management application.

## Remarks

**BandStart** and **BandSize** must be a multiple of the sector size of the underlying storage device.

## See also

[BAND_TABLE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_table_entry)

[IOCTL_EHSTOR_BANDMGMT_CREATE_BAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_create_band)

[IOCTL_EHSTOR_BANDMGMT_ENUMERATE_BANDS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_enumerate_bands)