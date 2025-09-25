# PRJ_STARTVIRTUALIZING_OPTIONS structure

## Description

Options to provide when starting a virtualization instance.

## Members

### `Flags`

A flag for starting virtualization.

### `PoolThreadCount`

The number of threads the provider wants to create to service callbacks.

### `ConcurrentThreadCount`

The maximum number of threads the provider wants to run concurrently to process callbacks.

### `NotificationMappings`

An array of zero or more notification mappings. See the Remarks section of PRJ_NOTIFICATION MAPPING for more details.

### `NotificationMappingsCount`

The number of notification mappings provided in NotificationMappings.