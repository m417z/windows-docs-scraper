# IWdsTransportCacheable::Discard

## Description

Discards all changes made to the object data members by clearing the [IWdsTransportCacheable::Dirty](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nf-wdstptmgmt-iwdstransportcacheable-get_dirty) property and then calling the object's [IWdsTransportCacheable::Refresh](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nf-wdstptmgmt-iwdstransportcacheable-refresh) method to reread the current object data.

## Remarks

This method can be called on any object.

Unlike [Refresh](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nf-wdstptmgmt-iwdstransportcacheable-refresh), which always refreshes object data (as long as the object's [Dirty](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nf-wdstptmgmt-iwdstransportcacheable-get_dirty) property has been set), this method checks first that the object's **Dirty** property has been set. If it has, the method resets the **Dirty** property and then rereads the current values of all data members. If **Dirty** has not been set, this method takes no action and returns immediately.

## See also

[IWdsTransportCacheable](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportcacheable)