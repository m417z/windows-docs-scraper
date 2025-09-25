# IKsAggregateControl::KsRemoveAggregate

## Description

The **KsRemoveAggregate** method removes a previously added COM server aggregate provider from the list of interface providers for the KS object that exposes the [IKsAggregateControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-iksaggregatecontrol) interface.

## Parameters

### `AggregateClass` [in]

Identifies the COM server to remove.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## See also

[IKsAggregateControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-iksaggregatecontrol)

[IKsAggregateControl::KsAddAggregate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksaggregatecontrol-ksaddaggregate)