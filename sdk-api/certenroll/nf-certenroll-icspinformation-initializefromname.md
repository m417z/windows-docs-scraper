# ICspInformation::InitializeFromName

## Description

The **InitializeFromName** method initializes the object from a string that contains a provider name. This method is web enabled.

## Parameters

### `strName` [in]

A **BSTR** variable that contains the name.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The object is already initialized. |

## Remarks

The **InitializeFromName** method opens the named provider and queries it to set the following property values on the [ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation) object:

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
* [Type](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_type)
* [Valid](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_valid)
* [Version](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_version)

The method adds the available algorithms to the [ICspAlgorithms](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspalgorithms) collection returned by the [CspAlgorithms](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_cspalgorithms) property. Call the [InitializeFromType](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-initializefromtype) method to initialize the object from a provider type.

## See also

[ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation)