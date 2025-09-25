# WcmTargetMode enumeration

## Description

Enumerates the various target modes. A target mode identifies how the redirections, from the target, are handled.

## Constants

### `OfflineMode:1`

This value indicates that the only expansions that will be performed on environment variables are those defined in the target.

### `OnlineMode:2`

This value indicates that the expansions will preferentially expand from the target. If a matching expansion is not found, the expansions will fall through to the current environment of the process.