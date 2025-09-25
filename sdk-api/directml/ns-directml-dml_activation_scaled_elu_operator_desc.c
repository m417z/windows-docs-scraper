struct DML_ACTIVATION_SCALED_ELU_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *OutputTensor;
  FLOAT                 Alpha;
  FLOAT                 Gamma;
};