## Description

Used to query a DirectML device for its support for one or more feature levels. See [IDMLDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-checkfeaturesupport). The feature constant is **DML_FEATURE_FEATURE_LEVELS**, and the support data type is [DML_FEATURE_DATA_FEATURE_LEVELS](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_feature_data_feature_levels).

## Members

### `RequestedFeatureLevelCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of elements in the *RequestedFeatureLevels* array.

### `RequestedFeatureLevels`

Type: \_Field\_size\_(RequestedFeatureLevelCount) **[DML_FEATURE_LEVEL](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_feature_level)\***

An array of feature levels to query support for. When [IDMLDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-checkfeaturesupport) returns, the [DML_FEATURE_DATA_FEATURE_LEVELS](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_feature_data_feature_levels) struct contains the highest feature level in this array that is supported by the device.

## Remarks
This query is useful in combination with the *minimumFeatureLevel* parameter of [DMLCreateDevice1](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-dmlcreatedevice1). By supplying a minimum feature level to **DMLCreateDevice1**, you can be guaranteed a *lower* bound to the underlying DirectML device's feature level support.

Using this query, you can then also retrieve an *upper* bound for the feature levels supported by this DirectML device. This information can then be used to achieve graceful fallbacks in cases where particular features are unavailable.

## Availability
This API was introduced in DirectML version `1.1.0`.

## See also

[IDMLDevice::CheckFeatureSupport method](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-checkfeaturesupport)

[DML_FEATURE enumeration](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_feature_level)

[DML_FEATURE_DATA_FEATURE_LEVELS structure](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_feature_data_feature_levels)