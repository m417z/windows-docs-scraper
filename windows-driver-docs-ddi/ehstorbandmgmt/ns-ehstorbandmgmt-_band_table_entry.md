# _BAND_TABLE_ENTRY structure

## Description

Banding information entries in [BAND_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_table) are represented as **BAND_TABLE_ENTRY** structures. These entries contain location and security properties for a band configuration.

## Members

### `BandId`

The band identifier for a configured band on a storage device.

### `LocationInfo`

The band location information.

### `SecurityInfo`

The band security information. This includes encryption algorithm information when selected in [ENUMERATE_BANDS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_enumerate_bands_parameters).

## See also

[BAND_LOCATION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_location_info)

[BAND_SECURITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_security_info)

[BAND_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_table)

[ENUMERATE_BANDS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_enumerate_bands_parameters)