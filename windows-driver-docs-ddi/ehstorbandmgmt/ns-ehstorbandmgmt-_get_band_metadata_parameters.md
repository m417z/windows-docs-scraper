# _GET_BAND_METADATA_PARAMETERS structure

## Description

The metadata for a configured band is retrieved according to the parameters in a **GET_BAND_METADATA_PARAMETERS** structure. This structure is input for an  [IOCTL_EHSTOR_BANDMGMT_GET_BAND_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_get_band_metadata) request.

## Members

### `StructSize`

The size of this structure in bytes. Set to **sizeof**(GET_BAND_METADATA_PARAMETERS).

### `BandId`

The identifier of a single band to return information for. **BandSize** must be 0 when a single band is selected with **BandId.** To use **BandStart** and **BandSize** instead of **BandId** to select a band, set **BandId** = (ULONG) –1.

### `BandStart`

The starting byte location on the storage device to begin a band search. An attempt is made to match a band at or after **BandStart**.

### `MetadataOffset`

The offset from the start of the band metadata property to retrieve data from.

### `MetadataSize`

The length of metadata bytes to retrieve.

## Remarks

 Precedence is given to **BandID** for band selection. If **BandID** is greater than 0 and **BandID** is less than the **MaxBandCount** member of [BAND_MANAGEMENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_management_capabilities), then **BandID** is used as the only selection criteria for a band match. If **BandID** == –1, then **BandStart** is used as the match criteria to select a band. If no band matches either selection criteria, then STATUS_INVALID_PARAMETER is returned in the *IoStatus* block for [IOCTL_EHSTOR_BANDMGMT_GET_BAND_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_get_band_metadata).

If **BandID** and **BandStart** are both set to –1, then the [IOCTL_EHSTOR_BANDMGMT_GET_BAND_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_get_band_metadata) returns metadata for the global band.

If [IOCTL_EHSTOR_BANDMGMT_GET_BAND_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_get_band_metadata) was successful, *Parameters.DeviceIoControl.InputBufferLength* equals the value in **MetadataSize**.

## See also

[BAND_MANAGEMENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_management_capabilities)

[IOCTL_EHSTOR_BANDMGMT_GET_BAND_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_get_band_metadata)