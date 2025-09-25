typedef struct _MI_OperationFT {
  MI_Result()(MI_Operation *operation) * Close;
  MI_Result()(MI_Operation *operation,MI_CancellationReason reason) * Cancel;
  MI_Result((MI_Operation *operation,MI_Session *session) * )GetSession;
  MI_Result(ration *operation, const MI_Instance **instance,MI_Boolean *moreResults,MI_Result *result, const MI_Char **errorMessage, const MI_Instance **completionDetails) * )(MI_OpeGetInstance;
  MI_Result(on *operation, const MI_Instance **instance, const MI_Char **bookmark, const MI_Char **machineID,MI_Boolean *moreResults,MI_Result *result, const MI_Char **errorMessage, const MI_Instance **completionDetails) * )(MI_OperatiGetIndication;
  MI_Result(ration *operation, const MI_Class **classResult,MI_Boolean *moreResults,MI_Result *result, const MI_Char **errorMessage, const MI_Instance **completionDetails) * )(MI_OpeGetClass;
} MI_OperationFT;