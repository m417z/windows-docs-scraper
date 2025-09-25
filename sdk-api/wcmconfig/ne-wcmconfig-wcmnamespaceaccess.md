# WcmNamespaceAccess enumeration

## Description

Describes the options passed to the [ISettingsEngine::GetNamespace](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsengine-getnamespace) method to choose how the namespace must be accessed. Read and write access must be used if the intent is to change settings and read-only access must be used if the intent is only to inspect the settings.

## Constants

### `ReadOnlyAccess:1`

Request read-only access.

### `ReadWriteAccess:2`

Request read and write access.