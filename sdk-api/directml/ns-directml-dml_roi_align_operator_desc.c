struct DML_ROI_ALIGN_OPERATOR_DESC {
  const DML_TENSOR_DESC  *InputTensor;
  const DML_TENSOR_DESC  *ROITensor;
  const DML_TENSOR_DESC  *BatchIndicesTensor;
  const DML_TENSOR_DESC  *OutputTensor;
  DML_REDUCE_FUNCTION    ReductionFunction;
  DML_INTERPOLATION_MODE InterpolationMode;
  FLOAT                  SpatialScaleX;
  FLOAT                  SpatialScaleY;
  FLOAT                  OutOfBoundsInputValue;
  UINT                   MinimumSamplesPerOutput;
  UINT                   MaximumSamplesPerOutput;
};