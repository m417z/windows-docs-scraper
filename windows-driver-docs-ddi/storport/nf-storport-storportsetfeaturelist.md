# StorPortSetFeatureList function

## Description

**StorPortSetFeatureList** sets the *StorPort* features that a miniport supports.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport's device extension.

### `FeatureCount`

Number of features that *FeatureList* points to.

### `FeatureList`

Pointer to an array of [**STORPORT_FEATURE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_feature_type) enum values that identify the *StorPort* features supported by the miniport.

## Return value

**StorPortSetFeatureList** returns a status code such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_SUCCESS | The feature list was set successfully. |
| STOR_STATUS_INVALID_PARAMETER | An input parameter is invalid; for example, *FeatureList* is NULL or *FeatureCount* is out of range. |
| STOR_STATUS_UNSUCCESSFUL | The operation failed. |

## Remarks

A miniport calls **StorPortSetFeatureList** to set the *StorPort* features that it supports. A miniport should call this function for each adapter in the beginning of its [*HwFindAdapter*](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize) routine.

## See also

[*HwFindAdapter*](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize)

[**STORPORT_FEATURE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_feature_type)