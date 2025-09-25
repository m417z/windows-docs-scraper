struct DML_ELEMENT_WISE_CLIP_GRAD1_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *InputGradientTensor;
  const DML_TENSOR_DESC *OutputGradientTensor;
  DML_TENSOR_DATA_TYPE  MinMaxDataType;
  DML_SCALAR_UNION      Min;
  DML_SCALAR_UNION      Max;
};