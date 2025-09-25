# IWdsTransportCacheable::get_Dirty

## Description

Receives a value that indicates whether object data has been modified.

This property is read-only.

## Parameters

## Remarks

All objects of the [IWdsTransportCacheable](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportcacheable) interface start with the **Dirty** property cleared. After any property is modified, **Dirty** is set to indicate that the object now contains changes not yet committed to its backing store. The **Dirty** property is cleared if the changes are committed or explicitly discarded via the appropriate methods.

## See also

[IWdsTransportCacheable](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportcacheable)