# UcmConnectorCreate function

## Description

Creates a connector object.

## Parameters

### `WdfDevice` [in]

A handle to a framework device object that the client driver received in the previous call to [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `Config` [in]

A pointer to a caller-supplied [UCM_CONNECTOR_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_config) structure that is initialized by calling [UCM_CONNECTOR_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucm_connector_config_init).

### `Attributes` [in]

A pointer to a caller-supplied [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains attributes for the new connector object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `Connector` [out]

A pointer to a location that receives a handle to the new connector object.

## Return value

**UcmConnectorCreate** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value.

## Remarks

If the client driver specifies a connector identifier that is already in use, the method fails with STATUS_INVALID_PARAMETER error code.

If the Type-C connector is specified to be a Dual-Role port (DRP), the client driver must register its [EVT_UCM_CONNECTOR_SET_DATA_ROLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nc-ucmmanager-evt_ucm_connector_set_data_role) event callback.

The parent object is WdfDevice. You can set the **ParentObject** member of [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) to NULL or the WDFDEVICE handle. The connector object gets deleted when the parent WDFDEVICE object gets deleted.

An appropriate place for a UCM client driver to call **UcmConnectorCreate** is in [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) or [EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry). Conversely, the driver should release the UCMCONNECTOR handle in [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) or [EvtDeviceD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit).

#### Examples

This example code shows how to create a Type-C connector that is PD-capable.

```

    UCMCONNECTOR Connector;

    UCM_CONNECTOR_CONFIG_INIT(&connCfg, 0);

    UCM_CONNECTOR_TYPE_C_CONFIG_INIT(
        &connCfg.TypeCConfig,
        UcmTypeCOperatingModeDrp,
        UcmTypeCCurrentDefaultUsb | UcmTypeCCurrent1500mA | UcmTypeCCurrent3000mA);

    connCfg.EvtSetDataRole = EvtSetDataRole;

    UCM_CONNECTOR_PD_CONFIG_INIT(&connCfg.PdConfig, UcmPowerRoleSink | UcmPowerRoleSource);

    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attr, CONNECTOR_CONTEXT);

    status = UcmConnectorCreate(Device, &connCfg, &attr, &Connector);
    if (!NT_SUCCESS(status))
    {
        TRACE_ERROR(
            "UcmConnectorCreate failed with %!STATUS!.",
            status);
        goto Exit;
    }

    TRACE_INFO("UcmConnectorCreate() succeeded.");

```

## See also

[UCM_CONNECTOR_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_config)

[UCM_CONNECTOR_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucm_connector_config_init)