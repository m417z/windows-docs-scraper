struct DML_GEMM_OPERATOR_DESC {
  const DML_TENSOR_DESC   *ATensor;
  const DML_TENSOR_DESC   *BTensor;
  const DML_TENSOR_DESC   *CTensor;
  const DML_TENSOR_DESC   *OutputTensor;
  DML_MATRIX_TRANSFORM    TransA;
  DML_MATRIX_TRANSFORM    TransB;
  FLOAT                   Alpha;
  FLOAT                   Beta;
  const DML_OPERATOR_DESC *FusedActivation;
};