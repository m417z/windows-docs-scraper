## Description

The **PKTMON_COMP_PROPERTY_IN** structure contains property information for setting component properties in the Packet Monitor infrastructure. This structure is passed to the **[PKTMON_PROVIDER_SET_COMP_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_set_comp_property)** callback to configure component behavior.

## Members

### `Header`

A [PKTMON_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_header) structure used for versioning and size validation.

### `Id`

A **[PKTMON_COMPONENT_PROPERTY_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmondefk/ne-pktmondefk-pktmon_component_property_id)** enumeration value that identifies which property is being set.

### `Value`

A pointer to the property value data. The format and interpretation of this data depends on the property ID.

### `Size`

The size in bytes of the data pointed to by the `Value` field.

## Remarks

This structure allows dynamic configuration of component properties after registration, enabling runtime adjustments to monitoring behavior.

## See also

- [PKTMON_PROVIDER_SET_COMP_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_set_comp_property)
- [PKTMON_COMPONENT_PROPERTY_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmondefk/ne-pktmondefk-pktmon_component_property_id)
- [PktMonClntSetComponentProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntsetcomponentproperty)