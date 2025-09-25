# _DOT11_STATUS_INDICATION structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_STATUS_INDICATION structure returns the completion results of an operation that is
performed by a set request of a Native 802.11 OID.

## Members

### `uStatusType`

The type of status indication that is made by the miniport driver.

For more information about the value that is used for the
**uStatusType** member, see the topic for the OID that requires a completion indication that uses the
DOT11_STATUS_INDICATION structure.

### `ndisStatus`

An NDIS_STATUS value that indicates the result of the operation.

If the operation completed without a failure, the miniport driver must set the
**ndisStatus** member to NDIS_STATUS_SUCCESS. Otherwise, the driver must set
**ndisStatus** to the appropriate NDIS_STATUS_xxx value for the failure.

## Syntax

```cpp
typedef struct _DOT11_STATUS_INDICATION {
  ULONG       uStatusType;
  NDIS_STATUS ndisStatus;
} DOT11_STATUS_INDICATION, *PDOT11_STATUS_INDICATION;
```

## Remarks

For the Windows Vista operating system, only
[OID_DOT11_RESET_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-reset-request) requires the
use of the DOT11_STATUS_INDICATION structure for completion indications.

## See also

[OID_DOT11_RESET_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-reset-request)