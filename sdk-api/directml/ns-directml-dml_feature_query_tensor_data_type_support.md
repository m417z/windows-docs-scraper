# DML_FEATURE_QUERY_TENSOR_DATA_TYPE_SUPPORT structure

## Description

Used to query a DirectML device for its support for a particular data type within tensors. See [IDMLDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-checkfeaturesupport). The query type is **DML_FEATURE_QUERY_TENSOR_DATA_TYPE_SUPPORT**, and
the support data type is [DML_FEATURE_DATA_TENSOR_DATA_TYPE_SUPPORT](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_feature_data_tensor_data_type_support).

## Members

### `DataType`

Type: [**DML_TENSOR_DATA_TYPE**](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_tensor_data_type)

The data type about which you're querying for support.