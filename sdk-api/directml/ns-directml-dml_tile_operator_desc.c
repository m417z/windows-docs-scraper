struct DML_TILE_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *OutputTensor;
  UINT                  RepeatsCount;
  const UINT            *Repeats;
};