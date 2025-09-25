typedef struct GET_OPERATION_CONTEXT_PARAMS {
  DWORD                         Size;
  DWORD                         Version;
  RESDLL_CONTEXT_OPERATION_TYPE Type;
  DWORD                         Priority;
} GET_OPERATION_CONTEXT_PARAMS, *PGET_OPERATION_CONTEXT_PARAMS;