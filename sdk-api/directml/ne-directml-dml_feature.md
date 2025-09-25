## Description

Defines a set of optional features and capabilities that can be queried from the DirectML device. See [IDMLDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-checkfeaturesupport).

## Constants

### `DML_FEATURE_TENSOR_DATA_TYPE_SUPPORT`

Allows querying for tensor data type support. The query type is [DML_FEATURE_QUERY_TENSOR_DATA_TYPE_SUPPORT](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_feature_query_tensor_data_type_support), and the support data type is [DML_FEATURE_DATA_TENSOR_DATA_TYPE_SUPPORT](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_feature_data_tensor_data_type_support).

### `DML_FEATURE_FEATURE_LEVELS`

Allows querying for the feature levels supported by the device. The query type is [DML_FEATURE_QUERY_FEATURE_LEVELS](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_feature_query_feature_levels), and the support data type is [DML_FEATURE_DATA_FEATURE_LEVELS](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_feature_data_feature_levels).

## See also

* [IDMLDevice::CheckFeatureSupport method](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-checkfeaturesupport)
* [DML_FEATURE_QUERY_TENSOR_DATA_TYPE_SUPPORT](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_feature_query_tensor_data_type_support)
* [DML_FEATURE_DATA_TENSOR_DATA_TYPE_SUPPORT](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_feature_data_tensor_data_type_support)
* [DML_FEATURE_QUERY_FEATURE_LEVELS](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_feature_query_feature_levels)
* [DML_FEATURE_DATA_FEATURE_LEVELS](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_feature_data_feature_levels)