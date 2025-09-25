# DOT11_BYTE_ARRAY structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_BYTE_ARRAY structure precedes a list of variable-length structures in the
**InformationBuffer** member of the
[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function's
*OidRequest* parameter.

## Members

### `Header`

The type, revision, and size of the DOT11_BYTE_ARRAY structure. This member is formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to the revision of the variable-length structures which follow the
DOT11_BYTE_ARRAY structure. For more information about the revision of these structures, refer to the
object identifiers (OIDS) listed in the
"See Also" section.

#### Size

This member must be set to
sizeof(DOT11_BYTE_ARRAY).

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uNumOfBytes`

The number of bytes in the
**ucBuffer** array.

### `uTotalNumOfBytes`

The maximum number of bytes that the
**ucBuffer** array requires.

### `ucBuffer`

The list of variable-length structures.

## Syntax

```cpp
typedef struct DOT11_BYTE_ARRAY {
  NDIS_OBJECT_HEADER Header;
  ULONG              uNumOfBytes;
  ULONG              uTotalNumOfBytes;
  UCHAR              ucBuffer[1];
} DOT11_BYTE_ARRAY, *PDOT11_BYTE_ARRAY;
```

## Remarks

The type of structures stored in the
**ucBuffer** array depends on the OID set and query request. For example, when queried by
[OID_DOT11_ENUM_BSS_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-enum-bss-list), a miniport
driver stores one or more DOT11_BSS_ENTRY structures in the
**ucBuffer** array.

When queried by an OID that uses the DOT11_BYTE_ARRAY structure, the miniport driver must verify that
the
**InformationBuffer** member of the
[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function's
*OidRequest* parameter is large enough to return the entire structure, including all entries in the
**ucBuffer** array. The value of the
**InformationBufferLength** member of the
*OidRequest* parameter determines what the miniport driver must do, as the following list shows:

* If the value of the
  **InformationBufferLength** member is less than the length, in bytes, of the entire DOT11_BYTE_ARRAY
  structure, the miniport driver must do the following:

  + For the
    *OidRequest* parameter, set the
    **BytesWritten** member to zero and the
    **BytesNeeded** member to the length, in bytes, of the entire DOT11_BYTE_ARRAY structure
  + Fail the query request by returning NDIS_STATUS_BUFFER_OVERFLOW from its
    [MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function.
* If the value of the
  **InformationBufferLength** member is greater than or equal to the length, in bytes, of the entire
  DOT11_BYTE_ARRAY structure, the miniport driver must do the following to complete a successful query
  request:

  + For the DOT11_BYTE_ARRAY structure, set the
    **uNumOfBytes** and
    **uTotalNumOfBytes** members to the total number of entries in the
    **ucBuffer** array.
  + For the
    *OidRequest* parameter, set the
    **BytesNeeded** member to zero and the
    **BytesWritten** member to the length, in bytes, of the entire DOT11_BYTE_ARRAY structure. The
    miniport driver must also copy the entire DOT11_BYTE_ARRAY structure to the
    **InformationBuffer** member.
  + Return NDIS_STATUS_SUCCESS from its
    [MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function.

## See also

[OID_DOT11_CIPHER_KEY_MAPPING_KEY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-cipher-key-mapping-key)

[OID_DOT11_ENUM_BSS_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-enum-bss-list)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)