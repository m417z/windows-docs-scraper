struct DML_ELEMENT_WISE_ADD1_OPERATOR_DESC {
  const DML_TENSOR_DESC   *ATensor;
  const DML_TENSOR_DESC   *BTensor;
  const DML_TENSOR_DESC   *OutputTensor;
  const DML_OPERATOR_DESC *FusedActivation;
};