struct DML_LOCAL_RESPONSE_NORMALIZATION_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *OutputTensor;
  BOOL                  CrossChannel;
  UINT                  LocalSize;
  FLOAT                 Alpha;
  FLOAT                 Beta;
  FLOAT                 Bias;
};