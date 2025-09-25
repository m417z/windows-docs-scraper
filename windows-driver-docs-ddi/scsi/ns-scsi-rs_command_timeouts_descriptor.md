## Description

The **RS_COMMAND_TIMEOUTS_DESCRIPTOR** structure contains command timeout information from the start of processing a command to its reported completion.

## Members

### `DescriptorLength[2]`

The length of this structure.

### `Reserved`

Reserved for internal use.

### `CommandSpecific`

Contains timeout information defined for a specific command, such as the write buffer command.

### `NominalCommandProcessingTimeoutInSec[4]`

Indicates the minimum amount of time, in seconds, that the application client should wait before checking the progress of the command. A value of zero means that no timeout is specified.

### `RecommendedCommandTimeoutInSec[4]`

Specifies the recommended time, in seconds, that the application client should wait before timing out the command. A value of zero means that no time is specified.

## Remarks

Values contained in the command timeouts descriptor do not include times that are outside the control of the device server.

For commands that cause a change in power condition, values contained in the command timeouts descriptor do not include transition time.

## See also