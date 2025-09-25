# IMSCEPSetup::IsMSCEPStoreEmpty

## Description

The **IsMSCEPStoreEmpty** method always returns **VARIANT_TRUE**. It should not be used.

## Parameters

### `pbEmpty` [out]

This parameter always contains **VARIANT_TRUE**.

## Remarks

For the Network Device Enrollment Service (NDES) role, the My personal store is used. The default implementation does not use a separate store for signing and exchange certificates.

## See also

[IMSCEPSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-imscepsetup)