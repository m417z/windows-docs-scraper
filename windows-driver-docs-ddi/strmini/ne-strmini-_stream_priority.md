# _STREAM_PRIORITY enumeration

## Description

_STREAM_PRIORITY enumerates available priority levels for the stream.

## Constants

### `High`

Highest priority, IRQL equal to the adapter's ISR.

### `Dispatch`

Medium priority, IRQL equal to dispatch level.

### `Low`

Lowest priority, IRQL equal to passive or APC level.

### `LowToHigh`

Go from low priority to high priority.