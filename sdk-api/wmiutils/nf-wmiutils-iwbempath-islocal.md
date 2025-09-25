# IWbemPath::IsLocal

## Description

The
**IWbemPath::IsLocal** method tests if the computer name passed in matches the computer name in the path, or if the server name in the path is **NULL** or ".".

## Parameters

### `wszMachine` [in]

Name of the computer to test.

## Return value

This method returns a **BOOL** indicating whether the path matches the passed in computer name, or if the server name in the path is **NULL** or ".".

## See also

[IWbemPath](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempath)

[IWbemPathKeyList](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempathkeylist)