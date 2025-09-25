struct DML_BATCH_NORMALIZATION_TRAINING_OPERATOR_DESC {
  const DML_TENSOR_DESC   *InputTensor;
  const DML_TENSOR_DESC   *ScaleTensor;
  const DML_TENSOR_DESC   *BiasTensor;
  const DML_TENSOR_DESC   *FusedAddTensor;
  const DML_TENSOR_DESC   *OutputTensor;
  const DML_TENSOR_DESC   *OutputMeanTensor;
  const DML_TENSOR_DESC   *OutputVarianceTensor;
  FLOAT                   Epsilon;
  const DML_OPERATOR_DESC *FusedActivation;
};