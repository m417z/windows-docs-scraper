# KsTopologyPropertyHandler function

## Description

The **KsTopologyPropertyHandler** function performs standard handling of the static members of the [KSPROPSETID_Topology](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-topology) Property Set. The function uses the [KSTOPOLOGY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kstopology) structure, which describes the set of information that is returned by this property set.

## Parameters

### `Irp` [in]

Specifies the IRP handling the property request.

### `Property` [in]

Specifies the specific property being queried.

### `Data` [in, out]

Specifies the topology property-specific data.

### `Topology` [in]

Points to a [KSTOPOLOGY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kstopology) structure containing the topology information.

## Return value

The **KsTopologyPropertyHandler** function returns STATUS_SUCCESS if successful, or it returns an error specific to the property being handled. The function always fills in the IO_STATUS_BLOCK.Information field of the PIRP.IoStatus element within the IRP. It does not set the IO_STATUS_BLOCK.Status field, nor does it complete the IRP.