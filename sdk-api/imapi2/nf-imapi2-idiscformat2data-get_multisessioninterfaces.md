# IDiscFormat2Data::get_MultisessionInterfaces

## Description

Retrieves a list of available multi-session interfaces.

## Parameters

### `value` [out]

List of available multi-session interfaces. Each element of the array is a **VARIANT** of type **VT_DISPATCH**. Query the **pdispVal** member of the variant for any interface that inherits from [IMultisession](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-imultisession) interface, for example, [IMultisessionSequential](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-imultisessionsequential).

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |

**Note** This method does not return an error when called on blank optical media.

## Remarks

The array will always contain at least one element.

## See also

[IDiscFormat2Data](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2data)