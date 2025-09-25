# IWdsTransportCacheable::Commit

## Description

Commits object data members to the underlying data store if the [IWdsTransportCacheable::Dirty](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nf-wdstptmgmt-iwdstransportcacheable-get_dirty) property has been set. Otherwise, the method returns with no action.

## Remarks

Upon successful completion, this method clears the [Dirty](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nf-wdstptmgmt-iwdstransportcacheable-get_dirty) property.

## See also

[IWdsTransportCacheable](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportcacheable)