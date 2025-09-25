## Description

Creates a root hub object for the specified host controller.

## Parameters

### `Controller` [in]

A handle to the controller object. The client driver retrieved the handle in a previous call to [**UcxControllerCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nf-ucxcontroller-ucxcontrollercreate).

### `Config` [in]

A pointer to a [**UCX\_ROOTHUB\_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_ucx_roothub_config) structure that describes various configuration operations for creating the root hub object.

### `Attributes` [in, optional]

A pointer to a caller-allocated [**WDF\_OBJECT\_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies attributes for the root hub object.

### `RootHub` [out]

A pointer to a variable that receives a handle to the new root hub object.

## Return value

The method returns STATUS\_SUCCESS if the operation succeeds. Otherwise, this method might return one an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) error code.

## Remarks

The client driver for the host controller must call this method after the [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) call. The parent of the new root hub object is the controller object.

Before calling this method, the client driver must initialize a [**UCX\_ROOTHUB\_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_ucx_roothub_config) structure by calling [**UCX\_ROOTHUB\_CONFIG\_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nf-ucxroothub-ucx_roothub_config_init_with_control_urb_handler). Supply function pointers to driver-supplied event callback implementations by call setting appropriate members of **UCX\_ROOTHUB\_CONFIG**. When events occur in the root hub object, UCX invokes those callback functions.

## Examples

```cpp
    UCX_ROOTHUB_CONFIG                      ucxRootHubConfig;
    UCXROOTHUB                              ucxRootHub;
    PUCX_ROOTHUB_CONTEXT                    ucxRootHubContext;

    // Create the root hub
    //
    UCX_ROOTHUB_CONFIG_INIT(&ucxRootHubConfig,
                            RootHub_EvtRootHubClearHubFeature,
                            RootHub_EvtRootHubClearPortFeature,
                            RootHub_EvtRootHubGetHubStatus,
                            RootHub_EvtRootHubGetPortStatus,
                            RootHub_EvtRootHubSetHubFeature,
                            RootHub_EvtRootHubSetPortFeature,
                            RootHub_EvtRootHubGetPortErrorCount,
                            RootHub_EvtRootHubInterruptTx,
                            RootHub_EvtRootHubGetInfo,
                            RootHub_EvtRootHubGet20PortInfo,
                            RootHub_EvtRootHubGet30PortInfo);

    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&objectAttributes, UCX_ROOTHUB_CONTEXT);

    status = UcxRootHubCreate(ucxController,
                              &ucxRootHubConfig,
                              &objectAttributes,
                              &ucxRootHub);

    if (!NT_SUCCESS(status)) {
        DbgTrace(TL_ERROR, Controller, "UcxRootHubCreate Failed %!STATUS!", status);
        goto Controller_WdfEvtDeviceAddEnd;
    }

    DbgTrace(TL_INFO, Controller, "UCX Root Hub created.");

    ucxControllerContext->UcxRootHub = ucxRootHub;

    ucxRootHubContext = GetUcxRootHubContext(ucxRootHub);
    ucxRootHubContext->UcxController = ucxController;
```

## See also

[**UCX\_ROOTHUB\_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_ucx_roothub_config)