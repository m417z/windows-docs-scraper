# _ENUMERATE_BANDS_PARAMETERS structure

## Description

The **ENUMERATE_BANDS_PARAMETERS** structure is used to select which band information entries are selected for return from an [IOCTL_EHSTOR_BANDMGMT_ENUMERATE_BANDS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_enumerate_bands) request.

## Members

### `StructSize`

The size of this structure in bytes. Set to **sizeof**(ENUMERATE_BANDS_PARAMETERS).

### `Flags`

Band enumeration flags. This value is a bitwise OR combination of the following.

| Value | Meaning |
| --- | --- |
| **ENUMBANDS_ENUM_ALL_BANDS** | All bands are returned. When this flag is set, the **BandId**, **BandStart**, and **BandSize** members are ignored. |
| **ENUMBANDS_REPORT_CRYPTO_ALGO** | Include media encryption algorithm information in the **SecurityInfo** member of [BAND_TABLE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_table_entry). |

### `Reserved`

Reserved.

### `BandId`

The identifier of a single band to return information for. **BandSize** must be 0 when a single band is selected with **BandId.** To use **BandStart** and **BandSize** instead of **BandId** to select a band, set **BandId** = (ULONG) –1.

### `BandStart`

The starting byte location on the storage device to begin a band search. An attempt is made to match a band at or after **BandStart**.

### `BandSize`

An optional band size match value in bytes. If **BandSize** == 0 and **BandId** == –1, then **BandStart** is the only match value for selecting a band. Otherwise, a band at or after **BandStart** and matching **BandSize** exactly is selected.

## Remarks

When **ENUMBANDS_ENUM_ALL_BANDS** is not set in **Flags**, a selection attempt is made to match a single band. A single band match is made based on the values in **BandID**, **BandStart**, and **BandSize**. Precedence is given to **BandID** for band selection. If **BandID** > 0 and **BandID** < **MaxBandCount** member of [BAND_MANAGEMENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_management_capabilities) If **BandID** is greater than 0 and **BandID** is less than the **MaxBandCount** member of **BAND_MANAGEMENT_CAPABILITIES**, then **BandID** is used as the only selection criteria for a band match. If **BandID** == –1, then **BandStart** and **BandSize** are used as match criteria to select a band.

When **BandStart** and **BandSize** are used to match a band, the first band configured at or after the **BandStart** location having the exact size of **BandSize** is returned. If **BandSize** == 0, when **BandStart** is valid, then the first band configured at or after **BandStart** is returned.

If **BandID** == 0 or no bands are configured and **Flags** is not set to ENUMBANDS_ENUM_ALL_BANDS, then the global band for the entire device is returned.

**BandStart** and **BandSize** are not valid unless their values, in bytes, are exact multiples of the sector size of the underlying storage device.

## See also

[BAND_MANAGEMENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_management_capabilities)

[BAND_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_table)

[BAND_TABLE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_table_entry)

[IOCTL_EHSTOR_BANDMGMT_ENUMERATE_BANDS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_enumerate_bands)