typedef struct _MI_UtilitiesFT {
  MI_ErrorCategory()(MI_Char *errorType,MI_Uint32 error) * MapErrorToMiErrorCategory;
  MI_Result(I_Uint32 error, const MI_Char *errorType, const MI_Char *errorMessage,MI_Instance **cimError)        * )(MCimErrorFromErrorCode;
} MI_UtilitiesFT;