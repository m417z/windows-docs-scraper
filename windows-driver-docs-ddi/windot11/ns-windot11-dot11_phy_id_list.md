# DOT11_PHY_ID_LIST structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_PHY_ID_LIST structure specifies a list of zero or more PHY types.

## Members

### `Header`

The type, revision, and size of the DOT11_PHY_ID_LIST structure. This member is formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_PHY_ID_LIST_REVISION_1.

#### Size

This member must be set to
sizeof(DOT11_PHY_ID_LIST).

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uNumOfEntries`

The number of entries in the
**dot11PhyId** array.

### `uTotalNumOfEntries`

The maximum number of entries that the
**dot11PhyId** array can contain.

### `dot11PhyId`

The list of PHY identifiers (IDs).

## Syntax

```cpp
typedef struct DOT11_PHY_ID_LIST {
  NDIS_OBJECT_HEADER Header;
  ULONG              uNumOfEntries;
  ULONG              uTotalNumOfEntries;
  ULONG              dot11PhyId[1];
} DOT11_PHY_ID_LIST, *PDOT11_PHY_ID_LIST;
```

## Remarks

A PHY ID in the
**dot11PhyId** array must be one of the following:

* An index into the table of supported PHYs that are defined by the Native 802.11 Operational
  **msDot11SupportedPhyTypes** management information base (MIB) object. For more information about PHY
  IDs and the
  **msDot11SupportedPhyTypes** MIB object, see
  [OID_DOT11_SUPPORTED_PHY_TYPES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-phy-types).
* A PHY ID with the value of DOT11_PHY_ID_ANY. This PHY ID is called a
  *wildcard PHY ID* and is used to specify any supported PHY on the 802.11 station. If the wildcard
  PHY ID is used, it must be the only entry in the
  **dot11PhyId** array.

A miniport driver returns the DOT11_PHY_ID_LIST structure when queried by either
[OID_DOT11_ACTIVE_PHY_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-active-phy-list) or
[OID_DOT11_DESIRED_PHY_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-phy-list).

When these OIDs are queried, the miniport driver must verify that the
**InformationBuffer** member of the
[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function's
*OidRequest* parameter is large enough to return the entire DOT11_PHY_ID_LIST structure, including
all entries in the
**dot11PhyId** array. The value of the
**InformationBufferLength** member of the
*OidRequest* parameter determines what the miniport driver must do, as the following list shows:

* If the value of the
  **InformationBufferLength** member is less than the length, in bytes, of the entire DOT11_PHY_ID_LIST
  structure, the miniport driver must do the following:

  + Set the
    **uNumOfEntries** member to zero.
  + Set the
    **uTotalNumOfEntries** member to the number of entries in the
    **dot11PhyId** array.
  + For the
    *OidRequest* parameter, set the
    **BytesWritten** member to zero and the
    **BytesNeeded** member to the length, in bytes, of the entire DOT11_PHY_ID_LIST structure.
  + Fail the query request by returning NDIS_STATUS_BUFFER_OVERFLOW from its
    [MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function.
* If the value of the
  **InformationBufferLength** member is greater than or equal to the length, in bytes, of the entire
  DOT11_PHY_ID_LIST structure, the miniport driver must do the following to complete a successful query
  request:

  + For the DOT11_PHY_ID_LIST structure, set the
    **uNumOfEntries** and
    **uTotalNumOfEntries** members to the total number of entries in the
    **dot11PhyId** array.
  + For the
    *OidRequest* parameter, set the
    **BytesNeeded** member to zero and the
    **BytesWritten** member to the length, in bytes, of the entire DOT11_PHY_ID_LIST structure. The
    miniport driver must also copy the entire DOT11_PHY_ID_LIST structure to the
    **InformationBuffer** member.
  + Return NDIS_STATUS_SUCCESS from its
    [MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function.

## See also

[OID_DOT11_ACTIVE_PHY_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-active-phy-list)

[OID_DOT11_DESIRED_PHY_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-phy-list)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)