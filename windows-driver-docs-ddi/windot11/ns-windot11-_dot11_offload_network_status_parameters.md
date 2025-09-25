# _DOT11_OFFLOAD_NETWORK_STATUS_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_OFFLOAD_NETWORK_STATUS_PARAMETERS structure indicates the success of the discovery of networks in the offload list.

## Members

### `Header`

The type, revision, and size of the DOT11_OFFLOAD_NETWORK_STATUS_PARAMETERS structure. The required settings for the members of **Header** are the following.

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_OFFLOAD_NETWORK_STATUS_PARAMETERS_REVISION_1 |
| **Size** | DOT11_SIZEOF_OFFLOAD_NETWORK_STATUS_PARAMETERS_REVISION_1 |

### `Status`

This must be STATUS_SUCCESS.

## Syntax

```cpp
typedef struct _DOT11_OFFLOAD_NETWORK_STATUS_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  NDIS_STATUS        Status;
} DOT11_OFFLOAD_NETWORK_STATUS_PARAMETERS, *PDOT11_OFFLOAD_NETWORK_STATUS_PARAMETERS;
```