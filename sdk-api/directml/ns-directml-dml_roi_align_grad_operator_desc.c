struct DML_ROI_ALIGN_GRAD_OPERATOR_DESC {
  const DML_TENSOR_DESC  *InputTensor;
  const DML_TENSOR_DESC  *InputGradientTensor;
  const DML_TENSOR_DESC  *ROITensor;
  const DML_TENSOR_DESC  *BatchIndicesTensor;
  const DML_TENSOR_DESC  *OutputGradientTensor;
  const DML_TENSOR_DESC  *OutputROIGradientTensor;
  DML_REDUCE_FUNCTION    ReductionFunction;
  DML_INTERPOLATION_MODE InterpolationMode;
  FLOAT                  SpatialScaleX;
  FLOAT                  SpatialScaleY;
  FLOAT                  InputPixelOffset;
  FLOAT                  OutputPixelOffset;
  UINT                   MinimumSamplesPerOutput;
  UINT                   MaximumSamplesPerOutput;
  BOOL                   AlignRegionsToCorners;
};