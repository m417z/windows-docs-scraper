# IWbemPath::SetNamespaceAt

## Description

The **IWbemPath::SetNamespace** method sets a namespace in a path using zero-based indexing to designate where in the path the namespace is positioned.

## Parameters

### `uIndex` [in]

Index of where the namespace is to be put. The leftmost namespace in the path is index 0 (zero) with each namespace to the right having a progressively higher index value. The maximum permitted value is the current number of namespaces, because specifying that would add a namespace to the end as the namespaces have a zero-based index.

### `pszName` [in]

Namespace name.

## Return value

This method returns an **HRESULT** indicating the status of the method call.

## See also

[IWbemPath](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempath)