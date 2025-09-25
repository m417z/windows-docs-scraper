# KsFastMethodHandler function

## Description

The **KsFastMethodHandler** function handles fast methods requested through IOCTL_KS_METHOD. It responds to all method identifiers defined by the sets that are also contained in the fast I/O list. This function can only be called at PASSIVE_LEVEL.

## Parameters

### `FileObject` [in]

Specifies the file object on which the request was made.

### `Method` [in]

Specifies the original method parameter. This will always be on FILE_LONG_ALIGNMENT, but may not be on FILE_QUAD_ALIGNMENT.

### `MethodLength` [in]

Specifies the length indicated by the caller of the method parameter.

### `Data` [in, out]

Specifies the original unaligned data parameter.

### `DataLength` [in]

Specifies the length indicated by the caller of the data parameter.

### `IoStatus` [out]

Specifies an aligned structure that is used to return error status and information.

### `MethodSetsCount` [in]

Indicates the number of method set structures being passed.

### `MethodSet` [in]

Specifies the pointer to the list of method set information.

## Return value

The **KsFastMethodHandler** function returns **TRUE** if the request is handled, or **FALSE** if the request is not handled. If the request is not handled, an IRP is generated. If the request was handled, the function sets the IoStatus->Information element to zero because of an internal error or the element is set by a method handler. The method handler also sets the IoStatus->Status field when the method is handled.

## Remarks

The owner of a method set can perform prefiltering or postfiltering of the method handling using the **KsFastMethodHandler** and **KsMethodHandler** functions. The **KsFastMethodHandler** function is used to process requests made through the fast I/O dispatch interface for Device Control. It is only used to process requests that can be fulfilled quickly. The *Wait* parameter of the fast I/O function is not passed and assumed to be **TRUE**.

## See also

[KsMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksmethodhandler)