# INetDiagHelperInfo::GetAttributeInfo

## Description

The **GetAttributeInfo** method retrieves the list of key parameters needed by the Helper Class Extension.

## Parameters

### `pcelt` [out]

A pointer to a count of elements in the array pointed to by *pprgAttributeInfos*.

### `pprgAttributeInfos` [out]

A pointer to an array of [HelperAttributeInfo](https://learn.microsoft.com/windows/desktop/api/ndhelper/ns-ndhelper-helperattributeinfo) structures that contain helper class key parameters.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_OUTOFMEMORY** | There is not enough memory available to complete this operation. |
| **E_INVALIDARG** | One or more parameters has not been provided correctly. |
| **E_ACCESSDENIED** | The caller does not have sufficient privileges to perform the diagnosis or repair operation. |

Helper Class Extensions may return HRESULTS that are specific to the diagnoses or repairs.

## Remarks

The key parameter list is used by NDF to determine whether enough information is available for the extension to perform diagnosis. If the hypothesis to call the extension lacks a key attribute, the extension will not be called. Optional attributes will not be returned by this call.

## See also

[INetDiagHelperInfo](https://learn.microsoft.com/windows/desktop/api/ndhelper/nn-ndhelper-inetdiaghelperinfo)