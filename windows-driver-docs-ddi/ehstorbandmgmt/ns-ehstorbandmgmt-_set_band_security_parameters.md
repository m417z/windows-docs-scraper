# _SET_BAND_SECURITY_PARAMETERS structure

## Description

The parameters to set security properties for a band on a storage device for a [IOCTL_EHSTOR_BANDMGMT_SET_BAND_SECURITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_set_band_security) request are specified in a **SET_BAND_SECURITY_PARAMETERS** structure.

## Members

### `StructSize`

The size of this structure in bytes. Set to **sizeof**(SET_BAND_SECURITY_PARAMETERS).

### `Flags`

Security parameter flags. This value is a bitwise OR combination of the following.

| Value | Meaning |
| --- | --- |
| **SETBANDSEC_AUTHKEY_CACHING_ENABLED** | The new authentication key can be cached to automate some band operations. |

### `Reserved`

### `BandId`

The identifier of a single band to return information for. **BandSize** must be 0 when a single band is selected with **BandId.** To use **BandStart** and **BandSize** instead of **BandId** to select a band, set **BandId** = (ULONG) –1.

### `BandStart`

The starting byte location on the storage device to begin a band search. An attempt is made to match a band at or after **BandStart**.

### `CurrentAuthKeyOffset`

The offset, in bytes, of an  **AUTH_KEY** structure containing the current authentication key for the band. This authentication key is required and must be present following this structure. The offset is from the beginning of **SET_BAND_SECURITY_PARAMETERS**. **AUTH_KEY** is declared in *ehstorbandmgmt.h* as the following.

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

To specify a default authentication key to the band, set **AuthKeyOffset** = **EHSTOR_BANDMGR_NO_KEY**.

### `NewAuthKeyOffset`

The offset, in bytes, of an  **AUTH_KEY** structure containing the new authentication key for the band. The offset is from the beginning of **SET_BAND_SECURITY_PARAMETERS**. **AUTH_KEY** is declared in *ehstorbandmgmt.h* as the following.

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

To assign a default authentication key to the band, set **AuthKeyOffset** = **EHSTOR_BANDMGR_NO_KEY**. If **NewAuthKeyOffset** == **CurrentAuthKeyOffset**, the authentication key for the band is left unchanged.

### `BandSecurityInfoOffset`

The offset, in bytes, of a [BAND_SECURITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_security_info) structure. The offset is from the beginning of **SET_BAND_SECURITY_PARAMETERS**.

## Remarks

 Precedence is given to **BandID** for band selection. If **BandID** is greater than 0 and **BandID** is less than the **MaxBandCount** member of [BAND_MANAGEMENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_management_capabilities), then **BandID** is used as the only selection criteria for a band match. If **BandID** == –1, then **BandStart** is used as the match criteria to select a band. If no band matches either selection criteria, then STATUS_INVALID_PARAMETER is returned in the *IoStatus* block for [IOCTL_EHSTOR_BANDMGMT_SET_BAND_SECURITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_set_band_security).

If **BandID** and **BandStart** are both set to –1, then the [IOCTL_EHSTOR_BANDMGMT_SET_BAND_SECURITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_set_band_security) request will change the properties of the global band.

**NewAuthKeyOffset** and **BandSecurityInfoOffset** are optional depending on the requirements of the operation. If only the authentication key is changed, then **NewAuthKeyOffset** is set to the location of the **AUTH_KEY** structure for the new key and **BandSecurityInfoOffset** is set to zero. Similarly, if only security properties are changed, **BandSecurityInfoOffset** is set to the location of [BAND_SECURITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_security_info) and **NewAuthKeyOffset** is set to 0.

The **CryptoAlgoIdType** and **CryptoAlgoOidString** members of the [BAND_SECURITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_security_info) structure at **BandSecurityInfoOffset** are not used in a band creation request and must be set to 0.

## See also

[BAND_LOCATION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_location_info)

[BAND_MANAGEMENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_management_capabilities)

[IOCTL_EHSTOR_BANDMGMT_SET_BAND_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_set_band_location)