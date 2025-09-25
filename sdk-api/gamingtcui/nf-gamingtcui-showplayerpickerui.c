HRESULT ShowPlayerPickerUI(
  [in]           HSTRING                         promptDisplayText,
  [in]           const HSTRING                   *xuids,
  [in]           size_t                          xuidsCount,
  [in, optional] const HSTRING                   *preSelectedXuids,
  [in]           size_t                          preSelectedXuidsCount,
  [in]           size_t                          minSelectionCount,
  [in]           size_t                          maxSelectionCount,
  [in]           PlayerPickerUICompletionRoutine completionRoutine,
  [in, optional] void                            *context
);