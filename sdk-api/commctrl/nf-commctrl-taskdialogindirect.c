HRESULT TaskDialogIndirect(
  [in]            const TASKDIALOGCONFIG *pTaskConfig,
  [out, optional] int                    *pnButton,
  [out, optional] int                    *pnRadioButton,
  [out, optional] BOOL                   *pfVerificationFlagChecked
);