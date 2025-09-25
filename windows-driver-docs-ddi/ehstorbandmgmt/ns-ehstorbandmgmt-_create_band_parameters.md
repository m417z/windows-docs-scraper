# _CREATE_BAND_PARAMETERS structure

## Description

The parameters to create a band on a storage device for an [IOCTL_EHSTOR_BANDMGMT_CREATE_BAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_create_band) request are specified in a **CREATE_BAND_PARAMETERS** structure.

## Members

### `StructSize`

The size of this structure in bytes. Set to **sizeof**(CREATE_BAND_PARAMETERS).

### `Flags`

Band creation flags. This value is a bitwise OR combination of the following.

| Value | Meaning |
| --- | --- |
| **CREATEBAND_AUTHKEY_CACHING_ENABLED** | The authentication key for this band is cached, which allows automation of later operations. The authentication key is cached when this flag is set and the band is not locked for both reading and writing. |

### `BandLocationInfoOffset`

The offset, in bytes, of a [BAND_LOCATION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_location_info) structure. The offset is from the beginning of **CREATE_BAND_PARAMETERS**.

### `BandSecurityInfoOffset`

The offset, in bytes, of a [BAND_SECURITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_security_info) structure. The offset is from the beginning of **CREATE_BAND_PARAMETERS**. If this value is 0, meaning band security info is not present, key manager metadata for the band is set to all zeros. Also, when this member is 0, the read and write lock states default to PERSISTANT_UNLOCK.

### `AuthKeyOffset`

The offset, in bytes, of an  **AUTH_KEY** structure that contains the authorization key for the new band. The offset is from the beginning of **CREATE_BAND_PARAMETERS**. **AUTH_KEY** is declared in *ehstorbandmgmt.h* as the following.

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

A variable length byte array that contains the key data.

To assign a default authorization key to the band, set **AuthKeyOffset** = **EHSTOR_BANDMGR_NO_KEY**.

## Remarks

The **CryptoAlgoIdType** and **CryptoAlgoOidString** members of the [BAND_SECURITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_security_info) structure at **BandSecurityInfoOffset** are not used in a band creation request and must be set to 0.

## See also

[BAND_LOCATION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_location_info)

[BAND_SECURITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_security_info)

[IOCTL_EHSTOR_BANDMGMT_CREATE_BAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_create_band)