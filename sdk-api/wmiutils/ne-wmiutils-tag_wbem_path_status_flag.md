# tag_WBEM_PATH_STATUS_FLAG enumeration

## Description

Contains flags used to describe a path.

## Constants

### `WBEMPATH_INFO_ANON_LOCAL_MACHINE:0x1`

Path has "." or **NULL** as the server name.

### `WBEMPATH_INFO_HAS_MACHINE_NAME:0x2`

Server name is specified in the path and that name is not ".".

### `WBEMPATH_INFO_IS_CLASS_REF:0x4`

There is a class part to the path, but it is not an instance.

### `WBEMPATH_INFO_IS_INST_REF:0x8`

There is a class part to the path and there are key values.

### `WBEMPATH_INFO_HAS_SUBSCOPES:0x10`

A subscope is present in the path. Currently WMI does not support scopes.

### `WBEMPATH_INFO_IS_COMPOUND:0x20`

Compound key is used.

### `WBEMPATH_INFO_HAS_V2_REF_PATHS:0x40`

One or more keys has a CIM reference.

### `WBEMPATH_INFO_HAS_IMPLIED_KEY:0x80`

Key names are missing somewhere in the path.

### `WBEMPATH_INFO_CONTAINS_SINGLETON:0x100`

One or more singletons.

### `WBEMPATH_INFO_V1_COMPLIANT:0x200`

No scopes and no CIM_REFERENCE keys.

### `WBEMPATH_INFO_V2_COMPLIANT:0x400`

Reserved. Do not use.

### `WBEMPATH_INFO_CIM_COMPLIANT:0x800`

Reserved. Do not use.

### `WBEMPATH_INFO_IS_SINGLETON:0x1000`

Object is a singleton.

### `WBEMPATH_INFO_IS_PARENT:0x2000`

Path is just "..".

### `WBEMPATH_INFO_SERVER_NAMESPACE_ONLY:0x4000`

There is no class portion of the path.

### `WBEMPATH_INFO_NATIVE_PATH:0x8000`

Path parser was initialized using
[SetText](https://learn.microsoft.com/windows/desktop/api/wmiutils/nf-wmiutils-iwbempath-settext).

### `WBEMPATH_INFO_WMI_PATH:0x10000`

Reserved. Do not use.

### `WBEMPATH_INFO_PATH_HAD_SERVER:0x20000`

Server name was set by either
[SetText](https://learn.microsoft.com/windows/desktop/api/wmiutils/nf-wmiutils-iwbempath-settext) or
[SetServer](https://learn.microsoft.com/windows/desktop/api/wmiutils/nf-wmiutils-iwbempath-setserver).