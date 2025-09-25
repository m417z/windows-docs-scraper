# WINML_VARIABLE_DESC structure

## Description

**These APIs have been deprecated and should no longer be used:** Please use [Windows.AI.MachineLearning](https://learn.microsoft.com/uwp/api/windows.ai.machinelearning) instead.

Contains description properties of the variable.

## Members

### `Name`

The name of the variable.

### `Description`

The description of the variable.

### `FeatureType`

A [WINML_FEATURE_TYPE](https://learn.microsoft.com/windows/desktop/api/winml/ne-winml-winml_feature_type) containing the feature type of variable.

### `Required`

**true** if the variable is required; otherwise, **false**.

### `Tensor`

A [WINML_TENSOR_VARIABLE_DESC](https://learn.microsoft.com/windows/desktop/api/winml/ns-winml-winml_tensor_variable_desc) containing the description of the tensor variable.

### `Sequence`

A [WINML_SEQUENCE_VARIABLE_DESC](https://learn.microsoft.com/windows/desktop/api/winml/ns-winml-winml_sequence_variable_desc) containing the description of the sequence variable.

### `Map`

A [WINML_MAP_VARIABLE_DESC](https://learn.microsoft.com/windows/desktop/api/winml/ns-winml-winml_map_variable_desc) containing the description of the map variable.

### `Image`

A [WINML_IMAGE_VARIABLE_DESC](https://learn.microsoft.com/windows/desktop/api/winml/ns-winml-winml_image_variable_desc) containing the description of the image variable.