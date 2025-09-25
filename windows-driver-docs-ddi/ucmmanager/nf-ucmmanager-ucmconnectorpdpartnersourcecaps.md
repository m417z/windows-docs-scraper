# UcmConnectorPdPartnerSourceCaps function

## Description

Notifies the USB connector manager framework extension (UcmCx) with the power source capabilities of the partner connector.

## Parameters

### `Connector` [in]

Handle to the connector object that the client driver received in the previous call to [UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate).

### `Pdos`

A caller-allocated array of [**UCM_PD_POWER_DATA_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_power_data_object) structures that describes the power source capabilities.

### `PdoCount` [in]

Number of elements in the array specified by *Pdos[]*.

## Return value

**UcmConnectorPdPartnerSourceCaps** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value.

## Remarks

When using a Type-C connector for charging by using the power delivery (PD) mechanism, the local connector queries the partner connector for its supported power sourcing capabilities. That query is not required if the partner connector is the power source because in that case, the local connector cached the initial advertisement when the partner connector was attached. If the source capabilities changed, it sends an update to the local connector.

If the partner connector is the power sink, the local connector port must query for the latest capabilities.

#### Examples

```
        UCM_PD_POWER_DATA_OBJECT Pdos[1];

        UCM_PD_POWER_DATA_OBJECT_INIT_FIXED(&Pdos[0]);

        Pdos[0].FixedSupplyPdo.VoltageIn50mV = 100;         // 5V
        Pdos[0].FixedSupplyPdo.MaximumCurrentIn10mA = 150;  // 1.5 A

        status = UcmConnectorPdPartnerSourceCaps(
            Connector,
            Pdos,
            ARRAYSIZE(Pdos));
        if (!NT_SUCCESS(status))
        {
            TRACE_ERROR(
                "UcmConnectorPdPartnerSourceCaps() failed with %!STATUS!.",
                status);
            goto Exit;
        }

```

## See also

[UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate)