# IKsPinEx::KsNotifyError

## Description

The **KsNotifyError** method notifies the filter graph of an error to give the filter graph an opportunity to halt.

## Parameters

### `Sample` [in]

Pointer to the **IMediaSample** interface for the associated media sample.

### `hr` [in]

Error value for notification. If ERROR_OPERATION_ABORTED (that is, the I/O was purposefully canceled), the filter graph is not notified.

## Remarks

The **KsNotifyError** method notifies the filter graph of the specific error using the EC_ERRORABORT event, which specifies that the error forced the termination of an I/O operation.

For more information about **IMediaSample**, see the Microsoft Windows SDK documentation.

## See also

[IKsPinEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-ikspinex)