# RealTimeStylusLockType enumeration

## Description

Specifies the locks within the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object that protect the **RealTimeStylus Class** object's members and properties from modification.

## Constants

### `RTSLT_ObjLock:0x1`

The object lock protects the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object's members and properties from modification.

### `RTSLT_SyncEventLock:0x2`

The object lock protects the synchronous plug-in collection from modification during event broadcasts.

### `RTSLT_AsyncEventLock:0x4`

The object lock protects the asynchronous plug-in collection from modification during event broadcasts.

### `RTSLT_ExcludeCallback:0x8`

The system excludes callbacks from the object's event or modification lock.

### `RTSLT_SyncObjLock:0xb`

The object lock protects the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) synchronous object's members and properties from modification.

### `RTSLT_AsyncObjLock:0xd`

The object lock protects the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) asynchronous object's members and properties from modification.

## Remarks

You can use these locks when you need to protect access to the plug-in collections or properties of the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object through the [IRealTimeStylusSynchronization Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylussynchronization) interface.

For example, the window's handle can be locked to prevent it from being altered.

## See also

[RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class)

[RealTimeStylus Reference](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-reference)

[RealTimeStylus Structures](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-structures)