# ICspInformation::InitializeFromType

## Description

The **InitializeFromType** method initializes the object from the default cryptographic provider.

## Parameters

### `Type` [in]

An [X509ProviderType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509providertype) enumeration value that defines the provider type.

* If you specify XCN_PROV_NONE and set the *pAlgorithm* parameter to a value other than **NULL**, the default Cryptography API: Next Generation (CNG) provider is used.
* If you specify a value other than XCN_PROV_NONE and set the *pAlgorithm* parameter to **NULL**, the default legacy cryptographic service provider (CSP) is used.

### `pAlgorithm` [in, optional]

Pointer to an [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) interface that represents an algorithm OID. This parameter is optional and can be **NULL**. For more information, see the *Type* parameter.

### `MachineContext` [in]

A **VARIANT_BOOL** variable that indicates whether to use the computer or user context to determine the default provider for the specified provider type. Specify **VARIANT_TRUE** for the computer and **VARIANT_FALSE** for the user.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The object is already initialized. |

## Remarks

The **InitializeFromType** method validates the specified type and saves it in the [Type](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_type) property, retrieves the default provider, and sets the following property values on the [ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation) object:

* [CspAlgorithms](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_cspalgorithms)
* [HasHardwareRandomNumberGenerator](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_hashardwarerandomnumbergenerator)
* [IsHardwareDevice](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_ishardwaredevice)
* [IsRemovable](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_isremovable)
* [IsSmartCard](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_issmartcard)
* [IsSoftwareDevice](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_issoftwaredevice)
* [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_keyspec)
* [LegacyCsp](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_legacycsp)
* [MaxKeyContainerNameLength](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_maxkeycontainernamelength)
* [Name](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_name)
* [Valid](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_valid)
* [Version](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_version)

The method adds the available algorithms to the [ICspAlgorithms](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspalgorithms) collection returned by the [CspAlgorithms](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_cspalgorithms) property. Call the [InitializeFromName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-initializefromname) method to initialize the object from a CSP name.

## See also

[ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation)