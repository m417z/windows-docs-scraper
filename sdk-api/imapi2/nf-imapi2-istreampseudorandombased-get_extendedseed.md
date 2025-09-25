# IStreamPseudoRandomBased::get_ExtendedSeed

## Description

Retrieves an array of seed values used by the random number generator.

## Parameters

### `values` [out]

Array of seed values used by the random number generator.

### `eCount` [out]

Number of seed values in the *values* array.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Not implemented.<br><br>Value: 0x80004001 |

## See also

[IStreamPseudoRandomBased](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-istreampseudorandombased)

[IStreamPseudoRandomBased::get_Seed](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-istreampseudorandombased-get_seed)

[IStreamPseudoRandomBased::put_ExtendedSeed](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-istreampseudorandombased-put_extendedseed)