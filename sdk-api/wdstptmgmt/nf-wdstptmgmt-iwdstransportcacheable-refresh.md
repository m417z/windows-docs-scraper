# IWdsTransportCacheable::Refresh

## Description

Refreshes the object data members by rereading their values from the underlying data store. This is allowed only if the object's [IWdsTransportCacheable::Dirty](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nf-wdstptmgmt-iwdstransportcacheable-get_dirty) property has been set.

## Remarks

When called on an object whose [Dirty](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nf-wdstptmgmt-iwdstransportcacheable-get_dirty) property has been set, this method fails in order to avoid inadvertently losing changes made to the object. If the caller wants to ignore current changes and reread the stored data, the caller should call the [IWdsTransportCacheable::Discard](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nf-wdstptmgmt-iwdstransportcacheable-discard) method instead.

## See also

[IWdsTransportCacheable](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportcacheable)