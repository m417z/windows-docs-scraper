# _SET_BAND_LOCATION_PARAMETERS structure

## Description

The [SET_BAND_LOCATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_set_band_location_parameters) structure specifies the parameters to set location properties for a band on a storage device for a [IOCTL_EHSTOR_BANDMGMT_SET_BAND_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_set_band_location) request.

## Members

### `StructSize`

The size of this structure in bytes. Set to **sizeof**(SET_BAND_LOCATION_PARAMETERS).

### `BandId`

The identifier of a single band to return information for. **BandSize** must be 0 when a single band is selected with **BandId.** To use **BandStart** and **BandSize** instead of **BandId** to select a band, set **BandId** = (ULONG) –1.

### `BandStart`

The starting byte location on the storage device to begin a band search. An attempt is made to match a band at or after **BandStart**.

### `AuthKeyOffset`

The offset, in bytes, of an  **AUTH_KEY** structure containing the authorization key for the band. The offset is from the beginning of [SET_BAND_LOCATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_set_band_location_parameters). **AUTH_KEY** is declared in *ehstorbandmgmt.h* as the following.

```
typedef struct _AUTH_KEY
{
    ULONG   KeySize;
    UCHAR   Key[ANYSIZE_ARRAY];
} AUTH_KEY;
```

#### KeySize

The size of the key, in bytes, of the key data at **Key**. If **KeySize** is set to 0, a default key is used.

#### Key

A variable-length byte array that contains the key data.

To specify a default authorization key to the band, set **AuthKeyOffset** = **EHSTOR_BANDMGR_NO_KEY**.

### `BandLocationInfoOffset`

The offset, in bytes, of a [BAND_LOCATION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_location_info) structure. The offset is from the beginning of [SET_BAND_LOCATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_set_band_location_parameters).

## Remarks

 Precedence is given to **BandID** for band selection. If **BandID** is greater than 0 and **BandID** is less than the **MaxBandCount** member of [BAND_MANAGEMENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_management_capabilities), then **BandID** is used as the only selection criteria for a band match. If **BandID** == –1, then **BandStart** is used as the match criteria to select a band. If no band matches either selection criteria, then STATUS_INVALID_PARAMETER is returned in the *IoStatus* block for [IOCTL_EHSTOR_BANDMGMT_SET_BAND_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_set_band_location).

If **BandID** and **BandStart**  are both set to –1, then the [IOCTL_EHSTOR_BANDMGMT_SET_BAND_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_set_band_location) request will change the properties of the global band.

## See also

[BAND_LOCATION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_location_info)

[BAND_MANAGEMENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_management_capabilities)

[IOCTL_EHSTOR_BANDMGMT_SET_BAND_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_set_band_location)