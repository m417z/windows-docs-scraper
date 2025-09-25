struct DML_UPSAMPLE_2D_OPERATOR_DESC {
  const DML_TENSOR_DESC  *InputTensor;
  const DML_TENSOR_DESC  *OutputTensor;
  DML_SIZE_2D            ScaleSize;
  DML_INTERPOLATION_MODE InterpolationMode;
};