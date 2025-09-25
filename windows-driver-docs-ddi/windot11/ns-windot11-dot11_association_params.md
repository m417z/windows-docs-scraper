# DOT11_ASSOCIATION_PARAMS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_ASSOCIATION_PARAMS structure specifies the list of additional information elements (IEs)
that the miniport driver appends to the association request that the NIC sends to an access point in an
infrastructure BSS network.

## Members

### `Header`

The type, revision, and size of the DOT11_ASSOCIATION_PARAMS structure. This member is formatted
as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_ASSOCIATION_PARAMS_REVISION_1.

#### Size

This member must be set to
**sizeof**(DOT11_ASSOCIATION_PARAMS).

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `BSSID`

The basic service set (BSS) identifier (BSSID) of the infrastructure BSS network for which the
association parameters are to be set.

The miniport driver should add new additional information elements (IEs) to an association request
only if it is attempting to associate with an access point that has the matching BSSID.

If this member is set to the wildcard BSSID (0xFFFFFFFFFFFF), the miniport driver should add new
additional information elements (IEs) to association requests for all access points that have valid
BSSIDs.

### `uAssocRequestIEsOffset`

The offset of the additional IEs, in bytes, that the operating system requests be added to the
association response. This offset is relative to the start of the buffer that contains the
DOT11_ASSOCIATION_PARAMS structure. The default value is 0.

### `uAssocRequestIEsLength`

The length of the additional IEs, in bytes, that the operating system requests be added to the
association response. The default value is 0.

## Syntax

```cpp
typedef struct DOT11_ASSOCIATION_PARAMS {
  NDIS_OBJECT_HEADER Header;
  DOT11_MAC_ADDRESS  BSSID;
  ULONG              uAssocRequestIEsOffset;
  ULONG              uAssocRequestIEsLength;
} DOT11_ASSOCIATION_PARAMS, *PDOT11_ASSOCIATION_PARAMS;
```

## Remarks

This structure is used with
[OID_DOT11_ASSOCIATION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-association-params).

## See also

[OID_DOT11_ASSOCIATION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-association-params)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)