# StorPortSetAdapterBusType function

## Description

**StorPortSetAdapterBusType** is used to adjust the bus type of the adapter depending on its current configuration.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport immediately after the miniport driver calls [**StorPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `BusType` [in]

Contains a [**STORAGE_BUS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_bus_type) value that specifies the type of bus-specific configuration data to be set.

## Return value

The **StorPortSetAdapterBusType** routine returns one of the following status codes:

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_UNSUCCESSFUL | This routine was called outside the [**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) function. |
| STOR_STATUS_SUCCESS | This routine completed successfully. |
| STOR_STATUS_INVALID_PARAMETER | BusType is an invalid value. |

## Remarks

 Setting the **BusType** with this routine will allow you to override the global property set in the miniport INF without having to re-install the driver. This is useful for scenarios such as RAID support or support for multiple adapters with a different bus type.