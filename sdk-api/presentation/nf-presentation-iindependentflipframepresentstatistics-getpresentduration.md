## Description

Gets the actual amount of time the present was displayed.

## Return value

TYPE: **[SystemInterruptTime](https://learn.microsoft.com/windows/win32/api/presentationtypes/ns-presentationtypes-systeminterrupttime)**

The actual amount of time the present was displayed.

## Remarks

The actual present duration may be different from the preferred present duration requested by the application if the system decided not to honor the preferred duration. This usually happens either because it was not supported by the driver, or other content on screen influenced the system to go with another duration.

## See also