# IStreamPseudoRandomBased::get_Seed

## Description

Retrieves the seed value used by the random number generator.

## Parameters

### `value` [out]

Seed value for the random number generator.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IStreamPseudoRandomBased](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-istreampseudorandombased)

[IStreamPseudoRandomBased::get_ExtendedSeed](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-istreampseudorandombased-get_extendedseed)

[IStreamPseudoRandomBased::put_Seed](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-istreampseudorandombased-put_seed)