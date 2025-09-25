# IStreamPseudoRandomBased::put_ExtendedSeed

## Description

Sets a list of seed values for the random number generator and seeks to the start of stream.

**Note** This interface is currently not implemented.

## Parameters

### `values` [in]

Array of seed values used by the random number generator.

### `eCount` [in]

Number of seed values in the *values* array.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Not implemented.<br><br>Value: 0x80004001 |

## Remarks

Use this method to provide a seed value greater than 32 bits.

## See also

[IStreamPseudoRandomBased](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-istreampseudorandombased)

[IStreamPseudoRandomBased::get_ExtendedSeed](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-istreampseudorandombased-get_extendedseed)

[IStreamPseudoRandomBased::put_Seed](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-istreampseudorandombased-put_seed)