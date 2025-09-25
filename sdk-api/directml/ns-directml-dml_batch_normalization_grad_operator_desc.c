struct DML_BATCH_NORMALIZATION_GRAD_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *InputGradientTensor;
  const DML_TENSOR_DESC *MeanTensor;
  const DML_TENSOR_DESC *VarianceTensor;
  const DML_TENSOR_DESC *ScaleTensor;
  const DML_TENSOR_DESC *OutputGradientTensor;
  const DML_TENSOR_DESC *OutputScaleGradientTensor;
  const DML_TENSOR_DESC *OutputBiasGradientTensor;
  FLOAT                 Epsilon;
};