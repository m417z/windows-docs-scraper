## Description

Performs a MaxPool function across the input tensor (according to regions of interest, or ROIs). For each output element, the coordinates of its corresponding ROI in the input are computed by the following equations.

Let `Y` be an index into the third dimension of *InputTensor* (`{ BatchSize, ChannelCount, **height**, width }`).

Let `X` be an index into the fourth dimension of *InputTensor* (`{ BatchSize, ChannelCount, height, **width** }`).

```
x1 = round(RoiX1 * SpatialScale)
x2 = round(RoiX2 * SpatialScale)
y1 = round(RoiY1 * SpatialScale)
y2 = round(RoiY2 * SpatialScale)

RegionHeight = y2 - y1 + 1
RegionWidth = x2 - x1 + 1

StartY = (OutputIndices.Y * RegionHeight) / PooledSize.Height + y1
StartX = (OutputIndices.X * RegionWidth) / PooledSize.Width + x1

EndY = ((OutputIndices.Y + 1) * RegionHeight + PooledSize.Height - 1) / PooledSize.Height + y1
EndX = ((OutputIndices.X + 1) * RegionWidth + PooledSize.Width - 1) / PooledSize.Width + x1
```

If the computed coordinates are out of bounds, then they are clamped to the input boundaries.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the input data with dimensions `{ BatchCount, ChannelCount, InputHeight, InputWidth }`.

### `ROITensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the regions of interest (ROI) data. The expected dimensions of `ROITensor` are `{ 1, 1, NumROIs, 5 }` and the data for each ROI is `[BatchID, x1, y1, x2, y2]`. x1, y1, x2, y2 are the inclusive coordinates of the corners of each ROI and x2 >= x1, y2 >= y1.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the output data. The expected dimensions of *OutputTensor* are `{ NumROIs, InputChannelCount, PooledSize.Height, PooledSize.Width }`.

### `SpatialScale`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Multiplicative spatial scale factor used to translate the ROI coordinates from their input scale to the scale used when pooling.

### `PooledSize`

Type: [**DML_SIZE_2D**](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_size_2d)

The ROI pool output size (height, width), which must match the last 2 dimensions of *OutputTensor*.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_1_0`.

## Tensor constraints
*InputTensor*, *OutputTensor*, and *ROITensor* must have the same *DataType*.

## Tensor support
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16 |
| ROITensor | Input | 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16 |