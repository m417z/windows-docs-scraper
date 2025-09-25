struct DML_ARGMAX_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *OutputTensor;
  UINT                  AxisCount;
  const UINT            *Axes;
  DML_AXIS_DIRECTION    AxisDirection;
};