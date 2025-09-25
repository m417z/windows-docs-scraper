# IKsAggregateControl::KsAddAggregate

## Description

The **KsAddAggregate** method adds a COM server as an aggregate provider to the list of interface providers for the KS object that exposes the [IKsAggregateControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-iksaggregatecontrol) interface.

## Parameters

### `AggregateClass` [in]

Identifies the COM server to add.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## See also

[IKsAggregateControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-iksaggregatecontrol)

[IKsAggregateControl::KsRemoveAggregate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksaggregatecontrol-ksremoveaggregate)