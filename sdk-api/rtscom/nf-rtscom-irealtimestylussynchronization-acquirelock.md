# IRealTimeStylusSynchronization::AcquireLock

## Description

Retrieves the specified lock.

## Parameters

### `lock` [in]

The [RealTimeStylusLockType Enumeration](https://learn.microsoft.com/windows/desktop/api/rtscom/ne-rtscom-realtimestyluslocktype) value that indicates which object lock to use.

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

Use the object locks to help protect the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object's members and properties from modification.

## See also

[IRealTimeStylusSynchronization Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylussynchronization)

[IRealTimeStylusSynchronization::ReleaseLock Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylussynchronization-releaselock)