struct DML_RANDOM_GENERATOR_OPERATOR_DESC {
  const DML_TENSOR_DESC     *InputStateTensor;
  const DML_TENSOR_DESC     *OutputTensor;
  const DML_TENSOR_DESC     *OutputStateTensor;
  DML_RANDOM_GENERATOR_TYPE Type;
};