# _DOT11_WFD_ADDITIONAL_IE structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The **DOT11_WFD_ADDITIONAL_IE** structure represents an additional Information Element (IE) included in an [OID_DOT11_WFD_ADDITIONAL_IE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-additional-ie) request. An additional IE contains both request and response data for probe and beacon operations.

## Members

### `Header`

Specifies the type, revision and size of the **DOT11_WFD_ADDITIONAL_IE** structure. The required settings for the members of **Header** are the following:

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_WFD_ADDITIONAL_IE_REVISION_1 |
| **Size** | DOT11_SIZEOF_WFD_ADDITIONAL_IE_REVISION_1 |

### `uBeaconIEsOffset`

The offset, in bytes, of an array of beacon IEs. This offset is relative to the start of the buffer that contains this structure. The Wi-Fi Direct (WFD) port must add these addition IEs to the beacon packets when it is acting as a Group Owner.

### `uBeaconIEsLength`

The length, in bytes, of the additional IEs at **uBeaconIEsOffset**. This member is ignored when the WFD port is operating in device or client mode.

### `uProbeResponseIEsOffset`

The offset, in bytes, of an array of probe response IEs. This offset is relative to the start of the buffer that contains this structure. The Wi-Fi Direct (WFD) port must add these addition IEs to the probe response packets when it is acting as a WFD device or Group Owner.

### `uProbeResponseIEsLength`

The length, in bytes, of the additional IEs at **uProbeResponseIEsOffset**. This member is ignored when the WFD port is operating in client mode.

### `uDefaultRequestIEsOffset`

The offset, in bytes, of an array of probe request IEs. This offset is relative to the start of the buffer that contains this structure. The Wi-Fi Direct (WFD) port must add these addition IEs to the probe request packets it transmits.

### `uDefaultRequestIEsLength`

The length, in bytes, of the additional IEs at **uDefaultRequestIEsOffset**.

## Syntax

```cpp
typedef struct _DOT11_WFD_ADDITIONAL_IE {
  NDIS_OBJECT_HEADER Header;
  ULONG              uBeaconIEsOffset;
  ULONG              uBeaconIEsLength;
  ULONG              uProbeResponseIEsOffset;
  ULONG              uProbeResponseIEsLength;
  ULONG              uDefaultRequestIEsOffset;
  ULONG              uDefaultRequestIEsLength;
}  DOT11_WFD_ADDITIONAL_IE, *PDOT11_WFD_ADDITIONAL_IE;
```

## Remarks

The additional IEs at **uDefaultRequestIEsOffset** are for probe requests originating from the driver only. Explicit device discovery requests from the system are initiated in an [OID_DOT11_WFD_DISCOVER_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-discover-request). The IEs for an explicit discovery request should come from those IEs in the OID_DOT11_WFD_DISCOVER_REQUEST request and not from the IEs at **uDefaultRequestIEsOffset**.