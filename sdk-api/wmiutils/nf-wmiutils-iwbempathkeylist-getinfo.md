# IWbemPathKeyList::GetInfo

## Description

The
**IWbemPathKeyList::GetInfo** method retrieves the status bits for the key.

## Parameters

### `uRequestedInfo` [in]

Reserved. Must be 0 (zero).

### `puResponse` [out]

Status for the key. The following bits indicate the values available.

#### WBEMPATH_INFO_IS_COMPOUND

Compound key is used.

#### WBEMPATH_INFO_HAS_V2_REF_PATHS

One or more of the keys has a CIM_REFERENCE.

#### WBEMPATH_INFO_HAS_IMPLIED_KEY

Key names are missing somewhere.

#### WBEMPATH_INFO_CONTAINS_SINGLETON

One or more singletons in the path.

## Return value

This method returns an **HRESULT** indicating the status of the method call.

## See also

[IWbemPath](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempath)

[IWbemPathKeyList](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempathkeylist)