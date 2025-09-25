# IWbemObjectAccess::ReadQWORD

## Description

The **ReadQWORD** method reads 64 bits of property data identified by a property handle.

## Parameters

### `lHandle` [in]

Integer that contains the handle identifying the property.

### `pqw` [out]

Pointer to a unsigned 64-bit integer used to return the data being read.

## Return value

This method returns **WBEM_S_NO_ERROR** if successful. If the property was **NULL**, then the method returns **WBEM_S_FALSE**.

## See also

[IWbemObjectAccess](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemobjectaccess)