# DefDriverProc function

## Description

Provides default processing for any messages not processed by an installable driver. This function is intended to be used only within the [DriverProc](https://learn.microsoft.com/previous-versions/dd797918(v=vs.85)) function of an installable driver.

## Parameters

### `dwDriverIdentifier`

Identifier of the installable driver.

### `hdrvr`

Handle of the installable driver instance.

### `uMsg`

Driver message value.

### `lParam1`

32-bit message-dependent information.

### `lParam2`

32-bit message-dependent information.

## Return value

Returns nonzero if successful or zero otherwise.