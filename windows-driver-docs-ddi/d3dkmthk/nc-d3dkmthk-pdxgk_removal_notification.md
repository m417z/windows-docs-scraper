# PDXGK_REMOVAL_NOTIFICATION callback

## Description

A callback indicating that the graphics device is being removed.

## Parameters

### `GraphicsDeviceHandle`

An opaque handle which should be provided when making callbacks to the graphics device.

### `PrivateHandle`

An opaque handle which will be provided in any callbacks. This handle must be globally unique, therefore, a pointer to the calling driver's PDO or FDO should be used.

## Remarks

Removal can occur on driver uninstall, device disable, device fault, and surprise removal. This callback is made at PASSIVE_LEVEL.