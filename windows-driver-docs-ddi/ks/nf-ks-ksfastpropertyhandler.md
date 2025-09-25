# KsFastPropertyHandler function

## Description

The **KsFastPropertyHandler** function handles fast property requests through IOCTL_KS_PROPERTY. It responds to all property identifiers defined by the sets that are also contained in the fast I/O list. This function can only be called at PASSIVE_LEVEL.

## Parameters

### `FileObject`

### `Property`

### `PropertyLength`

### `Data`

### `DataLength`

### `IoStatus`

### `PropertySetsCount`

### `PropertySet`

## Return value

The **KsFastPropertyHandler** function returns **TRUE** if the request was handled, or **FALSE** if the request was not handled. If **FALSE** is returned, an IRP is generated. If the request was handled, the function sets the IoStatus->Information element, either through setting it to zero because of an internal error, or through a property handler setting it. The property handler also sets the IoStatus->Status field when the property is actually handled.

## Remarks

The owner of a property set can perform prefiltering or postfiltering of the property handling, as well as processing requests made through the fast I/O dispatch interface for device control. The **KsFastPropertyHandler** function is only used to process requests that can be fulfilled quickly. The *Wait* parameter of the fast I/O function is not passed and is assumed to be **TRUE**.

## See also

[KsPropertyHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspropertyhandler)