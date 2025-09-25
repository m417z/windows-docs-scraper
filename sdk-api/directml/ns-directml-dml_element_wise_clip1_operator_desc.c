struct DML_ELEMENT_WISE_CLIP1_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *OutputTensor;
  const DML_SCALE_BIAS  *ScaleBias;
  DML_TENSOR_DATA_TYPE  MinMaxDataType;
  DML_SCALAR_UNION      Min;
  DML_SCALAR_UNION      Max;
};