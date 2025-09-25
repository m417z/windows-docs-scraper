# DOT11_CIPHER_ALGORITHM_LIST structure

## Description

> [!IMPORTANT]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_CIPHER_ALGORITHM_LIST structure defines a list of [DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm) structures that can be enabled on the 802.11 station.

## Members

### `Header`

The type, revision, and size of the DOT11_CIPHER_ALGORITHM_LIST structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of **Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_CIPHER_ALGORITHM_LIST_REVISION_1.

#### Size

This member must be set to sizeof(DOT11_CIPHER_ALGORITHM_LIST).

For more information about these members, see [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uNumOfEntries`

The number of entries in the **AlgorithmIds** array.

### `uTotalNumOfEntries`

The maximum number of entries that the **AlgorithmIds** array can contain.

### `AlgorithmIds`

The cipher algorithm, which is defined by a [DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm) enumerator value.

The list of cipher algorithms is sorted by preference. **AlgorithmIds** [0] defines the cipher algorithm with the highest preference.

## Syntax

```cpp
typedef struct DOT11_CIPHER_ALGORITHM_LIST {
  NDIS_OBJECT_HEADER     Header;
  ULONG                  uNumOfEntries;
  ULONG                  uTotalNumOfEntries;
  DOT11_CIPHER_ALGORITHM AlgorithmIds[1];
} DOT11_CIPHER_ALGORITHM_LIST, *PDOT11_CIPHER_ALGORITHM_LIST;
```

## Remarks

A miniport driver returns the DOT11_CIPHER_ALGORITHM_LIST structure when it is queried by either [OID_DOT11_SUPPORTED_UNICAST_ALGORITHM_PAIR](https://learn.microsoft.com/previous-versions/windows/embedded/gg157261(v=winembedded.80)) or [OID_DOT11_SUPPORTED_MULTICAST_ALGORITHM_PAIR](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-multicast-algorithm-pair).

When these OIDs are queried, the miniport driver must verify that the **InformationBuffer** member of the [MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function's *OidRequest* parameter is large enough to return the entire DOT11_CIPHER_ALGORITHM_LIST structure, including all entries in the
**AlgorithmIds** array. The value of the **InformationBufferLength** member of the *OidRequest* parameter determines what the miniport driver must do, as the following list shows:

* If the value of the **InformationBufferLength** member is less than the length, in bytes, of the entire DOT11_CIPHER_ALGORITHM_LIST structure, the miniport driver must do the following:
  * For the _OidRequest_ parameter, set the **BytesWritten** member to zero and the **BytesNeeded** member to the length, in bytes, of the entire DOT11_CIPHER_ALGORITHM_LIST structure.
  * Fail the query request by returning NDIS_STATUS_BUFFER_OVERFLOW from its [MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function.
* If the value of the **InformationBufferLength** member is greater than or equal to the length, in bytes, of the entire DOT11_CIPHER_ALGORITHM_LIST structure, the miniport driver must do the following to complete a successful query request:
  * For the DOT11_CIPHER_ALGORITHM_LIST structure, set the **uNumOfEntries** and **uTotalNumOfEntries** members to the total number of entries in the **AlgorithmIds** array.
  * For the _OidRequest_ parameter, set the **BytesNeeded** member to zero and the **BytesWritten** member to the length, in bytes, of the entire DOT11_CIPHER_ALGORITHM_LIST structure. The miniport driver must also copy the entire DOT11_CIPHER_ALGORITHM_LIST structure to the **InformationBuffer** member.
  * Return NDIS_STATUS_SUCCESS from its [MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function.

## See also

[OID_DOT11_SUPPORTED_UNICAST_ALGORITHM_PAIR](https://learn.microsoft.com/previous-versions/windows/embedded/gg157261(v=winembedded.80))

[OID_DOT11_SUPPORTED_MULTICAST_ALGORITHM_PAIR](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-multicast-algorithm-pair)

[DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)