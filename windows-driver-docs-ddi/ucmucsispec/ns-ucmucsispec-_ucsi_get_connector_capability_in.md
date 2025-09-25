# _UCSI_GET_CONNECTOR_CAPABILITY_IN structure

## Description

Used in the **GET_CONNECTOR_CAPABILITY** command.

## Members

### `OperationMode`

This field indicates the mode that the connector can support.

### `OperationMode.AsUInt8`

For internal use.

### `OperationMode.DfpOnly`

Indicates that the connector supports only DFP mode.

### `OperationMode.UfpOnly`

Indicates that the connector supports only UFP mode.

### `OperationMode.Drp`

Indicates that the connector supports DRP mode.

### `OperationMode.AudioAccessoryMode`

Indicates that the connector supports audio accessory mode.

### `OperationMode.DebugAccessoryMode`

Indicates that the connector supports debug accessory mode.

### `OperationMode.Usb2`

Indicates that the connector supports USB2 mode.

### `OperationMode.Usb3`

Indicates that the connector supports USB3 mode.

### `OperationMode.AlternateMode`

Indicates that the connector supports an alternate mode.

### `Provider`

Indicates that the connector is capable of providing power.

### `Consumer`

Indicates that the connector is capable of consuming power.

### `SwapToDfp`

Indicates that the connector is capable of accepting swap to DFP.

### `SwapToUfp`

Indicates that the connector is capable of accepting swap to UFP.

### `SwapToSrc`

Indicates that the connector is capable of accepting swap to SRC.

### `SwapToSnk`

Indicates that the connector is capable of accepting swap to SNK.

## Remarks

See Table 4-17 in [UCSI spec version 1.2](https://www.intel.com/content/dam/www/public/us/en/documents/technical-specifications/usb-type-c-ucsi-spec.pdf).

## See also

- [UCSI_GET_CONNECTOR_CAPABILITY_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsispec/ns-ucmucsispec-_ucsi_get_connector_capability_command)
- [UCSI spec version 1.2](https://www.intel.com/content/dam/www/public/us/en/documents/technical-specifications/usb-type-c-ucsi-spec.pdf)