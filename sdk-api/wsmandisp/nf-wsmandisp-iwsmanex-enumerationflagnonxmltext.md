# IWSManEx::EnumerationFlagNonXmlText

## Description

The
**IWSManEx::EnumerationFlagNonXmlText**
method returns the value of the enumeration constant **WSManFlagNonXmlText** for
use in the *flags* parameter of the
[IWSManSession::Enumerate](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmansession-enumerate) method.

**WSManFlagNonXmlText** is a constant in the
**__WSManEnumFlags** enumeration. For more information, see
[Enumeration Constants](https://learn.microsoft.com/windows/desktop/WinRM/enumeration-constants).

## Parameters

### `flags` [out]

The value of the constant.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWSManEx](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanex)

[IWSManSession](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmansession)