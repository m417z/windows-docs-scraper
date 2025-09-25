# IWbemPath::GetInfo

## Description

The
**IWbemPath::GetInfo** method returns details about a path that has been placed into a parser object.

## Parameters

### `uRequestedInfo` [in]

Reserved for future use. Must be 0 (zero).

### `puResponse` [out]

Upon success, this bitmap is set to 0 (zero) or more bits in the following list.

#### WBEMPATH_INFO_ANON_LOCAL_MACHINE

Path has "." or **NULL** as the server name.

#### WBEMPATH_INFO_HAS_MACHINE_NAME

Server name is specified in the path and that name is not ".".

#### WBEMPATH_INFO_IS_CLASS_REF

There is a class part to the path, but it is not an instance.

#### WBEMPATH_INFO_IS_INST_REF

There is a class part to the path and there are key values.

#### WBEMPATH_INFO_HAS_SUBSCOPES

A subscope is present in the path. Currently WMI does not support scopes.

#### WBEMPATH_INFO_IS_COMPOUND

Compound key is used.

#### WBEMPATH_INFO_HAS_V2_REF_PATHS

One or more keys has a CIM reference.

#### WBEMPATH_INFO_HAS_IMPLIED_KEY

Key names are missing somewhere in the path.

#### WBEMPATH_INFO_CONTAINS_SINGLETON

One or more singletons.

#### WBEMPATH_INFO_V1_COMPLIANT

No scopes and no CIM_REFERENCE keys.

#### WBEMPATH_INFO_V2_COMPLIANT

Reserved. Do not use.

#### WBEMPATH_INFO_CIM_COMPLIANT

Reserved. Do not use.

#### WBEMPATH_INFO_IS_SINGLETON

Object is a singleton.

#### WBEMPATH_INFO_IS_PARENT

Path is just "..".

#### WBEMPATH_INFO_SERVER_NAMESPACE_ONLY

There is no class portion of the path.

#### WBEMPATH_INFO_NATIVE_PATH

Path parser was initialized using
[SetText](https://learn.microsoft.com/windows/desktop/api/wmiutils/nf-wmiutils-iwbempath-settext).

#### WBEMPATH_INFO_WMI_PATH

Reserved. Do not use.

#### WBEMPATH_INFO_PATH_HAD_SERVER

Server name was set by either
[SetText](https://learn.microsoft.com/windows/desktop/api/wmiutils/nf-wmiutils-iwbempath-settext) or
[SetServer](https://learn.microsoft.com/windows/desktop/api/wmiutils/nf-wmiutils-iwbempath-setserver).

## Return value

This method returns one of the following values.

## See also

[IWbemPath](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempath)