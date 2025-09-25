# _DOT11_OFFLOAD_NETWORK_LIST_INFO structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_OFFLOAD_NETWORK_LIST_INFO structure describes a network offload-list (NLO).

## Members

### `Header`

The type, revision, and size of the DOT11_OFFLOAD_NETWORK_LIST_INFO structure. The required settings for the members of **Header** are the following.

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_OFFLOAD_NETWORK_LIST_REVISION_1 |
| **Size** | DOT11_SIZEOF_OFFLOAD_NETWORK_LIST_INFO_REVISION_1 |

### `ulFlags`

Bit flags to specify extra attributes of this NLO from the following table:

| Value | Meaning |
| --- | --- |
| DOT11_NLO_FLAG_STOP_NLO_INDICATION | Specifies that NLO scan should be stopped right away. No more NLO scans should occur. Nor should NLO discovery be indicated. **uNumOfEntries** should be 0. |
| DOT11_NLO_FLAG_SCAN_ON_AOAC_PLATFORM | Specifies that NLO should scan immediately, and the schedule of fast scan and slow scan should be followed. This is normally used on Always-On-Always-Connected (AOAC) platforms. **uNumOfEntries** can be from 0 to *n*. |
| DOT11_NLO_FLAG_SCAN_AT_SYSTEM_RESUME | Specifies that NLO is meant to be used at system resume on non-AOAC platforms, which is never the case for AOAC platforms. The NLO OID may be sent beforehand, when the systems is being suspended. Miniport/hardware should not start NLO scan right away. The list should be kept in miniport driver or hardware. When the system resumes, the miniport/hardware should try to connect to the previous connected network. The list should be scan right after the effort failed or when there is no previous connected AP to reconnect to. |

### `FastScanPeriod`

Fast scan period, in seconds. When the NIC receives the offload list, it should scan for matches to the list within the **FastScanPeriod** interval. In the fast scan period, the NIC scans for interesting SSIDs every such period for **FastScanIteration** then it switches to **SlowScanPeriod**.

### `FastScanIterations`

Number if iterations to repeat the fast scan. When the number of iterations is reached the NIC switches to the **SlowScanPeriod**.

### `SlowScanPeriod`

Slow scan period, in seconds. After the **FastScanPeriod** expires, the NIC switch to the **SlowScanPeriod**. The NIC should scan for matches to the list within the **SlowScanPeriod**. The duration is open ended until Windows issues an updated offload-list.

### `uNumOfEntries`

Number of networks in the list of those requested to offload.

### `offloadNetworkList`

Array of networks that hardware should automatically search for.

## Syntax

```cpp
typedef struct _DOT11_OFFLOAD_NETWORK_LIST_INFO {
  NDIS_OBJECT_HEADER    Header;
  ULONG                 ulFlags;
  ULONG                 FastScanPeriod;
  ULONG                 FastScanIterations;
  ULONG                 SlowScanPeriod;
  ULONG                 uNumOfEntries;
  DOT11_OFFLOAD_NETWORK offloadNetworkList[1];
} DOT11_OFFLOAD_NETWORK_LIST_INFO, *PDOT11_OFFLOAD_NETWORK_LIST_INFO;
```