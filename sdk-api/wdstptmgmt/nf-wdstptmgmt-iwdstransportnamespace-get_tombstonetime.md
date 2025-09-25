# IWdsTransportNamespace::get_TombstoneTime

## Description

Returns the UTC date and time when the server saved the namespace object of a deregistered namespace.

This property is read-only.

## Parameters

## Remarks

If the namespace has not been deregistered, this property fails with an error that indicates that the namespace is not valid at this time.

## See also

[IWdsTransportNamespace](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportnamespace)

[Tombstoned Property](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nf-wdstptmgmt-iwdstransportnamespace-get_tombstoned)