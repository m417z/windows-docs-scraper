# WdfFdoUnlockStaticChildListFromIteration function

## Description

[Applies to KMDF only]

The **WdfFdoUnlockStaticChildListFromIteration** method unlocks the list of child devices for a specified device and processes any changes to the list that the driver made while the list was locked.

## Parameters

### `Fdo` [in]

A handle to a framework device object that represents the parent device.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

Bus drivers that use static bus enumeration can call **WdfFdoUnlockStaticChildListFromIteration**.

To lock a child list, the driver calls [WdfFdoLockStaticChildListForIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdolockstaticchildlistforiteration).

Calls to [WdfFdoLockStaticChildListForIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdolockstaticchildlistforiteration) can be nested and must be matched by an equal number of calls to **WdfFdoUnlockStaticChildListFromIteration**. If a driver adds or removes items from the child list while it is locked, the framework queues these changes and processes them after the last call to **WdfFdoUnlockStaticChildListFromIteration**.

For more information about static child lists, see [Enumerating the Devices on a Bus](https://learn.microsoft.com/windows-hardware/drivers/wdf/enumerating-the-devices-on-a-bus).

#### Examples

For a code example that uses **WdfFdoUnlockStaticChildListFromIteration**, see [WdfFdoRetrieveNextStaticChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoretrievenextstaticchild).

## See also

[WdfFdoLockStaticChildListForIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdolockstaticchildlistforiteration)