struct DML_ELEMENT_WISE_CLIP_GRAD_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *InputGradientTensor;
  const DML_TENSOR_DESC *OutputGradientTensor;
  FLOAT                 Min;
  FLOAT                 Max;
};