# _SPB_CONNECTION_PARAMETERS structure

## Description

The **SPB_CONNECTION_PARAMETERS** structure contains the connection parameters for a target device on a [simple peripheral bus](https://learn.microsoft.com/previous-versions/hh450903(v=vs.85)).

## Members

### `Size`

The size, in bytes, of this structure. The [SpbTargetGetConnectionParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbtargetgetconnectionparameters) method uses the **Size** value to determine which version of this structure is being used. Use the [SPB_CONNECTION_PARAMETERS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spb_connection_parameters_init) function to initialize this member. For more information, see the following Remarks section.

### `ConnectionTag`

A pointer to the connection tag for this target. The connection tag is an opaque string that contains a connection ID that identifies the connection of the target device to the bus. For more information, see [Connection IDs for SPB-Connected Peripheral Devices](https://learn.microsoft.com/windows-hardware/drivers/spb/connection-ids-for-spb-connected-peripheral-devices).

### `ConnectionParameters`

A pointer to the connection parameters for this target. This member points to a memory buffer that contains the target-specific parameters that the SPB controller driver needs to communicate with the target. For more information, see the following Remarks section.

## Remarks

This structure contains information about the connection of a target device to the bus. When a client (peripheral driver) opens a logical connection to the target device, the SPB controller driver retrieves the connection settings for the device and stores these settings. Later, in response to an I/O request from the client to the device, the SPB controller driver uses the connection settings to configure the controller to access the device over the bus.

For example, the connection settings for a device on an I2C bus include the following:

* The bus-relative address of the target device.
* The number of address bits to use to access the target device.
* The bus clock frequency to use to access the target device.

The **ConnectionParameters** member of the **SPB_CONNECTION_PARAMETERS** structure is a pointer to a buffer that contains the connection settings for a target device on the bus. For a code example that uses the **ConnectionParameters** member to get these connection parameters, see [How to Get the Connection Settings for a Device](https://learn.microsoft.com/windows-hardware/drivers/spb/how-to-get-the-connection-settings-for-a-device).

Call the [SpbTargetGetConnectionParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbtargetgetconnectionparameters) method to get the connection parameters for an SPBTARGET handle that represents the target device. This method writes the connection parameters to a caller-supplied **SPB_CONNECTION_PARAMETERS** structure. Before passing this structure to **SpbTargetGetConnectionParameters**, initialize the structure by calling the [SPB_CONNECTION_PARAMETERS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spb_connection_parameters_init) function.

To open a connection on behalf of a client (peripheral driver), the SPB framework extension (SpbCx) calls your SPB controller driver's [EvtSpbTargetConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_connect) callback function. To close the connection, SpbCx calls the SPB controller driver's [EvtSpbTargetDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_disconnect) callback function. An SPB controller driver typically calls **SpbTargetGetConnectionParameters** from the driver's *EvtSpbTargetConnect* function.

## See also

[EvtSpbTargetConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_connect)

[EvtSpbTargetDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_disconnect)

[RH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/reshub/ns-reshub-_rh_query_connection_properties_output_buffer)

[SPB_CONNECTION_PARAMETERS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spb_connection_parameters_init)

[SpbTargetGetConnectionParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbtargetgetconnectionparameters)