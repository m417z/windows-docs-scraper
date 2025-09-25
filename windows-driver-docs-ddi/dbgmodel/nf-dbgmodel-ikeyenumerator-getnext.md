# IKeyEnumerator::GetNext

## Description

 Moves the iterator forward and fetches the name of the next key and, optionally, its value (or a reference to it) and associated metadata.
Note that depending on how this enumerator was acquired, the object returned in the value field may be the value associated with the key (EnumerateKeys), the resolved value of any property that the key refers to (EnumerateKeyValues), or a reference to the key (EnumerateKeyReferences).
If there was an error in resolving the value of the key (for EnumerateKeyValues, for instance), the method may return an error *AND* fill value with an error object. When the enumerator hits the end of the sequence, E_BOUNDS will be returned.

## Parameters

### `key`

The name of the key being enumerated is returned here. The caller is responsible for freeing this string with the SysFreeString method.

### `value`

The value of the key being enumerated is returned here. Depending on how the enumerator was acquired, this value may be the value associated with the key (EnumerateKeys), the resolved value of any property that the key refers to (EnumerateKeyValues), or a reference to the key (EnumerateKeyReferences).

### `metadata`

Any metadata associated with the key is optionally returned in this argument.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IKeyEnumerator interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-ikeyenumerator)