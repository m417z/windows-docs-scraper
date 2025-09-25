## Description

Provides detail about whether a DirectML device supports a particular data type within tensors. See [IDMLDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-checkfeaturesupport). The query type is [DML_FEATURE_QUERY_TENSOR_DATA_TYPE_SUPPORT](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_feature_query_tensor_data_type_support), and
the support data type is **DML_FEATURE_DATA_TENSOR_DATA_TYPE_SUPPORT**.

## Members

### `IsSupported`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if the tensor data type is supported within tensors by the DirectML device. Otherwise, **FALSE**.

## See also

[IDMLDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-checkfeaturesupport)