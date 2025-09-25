# _DELETE_BAND_PARAMETERS structure

## Description

A configured band is deleted according to the parameters in a **DELETE_BAND_PARAMETERS** structure. This structure is input for an  [IOCTL_EHSTOR_BANDMGMT_DELETE_BAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_delete_band) request.

## Members

### `StructSize`

The size of this structure in bytes. Set to **sizeof**(DELETE_BAND_PARAMETERS).

### `Flags`

Delete operation flags. This value is a bitwise OR combination of the following.

| Value | Meaning |
| --- | --- |
| **DELBAND_ERASE_BEFORE_DELETE** | Perform a cryptographic erase of the band property data before delete. |

### `Reserved`

Reserved.

### `BandId`

The identifier of a single band to return information for. **BandSize** must be 0 when a single band is selected with **BandId**. To use **BandStart** and **BandSize** instead of **BandId** to select a band, set **BandId** = (ULONG) –1.

### `BandStart`

The starting byte location on the storage device to begin a band search. An attempt is made to match a band at or after **BandStart**.

### `AuthKeyOffset`

The offset, in bytes, of an  **AUTH_KEY** structure containing the authorization key for the band. The offset is from the beginning of **DELETE_BAND_PARAMETERS**. **AUTH_KEY** is declared in *ehstorbandmgmt.h* as the following.

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

A variable-length byte array containing the key data.

To specify a default authentication key to the band, set **AuthKeyOffset** = **EHSTOR_BANDMGR_NO_KEY**. If **Flags** contains **DELBAND_ERASE_BEFORE_DELETE**, **AuthKeyOffset** must be set to **EHSTOR_BANDMGR_NO_KEY**.

## Remarks

 Precedence is given to **BandID** for band selection. If **BandID** is greater than 0 and **BandID** is less than the **MaxBandCount** member of [BAND_MANAGEMENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_management_capabilities), then **BandID** is used as the only selection criteria for a band match. If **BandID** == –1, then **BandStart** is used as the match criteria to select a band. If no band matches either selection criteria, then STATUS_INVALID_PARAMETER is returned in the *IoStatus* block for [IOCTL_EHSTOR_BANDMGMT_DELETE_BAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_delete_band).

If **DELBAND_ERASE_BEFORE_DELETE** is set in **Flags**, then an authentication key is not needed to delete the band. If this flag is not set, the current authentication key must be included at **AuthKeyOffset**.

.

## See also

[BAND_MANAGEMENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_management_capabilities)

[IOCTL_EHSTOR_BANDMGMT_DELETE_BAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_delete_band)

[IOCTL_EHSTOR_BANDMGMT_ERASE_BAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_erase_band)