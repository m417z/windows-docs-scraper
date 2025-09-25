# _NDIS_CONFIGURATION_OBJECT structure

## Description

The NDIS_CONFIGURATION_OBJECT structure defines the attributes of a configuration object that an NDIS
driver can pass to the
[NdisOpenConfigurationEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationex) function.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_CONFIGURATION_OBJECT structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_CONFIGURATION_OBJECT, the
**Revision** member to NDIS_CONFIGURATION_OBJECT_REVISION_1, and the
**Size** member to NDIS_SIZEOF_CONFIGURATION_OBJECT_REVISION_1.

### `NdisHandle`

An NDIS handle that the caller obtained during initialization.

### `Flags`

A bitwise OR of the following flags:

#### NDIS_CONFIG_FLAG_FILTER_INSTANCE_CONFIGURATION

Set this flag if a monitoring filter driver must access the filter module configuration for a
specific filter module when there are multiple filter modules configured over the same miniport
adapter. Modifying filter drivers must not use this flag.

## Remarks

To configuration parameters in the registry, an NDIS driver can use the NDIS_CONFIGURATION_OBJECT
structure to define a configuration object and then call the
[NdisOpenConfigurationEx](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndisopenconfigurationex) function
to get a configuration handle.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisOpenConfigurationEx](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndisopenconfigurationex)