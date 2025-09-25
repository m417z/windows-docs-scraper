# _UFX_INTERFACE_PROPRIETARY_CHARGER structure

## Description

Stores pointers to driver-implemented callback functions for handling proprietary charger operations.

## Members

### `InterfaceHeader`

The interface version number.

### `ProprietaryChargerDetect`

A pointer to the driver's implementation of the [UFX_PROPRIETARY_CHARGER_DETECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxproprietarycharger/nc-ufxproprietarycharger-ufx_proprietary_charger_detect) callback function.

### `ProprietaryChargerSetProperty`

A pointer to the driver's implementation of the [UFX_PROPRIETARY_CHARGER_SET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxproprietarycharger/nc-ufxproprietarycharger-ufx_proprietary_charger_set_property) callback function.

### `ProprietaryChargerAbortOperation`

A pointer to the driver's implementation of the [UFX_PROPRIETARY_CHARGER_ABORT_OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxproprietarycharger/nc-ufxproprietarycharger-ufx_proprietary_charger_abort_operation) callback function.

### `ProprietaryChargerResetOperation`

A pointer to the driver's implementation of the [UFX_PROPRIETARY_CHARGER_RESET_OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxproprietarycharger/nc-ufxproprietarycharger-ufx_proprietary_charger_reset_operation) callback function.

## See also

[USB filter driver for supporting proprietary chargers](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188012(v=vs.85))