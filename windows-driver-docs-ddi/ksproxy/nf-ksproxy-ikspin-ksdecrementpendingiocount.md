# IKsPin::KsDecrementPendingIoCount

## Description

The **KsDecrementPendingIoCount** method decrements the number of input/output (I/O) operations that are in progress on a pin.

## Return value

Returns an integer from 0 to *n*, the value that represents the new number of I/O operations that are in progress.

## Remarks

The **KsDecrementPendingIoCount** method is typically called from within an interface handler as described in the following sequence:

1. The proxy creates an instance of an interface handler ([IKsInterfaceHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-iksinterfacehandler)) to handle a particular media type.
2. A client calls the [IKsInterfaceHandler::KsSetPin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksinterfacehandler-kssetpin) method to inform that interface handler about the pin with which to communicate when passing data.
3. The client calls the [IKsInterfaceHandler::KsProcessMediaSamples](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksinterfacehandler-ksprocessmediasamples) method to move samples from or to the assigned pin. **KsProcessMediaSamples** performs I/O operations and for each I/O operation, calls [IKsPin::KsIncrementPendingIoCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-ikspin-ksincrementpendingiocount) to increment the I/O count.
4. The client calls the [IKsInterfaceHandler::KsCompleteIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksinterfacehandler-kscompleteio) method to complete an I/O operation. **KsCompleteIo** calls **KsDecrementPendingIoCount** to decrement the I/O count.

## See also

[IKsInterfaceHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-iksinterfacehandler)

[IKsInterfaceHandler::KsCompleteIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksinterfacehandler-kscompleteio)

[IKsInterfaceHandler::KsProcessMediaSamples](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksinterfacehandler-ksprocessmediasamples)

[IKsInterfaceHandler::KsSetPin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksinterfacehandler-kssetpin)

[IKsPin::KsIncrementPendingIoCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-ikspin-ksincrementpendingiocount)