struct DML_REDUCE_OPERATOR_DESC {
  DML_REDUCE_FUNCTION   Function;
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *OutputTensor;
  UINT                  AxisCount;
  const UINT            *Axes;
};