# KsCacheMedium function

## Description

The **KsCacheMedium** function improves graph building performance of pins that use Mediums to define connectivity.

## Parameters

### `SymbolicLink` [in]

The symbolic link used to open the device interface.

### `Medium` [in]

Points to the medium to cache.

### `PinDirection` [in]

Contains the direction of the Pin. 1 is output, 0 is input.

## Return value

**KsCacheMedium** returns STATUS_SUCCESS if the caching operation is successful, failure if it is not.

## Remarks

**KsCacheMedium** improves graph building performance by creating a registry key at:

**\System\CurrentControlSet\Control\MediumCache\GUID\DWORD\DWORD**

This enables fast lookup of connected filters in TvTuner and other complex graphs. Note that the GUID identifies the Medium of the connection, and that the DWORDs denote the device instance. The value name is the SymbolicLink for the driver, and ActualValue is the pin direction.turning.