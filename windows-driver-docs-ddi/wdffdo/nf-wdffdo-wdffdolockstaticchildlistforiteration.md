# WdfFdoLockStaticChildListForIteration function

## Description

[Applies to KMDF only]

The **WdfFdoLockStaticChildListForIteration** method prepares the framework for retrieving items from the static child list that belongs to a specified parent device.

## Parameters

### `Fdo` [in]

A handle to a framework device object that represents the parent device.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

Bus drivers that use static bus enumeration can call **WdfFdoLockStaticChildListForIteration**.

After calling **WdfFdoLockStaticChildListForIteration**, the driver can repeatedly call [WdfFdoRetrieveNextStaticChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoretrievenextstaticchild) to obtain information about each child device in the child list.

After the driver has finished calling [WdfFdoRetrieveNextStaticChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoretrievenextstaticchild), it must call [WdfFdoUnlockStaticChildListFromIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdounlockstaticchildlistfromiteration).

If the driver makes changes to the child list after calling **WdfFdoLockStaticChildListForIteration**, the framework stores all of the changes and notifies the Plug and Play (PnP) manager of the changes when the driver calls [WdfFdoUnlockStaticChildListFromIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdounlockstaticchildlistfromiteration).

The driver can nest calls to **WdfFdoLockStaticChildListForIteration** and [WdfFdoUnlockStaticChildListFromIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdounlockstaticchildlistfromiteration). If the driver nests calls to these methods, the framework stores all of the changes until the last call to **WdfFdoUnlockStaticChildListFromIteration**.

For more information about static child lists, see [Static Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/static-enumeration).

#### Examples

For a code example that uses **WdfFdoLockStaticChildListForIteration**, see [WdfFdoRetrieveNextStaticChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoretrievenextstaticchild).

## See also

[WdfFdoUnlockStaticChildListFromIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdounlockstaticchildlistfromiteration)