struct DML_ADAM_OPTIMIZER_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputParametersTensor;
  const DML_TENSOR_DESC *InputFirstMomentTensor;
  const DML_TENSOR_DESC *InputSecondMomentTensor;
  const DML_TENSOR_DESC *GradientTensor;
  const DML_TENSOR_DESC *TrainingStepTensor;
  const DML_TENSOR_DESC *OutputParametersTensor;
  const DML_TENSOR_DESC *OutputFirstMomentTensor;
  const DML_TENSOR_DESC *OutputSecondMomentTensor;
  FLOAT                 LearningRate;
  FLOAT                 Beta1;
  FLOAT                 Beta2;
  FLOAT                 Epsilon;
};