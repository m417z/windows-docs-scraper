## Description

Provides detail about the feature levels supported by a DirectML device. See [IDMLDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-checkfeaturesupport). The feature constant is **DML_FEATURE_FEATURE_LEVELS**, and the query data type is [DML_FEATURE_QUERY_FEATURE_LEVELS](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_feature_query_feature_levels).

## Members

### `MaxSupportedFeatureLevel`

Type: **[DML_FEATURE_LEVEL](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_feature_level)**

The highest feature level supplied in the query structure's *RequestedFeatureLevels* (see [DML_FEATURE_DATA_FEATURE_LEVELS](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_feature_data_feature_levels)) that is supported by this device.

> [!NOTE]
> Because this feature query only ever returns one of the values supplied in *RequestedFeatureLevels*, it's possible that the device supports an even higher feature level than the one returned by this query.

For example, DirectML version `1.4.0` supports a feature level of `DML_FEATURE_LEVEL_3_0`. If the *RequestedFeatureLevels* array contained only `DML_FEATURE_LEVEL_1_0` and `DML_FEATURE_LEVEL_2_0`, then this query would return `DML_FEATURE_LEVEL_2_0`, which is lower than the true feature level (3_0) supported by the device.

## Availability
This API was introduced in DirectML version `1.1.0`.

## See also

[IDMLDevice::CheckFeatureSupport method](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-checkfeaturesupport)

[DML_FEATURE enumeration](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_feature_level)

[DML_FEATURE_QUERY_FEATURE_LEVELS structure](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_feature_query_feature_levels)