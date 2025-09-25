# _PMI_EVENT structure

## Description

The PMI_EVENT structure contains information about a power metering and budgeting event that is signaled through the Power Meter Interface (PMI).

## Members

### `Version`

A value that specifies the version of this structure. For Windows 7, Windows Server 2008 R2, and later versions of Windows, this value must be 1.

### `EventType`

A [PMI_EVENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_event_type) enumeration value that specifies the PMI event type.

## Remarks

The PMI_EVENT structure contains information about a power metering or budgeting event. PMI generates an event for a power meter when one of the following occurs:

* The power meter's power metering or budgeting capabilities have changed.
* The power meter's power metering or budgeting configurations have changed.
* The power supply that is monitored by the power meter has exceeded the meter's configured power threshold.
* The power supply that is monitored by the power meter has exceeded or fallen below the meter's configured power budget.

A user-mode service or application registers for notification of these events through an [IOCTL_PMI_REGISTER_EVENT_NOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_register_event_notify) I/O control (IOCTL) query request.

The PMI_EVENT structure does not contain the current PMI data for the event. Depending on the value of the **EventType** member, the caller can retrieve the current PMI data through a PMI IOCTL query request. The following table describes the PMI IOCTL to use to query the changed data from a power meter for a query request.

| EventType value | PMI IOCTL | I/O request packet ([IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)) |
| --- | --- | --- |
| **PmiCapabilitiesChangedEvent** | [IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities) | The **AssociatedIrp.SystemBuffer** member is set to the address of an initiator-allocated buffer that contains any [PMI_CAPABILITIES_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_capabilities_type) enumeration value. |
| **PmiConfigurationChangedEvent** | [IOCTL_PMI_GET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_configuration) | The **AssociatedIrp.SystemBuffer** member is set to the address of an initiator-allocated buffer that contains any [PMI_CONFIGURATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_configuration_type) enumeration value. |
| **PmiThresholdEvent** | [IOCTL_PMI_GET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_configuration) | The **AssociatedIrp.SystemBuffer** member is set to the address of an initiator-allocated buffer that contains the [PMI_CONFIGURATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_configuration_type) enumeration value or **PmiThresholdConfiguration**. |
| **PmiBudgetEvent** | [IOCTL_PMI_GET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_configuration) | The **AssociatedIrp.SystemBuffer** member is set to the address of an initiator-allocated buffer that contains the [PMI_CONFIGURATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_configuration_type) enumeration value or **PmiBudgetConfiguration**. |
| **PmiAveragingIntervalChangedEvent** | [IOCTL_PMI_GET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_configuration) | The **AssociatedIrp.SystemBuffer** member is set to the address of an initiator-allocated buffer that contains the [PMI_CONFIGURATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_configuration_type) enumeration value or **PmiMeasurementConfiguration**. |

## See also

[IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities)

[IOCTL_PMI_GET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_configuration)

[IOCTL_PMI_REGISTER_EVENT_NOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_register_event_notify)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[PMI_CAPABILITIES_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_capabilities_type)

[PMI_CONFIGURATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_configuration_type)

[PMI_EVENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_event_type)