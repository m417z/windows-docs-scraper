# IX509AttributeOSVersion::InitializeEncode

## Description

The **InitializeEncode** method initializes the attribute from operating system version information.

## Parameters

### `strOSVersion` [in, optional]

A **BSTR** variable that contains the version information. The format of the string is *major.minor.build.platform*. This parameter is optional. If you do not specify a string, this method calls the **GetVersionEx** function.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) for this attribute is **XCN_OID_OS_VERSION** (1.3.6.1.4.1.311.13.2.3). For more information, see [CERTENROLL_OBJECTID](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-certenroll_objectid).

You must call either **InitializeEncode** or [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeosversion-initializedecode) before you can use an [IX509AttributeOSVersion](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributeosversion) object. The two methods complement each other. The **InitializeEncode** method enables you to construct an encoded [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) structure from raw data, and the **InitializeDecode** method enables you to initialize raw data from an encoded ASN.1 structure. You can call the [OSVersion](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeosversion-get_osversion) property to retrieve the raw data.

## See also

[IX509AttributeOSVersion](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributeosversion)