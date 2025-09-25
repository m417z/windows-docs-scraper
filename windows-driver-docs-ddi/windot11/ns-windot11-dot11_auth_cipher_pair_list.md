# DOT11_AUTH_CIPHER_PAIR_LIST structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_AUTH_CIPHER_PAIR_LIST structure defines a list of DOT11_AUTH_CIPHER_PAIR structures.

## Members

### `Header`

The type, revision, and size of the DOT11_AUTH_CIPHER_PAIR_LIST structure. This member is
formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
*Header* to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_AUTH_CIPHER_PAIR_LIST_REVISION_1.

#### Size

This member must be set to
`sizeof(DOT11_AUTH_CIPHER_PAIR_LIST)`.

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uNumOfEntries`

The number of entries in the
**AuthCipherPairs** array.

### `uTotalNumOfEntries`

The maximum number of entries that the
**AuthCipherPairs** array can contain.

### `AuthCipherPairs`

The list of
[DOT11_AUTH_CIPHER_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair) structures.

## Syntax

```cpp
typedef struct DOT11_AUTH_CIPHER_PAIR_LIST {
  NDIS_OBJECT_HEADER     Header;
  ULONG                  uNumOfEntries;
  ULONG                  uTotalNumOfEntries;
  DOT11_AUTH_CIPHER_PAIR AuthCipherPairs[1];
} DOT11_AUTH_CIPHER_PAIR_LIST, *PDOT11_AUTH_CIPHER_PAIR_LIST;
```

## Remarks

A miniport driver returns the DOT11_AUTH_CIPHER_PAIR_LIST structure when queried by either
[OID_DOT11_SUPPORTED_UNICAST_ALGORITHM_PAIR](https://learn.microsoft.com/previous-versions/windows/embedded/gg157261(v=winembedded.80)) or
[OID_DOT11_SUPPORTED_MULTICAST_ALGORITHM_PAIR](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-multicast-algorithm-pair).

When these OIDs are queried, the miniport driver must verify that the
**InformationBuffer** member of the
[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function's
*OidRequest* parameter is large enough to return the entire DOT11_AUTH_CIPHER_PAIR_LIST structure,
including all entries in the
**AuthCipherPairs** array. The value of the
**InformationBufferLength** member of the
*OidRequest* parameter determines what the miniport driver must do, as the following list shows:

* If the value of the **InformationBufferLength** member is less than the length, in bytes, of the entire DOT11_AUTH_CIPHER_PAIR_LIST structure, the miniport driver must do the following:
  + For the *OidRequest* parameter, set the **BytesWritten** member to zero and the **BytesNeeded** member to the length, in bytes, of the entire DOT11_AUTH_CIPHER_PAIR_LIST structure.
  + Fail the query request by returning NDIS_STATUS_BUFFER_OVERFLOW from its
    [MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function.
* If the value of the **InformationBufferLength** member is greater than or equal to the length, in bytes, of the entire DOT11_AUTH_CIPHER_PAIR_LIST structure, the miniport driver must do the following to complete a successful query request:
  + For the DOT11_AUTH_CIPHER_PAIR_LIST structure, set the **uNumOfEntries** and **uTotalNumOfEntries** members to the total number of entries in the **AuthCipherPairs** array.
  + For the *OidRequest* parameter, set the **BytesNeeded** member to zero and the **BytesWritten** member to the length, in bytes, of the entire DOT11_AUTH_CIPHER_PAIR_LIST structure. The miniport driver must also copy the entire DOT11_AUTH_CIPHER_PAIR_LIST structure to the **InformationBuffer** member.
  + Return NDIS_STATUS_SUCCESS from its [MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function.

Starting with Windows 7, an 802.11 miniport driver can report any combination of supported
authentication and cipher algorithm pairs in DOT11_AUTH_CIPHER_PAIR_LIST. However, if the operating
system starts Soft AP, it enables only the
**DOT11_AUTH_ALGO_RSNA_PSK** authentication algorithm and the
**DOT11_CIPHER_ALGO_CCMP** cipher algorithm. To support Soft AP, the miniport driver must support this
authentication/cipher pair.

If WPS is enabled on a NIC that is operating in Extensible AP mode, the miniport driver must allow
peer stations to associate with the Extensible AP by using
[Open System Authentication](https://learn.microsoft.com/windows-hardware/drivers/network/open-system-authentication) or
[Wired Equivalent Privacy (WEP)](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff565846(v=vs.85)) algorithms, regardless of
the enabled authorization and cipher algorithms. For more information about WPS and Extensible AP, see
[OID_DOT11_WPS_ENABLED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wps-enabled).

## See also

[OID_DOT11_SUPPORTED_UNICAST_ALGORITHM_PAIR](https://learn.microsoft.com/previous-versions/windows/embedded/gg157261(v=winembedded.80))

[OID_DOT11_SUPPORTED_MULTICAST_ALGORITHM_PAIR](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-multicast-algorithm-pair)

[DOT11_AUTH_CIPHER_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)