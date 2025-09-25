# IWscProduct::get_SignatureStatus

## Description

Returns the current status of the signature data for the security product.

## Parameters

### `pVal` [out]

A pointer to the status value of the signature of the security product. If the security product is a Firewall product, the return value is always **WSC_SECURITY_PRODUCT_UP_TO_DATE** because firewalls do not contain signature data.

## Return value

If the method succeeds, returns S_OK.

If the method fails, returns a Win32 error code.

## See also

[IWscProduct](https://learn.microsoft.com/windows/desktop/api/iwscapi/nn-iwscapi-iwscproduct)