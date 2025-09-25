# IDataCollectorSet::SetValue

## Description

Sets a user-defined value.

## Parameters

### `key` [in]

The name of the value.

### `value` [in]

The value associated with the key.

## Return value

Returns S_OK if successful.

## Remarks

You can specify one or more user-defined values. If you specify a key that currently exists, the current value is overwritten. To remove a value, set the *pValue* parameter to **NULL**.

You use the key value if you want to perform variable substitution in the [IDataCollectorSet::TaskArguments](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_taskarguments) property.

## See also

[IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset)

[IDataCollectorSet::GetValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-getvalue)