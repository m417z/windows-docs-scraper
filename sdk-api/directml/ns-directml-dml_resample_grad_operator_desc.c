struct DML_RESAMPLE_GRAD_OPERATOR_DESC {
  const DML_TENSOR_DESC  *InputGradientTensor;
  const DML_TENSOR_DESC  *OutputGradientTensor;
  DML_INTERPOLATION_MODE InterpolationMode;
  UINT                   DimensionCount;
  const FLOAT            *Scales;
  const FLOAT            *InputPixelOffsets;
  const FLOAT            *OutputPixelOffsets;
};