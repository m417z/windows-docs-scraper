# IDiscFormat2Data::get_ForceOverwrite

## Description

Determines if the data writer must overwrite the disc on overwritable media types.

## Parameters

### `value` [out]

Is VARIANT_TRUE if the data writer must overwrite the disc on overwritable media types; otherwise, VARIANT_FALSE.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IDiscFormat2Data](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2data)