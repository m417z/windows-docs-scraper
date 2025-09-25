# IKsDataTypeHandler::KsQueryExtendedSize

## Description

The **KsQueryExtendedSize** method retrieves extended header information required for input and output (I/O) operations.

## Parameters

### `ExtendedSize` [out]

Pointer to a variable that receives the extended header size in bytes.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

If **KsQueryExtendedSize** returns zero at *ExtendedSize*, clients should not call the [KsPrepareIoOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksdatatypehandler-ksprepareiooperation) and [KsCompleteIoOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksdatatypehandler-kscompleteiooperation) methods of the [IKsDataTypeHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-iksdatatypehandler) interface because I/O preparation and completion operations are not required. For all other values that **KsQueryExtendedSize** returns at *ExtendedSize*, clients should allocate memory space for the extended stream header per the returned value and call **KsPrepareIoOperation** and **KsCompleteIoOperation** to prepare and complete the I/O operation associated with the header.

## See also

[IKsDataTypeHandler::KsCompleteIoOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksdatatypehandler-kscompleteiooperation)

[IKsDataTypeHandler::KsPrepareIoOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksdatatypehandler-ksprepareiooperation)