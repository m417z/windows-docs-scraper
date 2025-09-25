# IWbemPath::IsRelative

## Description

The
**IWbemPath::IsRelative** method tests if the path, as already set in the parser, is relative to a particular computer and namespace.

## Parameters

### `wszMachine` [in]

Name of the computer.

### `wszNamespace` [in]

Namespace being tested.

## Return value

This method returns a BOOL indicating whether the path is relative to the specified computer and namespace.

## See also

[IWbemPath](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempath)

[IWbemPathKeyList](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempathkeylist)