HRESULT PrjCompleteCommand(
  [in]           PRJ_NAMESPACE_VIRTUALIZATION_CONTEXT     namespaceVirtualizationContext,
  [in]           INT32                                    commandId,
  [in]           HRESULT                                  completionResult,
  [in, optional] PRJ_COMPLETE_COMMAND_EXTENDED_PARAMETERS *extendedParameters
);