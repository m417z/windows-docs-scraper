## Description

Specifies the reason why a cloud file was dehydrated.

## Constants

### `CF_CALLBACK_DEHYDRATION_REASON_NONE`

The cloud file has never been dehydrated after its creation.

### `CF_CALLBACK_DEHYDRATION_REASON_USER_MANUAL`

User explicitly dehydrated the cloud file.

### `CF_CALLBACK_DEHYDRATION_REASON_SYSTEM_LOW_SPACE`

The platform dehydrated the cloud file when experiencing low disk space on the volume where this file resides.

### `CF_CALLBACK_DEHYDRATION_REASON_SYSTEM_INACTIVITY`

The platform aged out the cloud file based on user defined policies.

### `CF_CALLBACK_DEHYDRATION_REASON_SYSTEM_OS_UPGRADE`

The platform dehydrated this file when reclaiming disk space in order to upgrade the OS.

## Remarks

## See also