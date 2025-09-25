# _DOT11_SUPPORTED_ANTENNA_LIST structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_SUPPORTED_ANTENNA_LIST structure specifies a list of antennas that can be used for receive
or transmit operations.

## Members

### `uNumOfEntries`

The number of entries in the
**dot11SupportedAntenna** array. A zero value for the
**uNumOfEntries** member indicates an empty list.

### `uTotalNumOfEntries`

The maximum number of entries that the
**dot11SupportedAntenna** array can contain.

### `dot11SupportedAntenna`

The list of supported antennas. Each element in this list is formatted as a
[DOT11_SUPPORTED_ANTENNA](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_supported_antenna) structure.

## Syntax

```cpp
typedef struct _DOT11_SUPPORTED_ANTENNA_LIST {
  ULONG                   uNumOfEntries;
  ULONG                   uTotalNumOfEntries;
  DOT11_SUPPORTED_ANTENNA dot11SupportedAntenna[1];
} DOT11_SUPPORTED_ANTENNA_LIST, *PDOT11_SUPPORTED_ANTENNA_LIST;
```

## Remarks

A miniport driver returns the DOT11_SUPPORTED_ANTENNA_LIST structure when queried by either
[OID_DOT11_SUPPORTED_RX_ANTENNA](https://learn.microsoft.com/previous-versions/ms893804(v=msdn.10)) or
[OID_DOT11_SUPPORTED_TX_ANTENNA](https://learn.microsoft.com/previous-versions/windows/embedded/ee484405(v=winembedded.80)).

When these OIDs are queried, the miniport driver must verify that the
**InformationBuffer** member of the
[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function's
*OidRequest* parameter is large enough to return the entire DOT11_SUPPORTED_ANTENNA_LIST structure,
including all entries in the
**dot11SupportedAntenna** array. The value of the
**InformationBufferLength** member of the
*OidRequest* parameter determines what the miniport driver must do, as the following list shows:

* If the value of the
  **InformationBufferLength** member is less than the length, in bytes, of the entire
  DOT11_SUPPORTED_ANTENNA_LIST structure, the miniport driver must do the following:

  + Set the
    **uNumOfEntries** member to zero.
  + Set the
    **uTotalNumOfEntries** member to the number of entries in the
    **dot11SupportedAntenna** array.

    For the
    *OidRequest* parameter, set the
    **BytesWritten** member to zero and the
    **BytesNeeded** member to the length, in bytes, of the entire DOT11_PHY_ID_LIST structure.
  + Fail the query request by returning NDIS_STATUS_BUFFER_OVERFLOW from its
    [MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function.
* If the value of the
  **InformationBufferLength** member is greater than or equal to the length, in bytes, of the entire
  DOT11_SUPPORTED_ANTENNA_LIST structure, the miniport driver must do the following to complete a
  successful query request:

  + For the DOT11_SUPPORTED_ANTENNA_LIST structure, set the
    **uNumOfEntries** and
    **uTotalNumOfEntries** members to the total number of entries in the
    **dot11SupportedAntenna** array.
  + For the
    *OidRequest* parameter, set the
    **BytesNeeded** member to zero and the
    **BytesWritten** member to the length, in bytes, of the entire DOT11_SUPPORTED_ANTENNA_LIST
    structure. The miniport driver must also copy the entire DOT11_SUPPORTED_ANTENNA_LIST structure to
    the
    **InformationBuffer** member.
  + Return NDIS_STATUS_SUCCESS from its
    [MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function.

## See also

[DOT11_SUPPORTED_ANTENNA](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_supported_antenna)

[OID_DOT11_SUPPORTED_TX_ANTENNA](https://learn.microsoft.com/previous-versions/windows/embedded/ee484405(v=winembedded.80))

[OID_DOT11_SUPPORTED_RX_ANTENNA](https://learn.microsoft.com/previous-versions/ms893804(v=msdn.10))