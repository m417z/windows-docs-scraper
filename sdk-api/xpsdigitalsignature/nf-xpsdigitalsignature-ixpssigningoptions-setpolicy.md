# IXpsSigningOptions::SetPolicy

## Description

Sets the [XPS_SIGN_POLICY](https://learn.microsoft.com/windows/win32/api/xpsdigitalsignature/ne-xpsdigitalsignature-xps_sign_policy) value that represents the signing policy.

## Parameters

### `policy` [in]

The logical **OR** of the [XPS_SIGN_POLICY](https://learn.microsoft.com/windows/win32/api/xpsdigitalsignature/ne-xpsdigitalsignature-xps_sign_policy) values to be set as the signing policy.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

If an [XPS_SIGN_POLICY](https://learn.microsoft.com/windows/win32/api/xpsdigitalsignature/ne-xpsdigitalsignature-xps_sign_policy) value is set and it does not have a corresponding part in the package being signed, only the relationship type will be signed.

## See also

[IOpcSigningOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsigningoptions)

[IXpsSigningOptions](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssigningoptions)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS_SIGN_POLICY](https://learn.microsoft.com/windows/win32/api/xpsdigitalsignature/ne-xpsdigitalsignature-xps_sign_policy)