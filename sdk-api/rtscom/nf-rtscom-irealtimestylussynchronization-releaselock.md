# IRealTimeStylusSynchronization::ReleaseLock

## Description

Releases the specified lock.

## Parameters

### `lock` [in]

The [RealTimeStylusLockType Enumeration](https://learn.microsoft.com/windows/desktop/api/rtscom/ne-rtscom-realtimestyluslocktype) value that indicates which object lock to release.

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

The object locks can be used to help protect the RealTimeStylus (RTS) object's members and properties from modification. The lock remains in effect until released.

## See also

[DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85))

[IRealTimeStylusSynchronization Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylussynchronization)

[IRealTimeStylusSynchronization::AcquireLock Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylussynchronization-acquirelock)