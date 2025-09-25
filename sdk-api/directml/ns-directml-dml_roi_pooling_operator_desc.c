struct DML_ROI_POOLING_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *ROITensor;
  const DML_TENSOR_DESC *OutputTensor;
  FLOAT                 SpatialScale;
  DML_SIZE_2D           PooledSize;
};