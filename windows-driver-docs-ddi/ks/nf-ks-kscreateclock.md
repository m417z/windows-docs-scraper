# KsCreateClock function

## Description

The **KsCreateClock** function creates a handle to a clock instance.

## Parameters

### `ConnectionHandle` [in]

Specifies the handle to the connection on which to create the clock.

### `ClockCreate` [in]

Specifies clock create parameters. This currently consists of a flag that must be set to zero.

### `ClockHandle` [out]

Specifies the new clock handle.

## Return value

The **KsCreateClock** function returns STATUS_SUCCESS if successful, or it returns an error on clock creation failure.