# UcmConnectorPdSourceCaps function

## Description

Notifies the USB connector manager framework extension (UcmCx) with the power source capabilities of the connector.

## Parameters

### `Connector` [in]

Handle to the connector object that the client driver received in the previous call to [UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate).

### `Pdos`

A caller-allocated array of [**UCM_PD_POWER_DATA_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_power_data_object) structures that describes the power source capabilities.

### `PdoCount` [in]

Number of elements in the array specified by *Pdos[]*.

## Return value

**UcmConnectorPdSourceCaps** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value.

## Remarks

If the connector (local connector) is the power source, the client driver can report the capabilities and changes to those capabilities to UcmCx by using **UcmConnectorPdSourceCaps**. If connector is a power sink, report the advertised capabilities received from partner by calling [UcmConnectorPdPartnerSourceCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorpdpartnersourcecaps). The client driver must call **UcmConnectorPdPartnerSourceCaps** each time the partner re-advertises its capabilities.

## See also

[UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate)