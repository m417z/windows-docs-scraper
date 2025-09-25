# IDMLDevice::CheckFeatureSupport

## Description

Gets information about the optional features and capabilities that are supported by the DirectML device.

## Parameters

### `feature`

Type: [**DML_FEATURE**](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_feature)

A constant from the [DML_FEATURE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_feature) enumeration describing the feature(s) that you want to query for support.

### `featureQueryDataSize`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The size of the structure pointed to by the *featureQueryData* parameter, if provided, otherwise 0.

### `featureQueryData` [in, optional]

Type: **const void***

An optional pointer to a query structure that corresponds to the value of the *feature* parameter. To determine the corresponding query type for each constant, see [DML_FEATURE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_feature).

### `featureSupportDataSize`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The size of the structure pointed to by the *featureSupportData* parameter.

### `featureSupportData` [out]

Type: **void***

A pointer to a support data structure that corresponds to the value of the *feature* parameter. To determine the corresponding support data type for each constant, see [DML_FEATURE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_feature).

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

If this method succeeds, it returns **S_OK**. Otherwise, it returns **DXGI_ERROR_UNSUPPORTED** if the [DML_FEATURE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_feature) is unrecognized or unsupported, and **E_INVALIDARG** if the parameters are incorrect.

## See also

[IDMLDevice](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldevice)