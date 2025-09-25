# _BAND_SECURITY_INFO structure

## Description

The **BAND_SECURITY_INFO** structure specifies the security information for a band table entry query.

## Members

### `StructSize`

The size of the structure in bytes. Set to **sizeof**(BAND_SECURITY_INFO).

### `ReadLock`

Whether the band is accessible for reading and how a read lock is affected by a power reset.

### `WriteLock`

Whether the band is accessible for writing and how a write lock is affected by a power reset.

### `CryptoAlgoIdType`

The type of encryption algorithm identifier used. This must be set to **AlgoIdTypeOidString**.

### `CryptoAlgoOidString`

The encryption algorithm used to protect the data in the band.

### `CryptoAlgoOidString.Offset`

The offset from the beginning of this structure where the encryption algorithm OID string begins.

### `CryptoAlgoOidString.Length`

The length of the OID string identifying the encryption algorithm. This is a byte-length value including a NULL terminator for the OID string.

### `CryptoAlgoNumericId`

Reserved.

### `Metadata`

A metadata field available for use by a key manager.

## Remarks

Both **Readlock** and **Writelock** are **LOCKSTATE** values and indicate locking state and lock persistence. Their values are one of the following.

| Lock State | Description |
| --- | --- |
| INVALID_LOCK_STATE | The lock state is not valid. |
| PERSISTENT_UNLOCK | The device is unlocked and remains unlocked during power reset. |
| NONPERSISTENT_UNLOCK | The device is unlocked but becomes locked during power reset. |
| PERSISTENT_LOCK | The device is locked and remains locked during power reset. |

**CryptoAlgoOidString** specifies the data encryption algorithm only if **ENUMBANDS_REPORT_CRYPTO_ALGO** is set in the **Flags** member of [ENUMERATE_BANDS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_enumerate_bands_parameters) in an [IOCTL_EHSTOR_BANDMGMT_ENUMERATE_BANDS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_enumerate_bands) request. Otherwise, both **CryptoAlgoOidString.Offset** and **CryptoAlgoOidString.Length** are set to 0. The following are possible encryption algorithm OID strings returned for **CryptoAlgoOidString**.

| Algorithm | OID |
| --- | --- |
| IAES128-ECB | 2.16.840.1.101.3.4.1.1 |
| AES128-CBC | 2.16.840.1.101.3.4.1.2. |
| AES128-OFB | 2.16.840.1.101.3.4.1.3 |
| AES128-CFB | 2.16.840.1.101.3.4.1.4 |
| AES128-XTS | 1.3.111.2.1619.0.1.1 |
| AES256-ECB | 2.16.840.1.101.3.4.1.41 |
| AES256-CBC | 2.16.840.1.101.3.4.1.42 |
| AES256-OFB | 2.16.840.1.101.3.4.1.43 |
| AES256-CFB | 2.16.840.1.101.3.4.1.44 |
| AES256-XTS | 1.3.111.2.1619.0.1.2 |

When **BAND_SECURITY_INFO** is used in an input parameter set, **CryptoAlgoIdType** and **CryptoAlgoOidString** are not used and must be set to 0.

## See also

[BAND_TABLE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_table_entry)

[ENUMERATE_BANDS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_enumerate_bands_parameters)

[IOCTL_EHSTOR_BANDMGMT_CREATE_BAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_create_band)

[IOCTL_EHSTOR_BANDMGMT_ENUMERATE_BANDS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_enumerate_bands)