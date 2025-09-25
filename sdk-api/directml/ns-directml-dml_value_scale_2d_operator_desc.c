struct DML_VALUE_SCALE_2D_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *OutputTensor;
  FLOAT                 Scale;
  UINT                  ChannelCount;
  const FLOAT           *Bias;
};