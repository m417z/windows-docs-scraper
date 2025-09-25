# KeShouldYieldProcessor function

## Description

This function advises the caller if it should break out of a work loop running at DISPATCH_LEVEL or higher to allow other processing to take place.

## Return value

Returns TRUE if the caller should lower IRQL to below DISPATCH_LEVEL.

## Remarks

When this function returns TRUE:

* If the caller is running in thread context (i.e. not in an interrupt or DPC), it should lower IRQL to below DISPATCH_LEVEL.
* If the caller is within a DPC or cannot directly lower IRQL, it should queue work to a worker thread and return.

## See also