# _ERASE_BAND_PARAMETERS structure

## Description

The **ERASE_BAND_PARAMETERS** structure contains the selection criteria for a band to erase. Additionally, a new authentication key can be set. This structure is input for an  [IOCTL_EHSTOR_BANDMGMT_ERASE_BAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_erase_band) request.

## Members

### `StructSize`

The size of this structure in bytes. Set to **sizeof**(ERASE_BAND_PARAMETERS).

### `Flags`

Delete operation flags. This value is a bitwise OR combination of the following.

| Value | Meaning |
| --- | --- |
| **ERASEBAND_AUTHKEY_CACHING_ENABLED** | The new authentication key for this band is cached allowing for automation of later operations. |

### `Reserved`

Reserved.

### `BandId`

The identifier of a single band to return information for. **BandSize** must be 0 when a single band is selected with **BandId.** To use **BandStart** and **BandSize** instead of **BandId** to select a band, set **BandId** = (ULONG) –1.

### `BandStart`

The starting byte location on the storage device to begin a band search. An attempt is made to match a band at or after **BandStart**.

### `NewAuthKeyOffset`

The offset, in bytes, of an  **AUTH_KEY** structure containing the new authorization key for the band. The offset is from the beginning of **ERASE_BAND_PARAMETERS**. **AUTH_KEY** is declared in *ehstorbandmgmt.h* as the following.

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

To specify a default authentication key to the band, set **NewAuthKeyOffset** = **EHSTOR_BANDMGR_NO_KEY**.

## Remarks

 Precedence is given to **BandID** for band selection. If **BandID** is greater than 0 and **BandID** is less than the **MaxBandCount** member of [BAND_MANAGEMENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_management_capabilities), then **BandID** is used as the only selection criteria for a band match. If **BandID** == –1, then **BandStart** is used as the match criteria to select a band. If no band matches either selection criteria, then STATUS_INVALID_PARAMETER is returned in the *IoStatus* block for [IOCTL_EHSTOR_BANDMGMT_ERASE_BAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_erase_band).

.

## See also

[BAND_MANAGEMENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_management_capabilities)

[IOCTL_EHSTOR_BANDMGMT_DELETE_BAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_delete_band)

[IOCTL_EHSTOR_BANDMGMT_ERASE_BAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_erase_band)