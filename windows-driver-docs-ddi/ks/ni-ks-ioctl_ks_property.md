# IOCTL_KS_PROPERTY IOCTL

## Description

An application can use IOCTL_KS_PROPERTY to get or set properties, or to determine the properties supported by a KS object. The application passes IOCTL_KS_PROPERTY with the parameters described below to the [KsSynchronousDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-kssynchronousdevicecontrol) function.

## Parameters

### Major code

### Input buffer

The contents of the client-specified **InBuffer** parameter depend on the property request, and are documented for each property set. For instance, clients requesting properties in the [KSPROPSETID_Pin](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-pin) property set specify a pointer to a [KSP_PIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksp_pin) structure.

### Input buffer length

The application places the size, in bytes, of the input buffer contents in the **InLength** parameter.

### Output buffer

Similarly, the type of output buffer required also depends on the property request.

### Output buffer length

The application places the size, in bytes, of the output buffer in the **OutLength** parameter.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the Status member is set to STATUS_SUCCESS.

## Remarks

For more information about input and output buffers and their sizes, see [KS Properties](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-properties).

Filters and pins support property sets using the **IOCTL_KS_PROPERTY** device I/O control. Although this IOCTL is defined with the METHOD_NEITHER flag, the property data is passed as the output buffer to the IOCTL and probed for read access. The [KsPropertyHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspropertyhandler) function handles properties requested through **IOCTL_KS_PROPERTY**.

For a list of valid flags and corresponding descriptions, see the reference page for the [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_description)

[KSPROPERTY_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_item)

[KSPROPERTY_MEMBERSHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_membersheader)

[KSPROPERTY_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_set)

[KSPROPERTY_VALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_values)