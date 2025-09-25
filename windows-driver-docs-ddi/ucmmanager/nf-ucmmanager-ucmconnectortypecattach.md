# UcmConnectorTypeCAttach function

## Description

Notifies the USB connector manager framework extension (UcmCx) when a partner connector is attached.

## Parameters

### `Connector` [in]

Handle to the connector object that the client driver received in the previous call to [UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate).

### `Params` [in]

A pointer to a driver-allocated [UCM_CONNECTOR_TYPEC_ATTACH_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_typec_attach_params) that has been initialized by calling [UCM_CONNECTOR_TYPEC_ATTACH_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucm_connector_typec_attach_params_init).

## Return value

**UcmConnectorTypeCAttach** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value.

## Remarks

When a connection to a partner connector is detected, the client driver calls this method to notify UcmCx with information about the partner connector. That information includes the connector role, down stream or upstream facing port, the amount of current connector can draw or deliver, and charging state. UcmCx uses that information to perform certain operations. For example, it may determine the role of the partner connector attached, and configure the USB controller in host or peripheral mode.

Typically, every **UcmConnectorTypeCAttach** call has a subsequent [UcmConnectorTypeCDetach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectortypecdetach) call to notify UcmCx when the partner connector is detached. However, when a powered cable without an upstream port is attached (indicated by **Params->PortPartnerType** set to **UcmTypeCPortStatePoweredCableNoUfp**). The client driver can call **UcmConnectorTypeCAttach** again when a connection is detected to the upstream port to the powered cable.

#### Examples

```
        UCM_CONNECTOR_TYPEC_ATTACH_PARAMS attachParams;

        UCM_CONNECTOR_TYPEC_ATTACH_PARAMS_INIT(
            &attachParams,
            UcmTypeCPortStateDfp);
        attachParams.CurrentAdvertisement = UcmTypeCCurrent1500mA;

        status = UcmConnectorTypeCAttach(
                    Connector,
                    &attachParams);
        if (!NT_SUCCESS(status))
        {
            TRACE_ERROR(
                "UcmConnectorTypeCAttach() failed with %!STATUS!.",
                status);
            goto Exit;
        }

        TRACE_INFO("UcmConnectorTypeCAttach() succeeded.");

```

## See also

[UCM_CONNECTOR_TYPEC_ATTACH_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_typec_attach_params)

[UCM_CONNECTOR_TYPEC_ATTACH_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucm_connector_typec_attach_params_init)

[UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate)