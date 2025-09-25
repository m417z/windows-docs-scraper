struct DML_ELEMENT_WISE_THRESHOLD_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *OutputTensor;
  const DML_SCALE_BIAS  *ScaleBias;
  FLOAT                 Min;
};