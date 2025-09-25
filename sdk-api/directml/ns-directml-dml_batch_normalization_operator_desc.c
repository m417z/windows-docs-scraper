struct DML_BATCH_NORMALIZATION_OPERATOR_DESC {
  const DML_TENSOR_DESC   *InputTensor;
  const DML_TENSOR_DESC   *MeanTensor;
  const DML_TENSOR_DESC   *VarianceTensor;
  const DML_TENSOR_DESC   *ScaleTensor;
  const DML_TENSOR_DESC   *BiasTensor;
  const DML_TENSOR_DESC   *OutputTensor;
  BOOL                    Spatial;
  FLOAT                   Epsilon;
  const DML_OPERATOR_DESC *FusedActivation;
};