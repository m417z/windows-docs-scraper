# MFRR_COMPONENTS structure

## Description

Contains information about one or more revoked components.

## Members

### `dwRRInfoVersion`

Revocation information version.

### `dwRRComponents`

Number of elements in the **pRRComponents** array.

### `pRRComponents`

Array of [MFRR_COMPONENT_HASH_INFO](https://learn.microsoft.com/windows/desktop/api/mfidl/ns-mfidl-mfrr_component_hash_info) structures.

## See also

[MFRR_COMPONENT_HASH_INFO](https://learn.microsoft.com/windows/desktop/api/mfidl/ns-mfidl-mfrr_component_hash_info)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)