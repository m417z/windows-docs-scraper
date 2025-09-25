# TAPI_TONEMODE enumeration

## Description

The **TAPI_TONEMODE** enum is used to describe the different selections that are used when generating line tones.

## Constants

### `TTM_RINGBACK:0x2`

The tone is a ringback tone. Exact definition is service-provider defined.

### `TTM_BUSY:0x4`

The tone is a busy tone. Exact definition is service-provider defined.

### `TTM_BEEP:0x8`

The tone is a beep, such as that used to announce the beginning of a recording. Exact definition is service-provider defined.

### `TTM_BILLING:0x10`

The tone is a billing information tone, such as a credit card prompt tone. Exact definition is service-provider defined.

## See also

[ITLegacyCallMediaControl2::GenerateTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol2-generatetone)