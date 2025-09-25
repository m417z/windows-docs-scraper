# _SET_BAND_METADATA_PARAMETERS structure

## Description

The metadata for a configured band is set to the parameters in a **SET_BAND_METADATA_PARAMETERS** structure. This structure is input for a [IOCTL_EHSTOR_BANDMGMT_SET_BAND_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_set_band_metadata) request.

## Members

### `StructSize`

The size of this structure in bytes. Set to **sizeof**(SET_BAND_METADATA_PARAMETERS).

### `BandId`

The identifier of a single band to return information for. **BandSize** must be 0 when a single band is selected with **BandId.** To use **BandStart** and **BandSize** instead of **BandId** to select a band, set **BandId** = (ULONG) –1.

### `BandStart`

The starting byte location on the storage device to begin a band search. An attempt is made to match a band at or after **BandStart**.

### `MetadataOffset`

The offset from the start of the band metadata property to set the new data.

### `MetadataSize`

The length of metadata bytes to set. This size is limited by the value of **MetadataOffset** subtracted from the **BandMetadataSize** member of the [BAND_MANAGEMENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_management_capabilities) structure.

### `BufferOffset`

The offset, in bytes, from the beginning of **SET_BAND_METADATA_PARAMETERS**  to the location of the new metadata.

### `AuthKeyOffset`

The offset, in bytes, of an  **AUTH_KEY** structure containing the authorization key for the band. The offset is from the beginning of **SET_BAND_METADATA_PARAMETERS**. **AUTH_KEY** is declared in *ehstorbandmgmt.h* as the following.

```
typedef struct _AUTH_KEY
{
    ULONG   KeySize;
    UCHAR   Key[ANYSIZE_ARRAY];
} AUTH_KEY;
```

#### KeySize

Size of the key, in bytes, of the key data at **Key**. If **KeySize** is set to 0, a default key is used.

#### Key

A variable-length byte array that contains the key data.

To specify a default authentication key to the band, set **AuthKeyOffset** = **EHSTOR_BANDMGR_NO_KEY**.

## Remarks

 Precedence is given to **BandID** for band selection. If **BandID** is greater than 0 and **BandID** is less than the **MaxBandCount** member of [BAND_MANAGEMENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_management_capabilities), then **BandID** is used as the only selection criteria for a band match. If **BandID** == -1, then **BandStart** is used as the match criteria to select a band. If no band matches either selection criteria, then STATUS_INVALID_PARAMETER is returned in the *IoStatus* block for [IOCTL_EHSTOR_BANDMGMT_SET_BAND_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_set_band_metadata).

If **BandID** and **BandStart** are both set to –1, then the [IOCTL_EHSTOR_BANDMGMT_SET_BAND_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_set_band_metadata) sets metadata for the global band.

The size of the band metadata store is found in the **BandMetadataSize** member of [BAND_MANAGEMENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_management_capabilities). This structure is returned from a [IOCTL_EHSTOR_BANDMGMT_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_query_capabilities) request.

The new metadata to set for the band is included in the system buffer for the [IOCTL_EHSTOR_BANDMGMT_SET_BAND_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_set_band_metadata) request and follows this structure at **BufferOffset**.

## See also

[BAND_MANAGEMENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_management_capabilities)

[IOCTL_EHSTOR_BANDMGMT_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_query_capabilities)

[IOCTL_EHSTOR_BANDMGMT_SET_BAND_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_set_band_metadata)