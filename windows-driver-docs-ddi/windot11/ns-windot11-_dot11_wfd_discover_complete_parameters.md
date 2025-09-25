# _DOT11_WFD_DISCOVER_COMPLETE_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

the **DOT11_WFD_DISCOVER_COMPLETE_PARAMETERS** structure is returned in a [NDIS_STATUS_DOT11_WFD_DISCOVER_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-discover-complete) indication. The structure contains a list of devices discovered

## Members

### `Header`

Specifies the type, revision and size of the **DOT11_WFD_DISCOVER_COMPLETE_PARAMETERS** structure. The required settings for the members of **Header** are the following:

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_WFD_DISCOVER_COMPLETE_PARAMETERS_REVISION_1 |
| **Size** | DOT11_SIZEOF_WFD_DISCOVER_COMPLETE_PARAMETERS_REVISION_1 |

### `Status`

The appropriate status code for the device discovery operation. If this value is not **NDIS_STATUS_SUCCESS**, the rest of the members in this structure must be set to 0.

### `uNumOfEntries`

The total number of discovered devices in the list at **uListOffset**. The number of entries cannot exceed **DOT11_WFD_DISCOVER_COMPLETE_MAX_LIST_SIZE**.

### `uTotalNumOfEntries`

The total number of discovered devices in actually discovered by the driver. The number of entries cannot exceed **DOT11_WFD_DISCOVER_COMPLETE_MAX_LIST_SIZE**.

### `uListOffset`

The offset in the **StatusBuffer** of [NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication) where the list of [DOT11_WFD_DEVICE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_wfd_device_entry) elements begins.

### `uListLength`

The length, in bytes of the device list at **uListOffset**.

## Syntax

```cpp
typedef struct _DOT11_WFD_DISCOVER_COMPLETE_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  NDIS_STATUS        Status;
  ULONG              uNumOfEntries;
  ULONG              uTotalNumOfEntries;
  ULONG              uListOffset;
  ULONG              uListLength;
} DOT11_WFD_DISCOVER_COMPLETE_PARAMETERS, *PDOT11_WFD_DISCOVER_COMPLETE_PARAMETERS;
```

## See also

[NDIS_STATUS_DOT11_WFD_DISCOVER_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-discover-complete)