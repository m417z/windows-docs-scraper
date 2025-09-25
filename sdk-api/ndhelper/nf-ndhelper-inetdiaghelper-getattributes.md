# INetDiagHelper::GetAttributes

## Description

The **GetAttributes** method retrieves additional information about a problem that the helper class extension has diagnosed.

## Parameters

### `pcelt` [out]

A pointer to a count of elements in the **HELPER_ATTRIBUTE** array.

### `pprgAttributes` [out]

A pointer to an array of [HELPER_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-helper_attribute) structures.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_OUTOFMEMORY** | There is not enough memory available to complete this operation. |
| **E_INVALIDARG** | One or more parameters has not been provided correctly. |
| **E_NOTIMPL** | This optional method is not implemented. |
| **E_ACCESSDENIED** | The caller does not have sufficient privileges to perform the diagnosis or repair operation. |
| **E_ABORT** | The diagnosis or repair operation has been canceled. |

Helper Class Extensions may return HRESULTS that are specific to the failures encountered in the function.

## Remarks

This method is not required when building a Helper Class Extension.

During the process of diagnosis and repair, a helper class may optionally return attributes to NDF that improve NDF's handling of the diagnosis. The predefined attributes that can be returned to NDF are as follows.

| Term | Description |
| --- | --- |
| werperameter (Type: AT_UINT32) | When diagnosis fails, an optional attribute for additional helper class specific Windows Error Reporting (WER) bucketing parameter. |
| werfile (Type: AT_STRING) | An optional attribute for adding helper class-specific files to Windows Error Reporting (WER) reports. |
| rootcauseid (Type: AT_GUID) | Helper Classes can often diagnose more than one problem at once. Analysis of the problem encountered can be improved in NDF if the extension returns a HelperAttribute of type AT_GUID with the pszName parameter set to rootcauseid and the Guid field set to a GUID identifying the specific problem encountered. These GUIDs are custom defined by the helper extension. |

## See also

[INetDiagHelper](https://learn.microsoft.com/windows/desktop/api/ndhelper/nn-ndhelper-inetdiaghelper)