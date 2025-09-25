# PDXGK_GRAPHICSPOWER_UNREGISTER callback function

## Description

A callback to un-register itself with the graphics driver.

## Parameters

### `DeviceHandle`

An opaque handle which should be provided when making callbacks to the graphics device.

### `PrivateHandle`

An opaque handle which will be provided in any callbacks. This handle must be globally unique, therefore, a pointer to the calling driver’s PDO or FDO should be used.

## Return value

Return STATUS_SUCCESS if the call succeeds.