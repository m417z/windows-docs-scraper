struct DML_LOCAL_RESPONSE_NORMALIZATION_GRAD_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *InputGradientTensor;
  const DML_TENSOR_DESC *OutputGradientTensor;
  BOOL                  CrossChannel;
  UINT                  LocalSize;
  FLOAT                 Alpha;
  FLOAT                 Beta;
  FLOAT                 Bias;
};