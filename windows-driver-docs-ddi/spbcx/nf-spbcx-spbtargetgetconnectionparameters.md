# SpbTargetGetConnectionParameters function

## Description

The **SpbTargetGetConnectionParameters** method retrieves the connection parameters for a target device on the bus.

## Parameters

### `Target` [in]

An [SPBTARGET](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles) handle to the target device for which to retrieve the connection parameters.

### `ConnectionParameters` [out]

A pointer to a caller-allocated [SPB_CONNECTION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/ns-spbcx-_spb_connection_parameters) structure into which the method writes the connection parameters. The caller must previously have called the [SPB_CONNECTION_PARAMETERS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spb_connection_parameters_init) function to initialize this structure.

## Remarks

This method retrieves a set of connection parameters that the SPB controller driver requires to access the specified target device on the bus. For more information, see [SPB_CONNECTION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/ns-spbcx-_spb_connection_parameters).

A client (peripheral driver) that successfully opens a connection to a target has exclusive use of that target.

The SPB framework extension (SpbCx) calls your controller driver's [EvtSpbTargetConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_connect) and [EvtSpbTargetDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_disconnect) callback functions to open and close a connection.

**SpbTargetGetConnectionParameters** will not fail if it is called with a valid SPBTARGET handle.

## See also

[EvtSpbTargetConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_connect)

[EvtSpbTargetDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_disconnect)

[SPBTARGET](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles)

[SPB_CONNECTION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/ns-spbcx-_spb_connection_parameters)

[SPB_CONNECTION_PARAMETERS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spb_connection_parameters_init)