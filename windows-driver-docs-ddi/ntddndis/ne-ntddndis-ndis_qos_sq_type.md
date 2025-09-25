## Description

The **NDIS_QOS_SQ_TYPE** enumeration specifies the type of an NDIS Quality of Service (QoS) Scheduler Queue (SQ).

## Constants

The following SQ types are defined:

### `NdisQosSqTypeUndefined`

An undefined SQ type used for validation in code.

### `NdisQosSqTypeStandard`

A standard (non-GFT) SQ.

### `NdisQosSqTypeGFT`

Not currently in use.

### `NdisQosSqTypeMax`

Used for validation in code.

## Remarks

The **NDIS_QOS_SQ_TYPE** enumeration is a member of the [**NDIS_QOS_SQ_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-ndis_qos_sq_parameters), [**NDIS_QOS_SQ_ARRAY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-ndis_qos_sq_parameters_enum_array), and [**NDIS_QOS_SQ_STATS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-ndis_qos_sq_stats) structures.

## See also

[**NDIS_QOS_SQ_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-ndis_qos_sq_parameters)

[**NDIS_QOS_SQ_ARRAY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-ndis_qos_sq_parameters_enum_array)

[**NDIS_QOS_SQ_STATS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-ndis_qos_sq_stats)

[**NDIS_QOS_OFFLOAD_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-ndis_qos_offload_capabilities)