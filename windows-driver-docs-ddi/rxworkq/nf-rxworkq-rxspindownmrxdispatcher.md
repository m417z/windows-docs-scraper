# RxSpinDownMRxDispatcher function

## Description

**RxSpinDownMRxDispatcher** tears down the dispatcher context for a network mini-redirector.

## Parameters

### `pMRxDeviceObject` [in, out]

A pointer to the device object of the corresponding network mini-redirector driver.

## Return value

**RxSpinDownMRxDispatcher** returns STATUS_SUCCESS on success. On checked builds, this routine causes the system to ASSERT on failure.

## Remarks

The **RxSpinDownMRxDispatcher** routine will set a tear down request into the driver device object of the network mini-redirector driver (the **DispatcherContext.pTearDownEvent** member of the device object is set to **&TearDownEvent**) and wait for the driver to tear down any outstanding worker threads.

The **RxSpinDownMRxDispatcher** routine is also called internally by the **RxStopMiniRdr** and **RxpUnregisterMinirdr** routines.

## See also

[RxDispatchToWorkerThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxworkq/nf-rxworkq-rxdispatchtoworkerthread)

[RxPostToWorkerThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxworkq/nf-rxworkq-rxposttoworkerthread)