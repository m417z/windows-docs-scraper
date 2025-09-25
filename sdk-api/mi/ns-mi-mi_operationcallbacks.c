typedef struct _MI_OperationCallbacks {
  void                                   *callbackContext;
  MI_OperationCallback_PromptUser        promptUser;
  MI_OperationCallback_WriteError        writeError;
  MI_OperationCallback_WriteMessage      writeMessage;
  MI_OperationCallback_WriteProgress     writeProgress;
  MI_OperationCallback_Instance          instanceResult;
  MI_OperationCallback_Indication        indicationResult;
  MI_OperationCallback_Class             classResult;
  MI_OperationCallback_StreamedParameter streamedParameterResult;
} MI_OperationCallbacks;