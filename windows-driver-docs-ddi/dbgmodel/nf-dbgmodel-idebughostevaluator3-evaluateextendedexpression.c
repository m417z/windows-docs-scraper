HRESULT EvaluateExtendedExpression(
  IDebugHostContext           *context,
  PCWSTR                      expression,
  IModelObject                *bindingContext,
  _COM_Errorptr_ IModelObject **result,
  IKeyStore                   **metadata
);