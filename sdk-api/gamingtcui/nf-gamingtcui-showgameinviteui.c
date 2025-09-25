HRESULT ShowGameInviteUI(
  [in]           HSTRING                 serviceConfigurationId,
  [in]           HSTRING                 sessionTemplateName,
  [in]           HSTRING                 sessionId,
  [in]           HSTRING                 invitationDisplayText,
  [in]           GameUICompletionRoutine completionRoutine,
  [in, optional] void                    *context
);