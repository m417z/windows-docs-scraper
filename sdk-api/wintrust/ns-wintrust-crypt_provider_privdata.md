# CRYPT_PROVIDER_PRIVDATA structure

## Description

[The **CRYPT_PROVIDER_PRIVDATA** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPT_PROVIDER_PRIVDATA** structure contains private data to be used by a provider. The structure is used by the [CRYPT_PROVIDER_DATA](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_data) structure.

## Members

### `cbStruct`

The size, in bytes, of this structure.

### `gProviderID`

**GUID** that identifies the provider.

### `cbProvData`

Number of bytes referenced by **pvProvData**.

### `pvProvData`

A pointer to a **void** that contains the private data.

## See also

[CRYPT_PROVIDER_DATA](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_data)