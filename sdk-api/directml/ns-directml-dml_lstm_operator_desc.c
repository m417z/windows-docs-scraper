struct DML_LSTM_OPERATOR_DESC {
  const DML_TENSOR_DESC           *InputTensor;
  const DML_TENSOR_DESC           *WeightTensor;
  const DML_TENSOR_DESC           *RecurrenceTensor;
  const DML_TENSOR_DESC           *BiasTensor;
  const DML_TENSOR_DESC           *HiddenInitTensor;
  const DML_TENSOR_DESC           *CellMemInitTensor;
  const DML_TENSOR_DESC           *SequenceLengthsTensor;
  const DML_TENSOR_DESC           *PeepholeTensor;
  const DML_TENSOR_DESC           *OutputSequenceTensor;
  const DML_TENSOR_DESC           *OutputSingleTensor;
  const DML_TENSOR_DESC           *OutputCellSingleTensor;
  UINT                            ActivationDescCount;
  const DML_OPERATOR_DESC         *ActivationDescs;
  DML_RECURRENT_NETWORK_DIRECTION Direction;
  float                           ClipThreshold;
  BOOL                            UseClipThreshold;
  BOOL                            CoupleInputForget;
};