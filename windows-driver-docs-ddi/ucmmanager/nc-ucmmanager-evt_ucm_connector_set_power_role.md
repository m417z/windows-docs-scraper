# EVT_UCM_CONNECTOR_SET_POWER_ROLE callback function

## Description

The client driver's implementation of the *EVT_UCM_CONNECTOR_SET_POWER_ROLE* event callback function that sets the power role of the connector to the specified role when attached to a partner connector.

## Parameters

### `Connector` [in]

Handle to the connector that the client driver received in a previous call to the [UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate) method.

### `PowerRole` [in]

A [UCM_POWER_ROLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ne-ucmtypes-_ucm_power_role)-typed flag that specifies the role to set.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it must return a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

To register an *EVT_UCM_CONNECTOR_SET_POWER_ROLE* callback function, the client must call [UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate).

The USB connector manager framework extension (UcmCx) can request either **UcmPowerRoleSink** or **UcmPowerRoleSource**. If the port is already in the requested role, the client driver can complete the request without any changes. Otherwise, it starts a power-role swap operation (PR_Swap). The driver calls [UcmConnectorPowerDirectionChanged](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorpowerdirectionchanged) to notify UcmCx about the success or failure of that operation.
The driver can call that method within the callback function.

The role persists for the current connection.

If a role-swap operation is pending, UcmCx does not request another role swap. Those operations are serialized across power and data role swaps.

After the swap operation completes, if the partner port sends a PR_Swap request, the client driver must reject the request.

#### Examples

```

EVT_UCM_CONNECTOR_SET_POWER_ROLE     EvtSetPowerRole;

NTSTATUS
EvtSetPowerRole(
    UCMCONNECTOR Connector,
    UCM_POWER_ROLE PowerRole
    )
{
    PCONNECTOR_CONTEXT connCtx;

    TRACE_INFO("EvtSetPowerRole(%!UCM_POWER_ROLE!) Entry", PowerRole);

    connCtx = GetConnectorContext(Connector);

    //PR_Swap operation.

    TRACE_FUNC_EXIT();
    return STATUS_SUCCESS;
}

```

## See also

[UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate)