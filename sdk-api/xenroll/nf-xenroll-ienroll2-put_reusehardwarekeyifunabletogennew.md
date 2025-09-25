# IEnroll2::put_ReuseHardwareKeyIfUnableToGenNew

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **ReuseHardwareKeyIfUnableToGenNew** property sets or retrieves a Boolean value that determines the action taken by the
certificate enrollment control object if an error is encountered when generating a new key.

This property was first defined in the [IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll2) interface.

This property is read/write.

## Parameters

## Remarks

This property is a Boolean value. This property affects only [cryptographic service providers](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) that return NTE_TOKEN_KEYSET_STORAGE_FULL. These CSPs are typically hardware-based; an example is a smart card. If this property is **TRUE** and an error is encountered while generating a new key, the certificate enrollment control object will reuse the existing hardware key. If this property is **FALSE** and an error is encountered while generating a new key, the certificate enrollment control object will not reuse the existing hardware key but will instead pass an error to the caller.

## See also

[IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll2)

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)