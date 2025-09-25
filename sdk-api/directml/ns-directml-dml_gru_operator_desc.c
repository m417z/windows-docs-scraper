struct DML_GRU_OPERATOR_DESC {
  const DML_TENSOR_DESC           *InputTensor;
  const DML_TENSOR_DESC           *WeightTensor;
  const DML_TENSOR_DESC           *RecurrenceTensor;
  const DML_TENSOR_DESC           *BiasTensor;
  const DML_TENSOR_DESC           *HiddenInitTensor;
  const DML_TENSOR_DESC           *SequenceLengthsTensor;
  const DML_TENSOR_DESC           *OutputSequenceTensor;
  const DML_TENSOR_DESC           *OutputSingleTensor;
  UINT                            ActivationDescCount;
  const DML_OPERATOR_DESC         *ActivationDescs;
  DML_RECURRENT_NETWORK_DIRECTION Direction;
  BOOL                            LinearBeforeReset;
};